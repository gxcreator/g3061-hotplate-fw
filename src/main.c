#include "STC8XXXX.H"
#include "oled.h"
#include "bmp.h"
#include "timer0.h"
#include "ADC.h"
#include "EEPROM.h"
#include <math.h>

#define vol_channel 0
#define tem_channel 1
#define vcc_channel 15

void prekey(void);//Calculate key press duration
void relkey_page0(void);//Handle key input
void relkey_page1(void);//Handle key input
void page0(void);//Page 0
void page1(void);//Page 1
void mode0(void);//Mode 0
void mode1(void);//Mode 1
void pid_p(void);

unsigned int presstime=500;//Long-press duration in ms
unsigned int tartem=300;//Target temperature
unsigned int keyi0=0;//Key 0 press duration
unsigned int keyi1=0;//Key 1 press duration
unsigned int keyi=0;//Both-key press duration
unsigned int maxtartem=350;//Configurable maximum target temperature
unsigned int mintartem=1;//Configurable minimum target temperature
unsigned int i;//Loop variable
unsigned int time;//Timer counter
unsigned int kp=10,ki=20,kd=30;

int pwm=0;
int pagenum=0;
int err=0,lasterr=0;
int integral=0;
int derivative=0;

double showpwm=0;
double showpwm_opp=0;
double powvol;//Supply voltage total
double powvol_average[30]={0};//Supply voltage samples
double realtem=200;//Actual temperature
double realtem_average[30]={0};//Actual temperature samples
double p1=    0.00000016;//Temperature curve coefficient 1
double p2=   -0.00089441;//Temperature curve coefficient 2
double p3=    1.91367865;//Temperature curve coefficient 3
double p4=-1537.97459730;//Temperature curve coefficient 4
double vcc=0;

unsigned char count=0;//Supply voltage sample index
unsigned char page = 0;//Page selection
unsigned char modesel=0;//Mode selection
unsigned char keyx0,keyx1;
unsigned char page1_iconnum=4;//Page 1 option count
unsigned char page1_PIDnum=4;//PID submenu option count
unsigned char page1_TEMnum=3;//Temperature submenu option count
unsigned char page1_MODEnum=3;//Mode submenu option count
unsigned char eeptart[2]={0};
unsigned char eepkp[2]={0};
unsigned char eepki[2]={0};
unsigned char eepkd[2]={0};
unsigned char eepmaxt[2]={0};
unsigned char eepmint[2]={0};
unsigned char mapline[101]={0};//Temperature history
unsigned char numofsam=30;//Sample count

__sbit __at(0xB4) heat;//Heater (P3^4)
__sbit __at(0xB2) key0;//Key 0 (P3^2)
__sbit __at(0xB3) key1;//Key 1 (P3^3)

bit swclose=1;//Key sleep switch
bit keyj0;//Key 0 flag
bit keyj1;//Key 1 flag
bit keyj;//Both-key flag 1
bit keyp;//Both-key flag 2
bit eeprom_tartem=1;//Target temperature flag
bit eeprom_pid=1;//PID parameter flag
bit eeprom_limtem=1;//Temperature limit flag
bit eeprom_mode=1;
bit pageflag;//Page switch flag
bit blinker;//Refresh flag
bit pidflag;

void init(void)
{
	EEPROM_read_n(0x0000,&eeptart[0],2);
	EEPROM_read_n(0x0200,&eepkp[0],2);
	EEPROM_read_n(0x0204,&eepki[0],2);
	EEPROM_read_n(0x0208,&eepkd[0],2);
	EEPROM_read_n(0x0400,&eepmaxt[0],2);
	EEPROM_read_n(0x0404,&eepmint[0],2);
	EEPROM_read_n(0x0600,&modesel,1);
	tartem=(256*eeptart[1])+eeptart[0];
	kp=(256*(eepkp[1]))+(eepkp[0]);
	ki=(256*(eepki[1]))+(eepki[0]);
	kd=(256*(eepkd[1]))+(eepkd[0]);
	maxtartem=(256*(eepmaxt[1]))+(eepmaxt[0]);
	mintartem=(256*(eepmint[1]))+(eepmint[0]);
	if(maxtartem>350){maxtartem=350;}
	else if(maxtartem<200){maxtartem=200;}
	if(mintartem>200){mintartem=0;}
	else if(mintartem<0){mintartem=0;}
	if(tartem>maxtartem){tartem=maxtartem;}
	else if(tartem<mintartem){tartem=mintartem;}
	if(kp>1000){kp=500;}
	else if(kp<0){kp=0;}
	if(ki>1000){ki=500;}
	else if(ki<0){ki=0;}
	if(kd>1000){kd=500;}
	else if(kd<0){kd=0;}
	if(modesel>page1_MODEnum-2 || page1_MODEnum<0)
	{
		modesel=0;
	}
	P1M0 = 0x00;//00000011
	P1M1 = 0xff;//11111100
	P3M0 = 0xff;//11111111
	P3M1 = 0x0c;//00001100
	heat=0;
	swclose=0;
	powvol=0;
	adc_init();//Initialize ADC
	OLED_Init();//Initialize display
	Timer0Init();//Initialize Timer 0
	EA=1;
	showpwm_opp=100-showpwm;
	for(i=0;i<numofsam;i++)
	{
		powvol_average[i]=get_adc(vol_channel);//Read supply ADC value
		realtem_average[i]=transform(get_adc(tem_channel),p1,p2,p3,p4);
	}
	for(i=0;i<numofsam;i++)
	{
		vcc+=(1.19*4096)/get_adc(vcc_channel);//Calculate supply voltage
	}
	vcc/=numofsam;
	for(i=0;i<numofsam;i++)
	{
		powvol+=19*vcc*(powvol_average[i]/4096);
		realtem+=realtem_average[i];
	}
	powvol/=numofsam;
	realtem/=numofsam;
}

void main(void)
{	
	init();
	while(1)
	{
		if(page==0){page0();}//Page 0
		if(page==1){page1();}//Page 1
	}
}

void timer0(void) __interrupt(1)
{
	time++;
	if(time==1000){time=0;blinker=0;if(swclose){pidflag=1;}}
	if(pwm>=time && swclose){heat=1;}
	else/* if(pwm<time || !swclose)*/{heat=0;}
	prekey();//Detect and time key presses
}

void prekey(void)
{
	if(!key0 && key1 && !keyj)
		{keyi0++;keyj0=1;}
	if(!key1 && key0 && !keyj)
		{keyi1++;keyj1=1;}
	if(!key0 && !key1 && keyi0<presstime && keyi1<presstime) 
		{keyi0=keyi1=keyj0=keyj1=0;keyi++;keyj=1;}
}

void relkey_page0(void)
{
	if(!key0 && keyi0>=presstime)//Hold key 0
	{
		if(tartem<maxtartem)
		{
			tartem++;
			eeprom_tartem=0;
		}
	}
	else if(key0 && keyj0)//Tap key 0
	{
		if(tartem<maxtartem)
		{
			tartem++;keyi0=0;keyj0=0;eeprom_tartem=0;
		}
	}
	if(!key1 && keyi1>=presstime)//Hold key 1
	{
		if(tartem>mintartem)
		{
			tartem--;
			eeprom_tartem=0;
		}
	}
	else if(key1 && keyj1 && !pageflag)//Tap key 1
	{
		if(tartem>mintartem)
		{
			tartem--;keyi1=0;keyj1=0;eeprom_tartem=0;
		}
	}
	if(!key0 && !key1 && keyi>=presstime && keyj && keyp)//Hold both keys
	{
		page=!page;
		swclose=0;
		heat=0;
		keyj=0;
		keyi=0;
		keyp=0;
		pagenum=1;
	}
	else if(key1 && key0 && keyj && keyi<presstime && keyp)//Tap both keys
	{
		swclose=!swclose;
		pagenum=1;
		heat=swclose;
		integral=0;
		pwm=0;
		keyj=0;
		keyi=0;
	}
	if(key1 && key0)//Release keys
	{
		keyi=0;
		keyj=0;
		keyp=1;
		keyi0=0;
		keyi1=0;
		keyj0=0;
		keyj1=0;
		if(eeprom_tartem==0)
		{
			eeptart[0]=(tartem%256);
			eeptart[1]=(tartem/256);
			EEPROM_SectorErase(0x0000);
			EEPROM_write_n(0x0000,&eeptart[0],2);
			eeptart[0]=eeptart[1]=0;
			eeprom_tartem=1;
		}
	}
	if(pageflag)
	{
		pageflag=0;
	}
}

void page0(void)
{
	OLED_display_clear();
	count++;
	count%=numofsam;
	powvol_average[count]=get_adc(vol_channel);//Read supply ADC value
	realtem_average[count]=transform(get_adc(tem_channel),p1,p2,p3,p4);
	realtem=0;
	powvol=0;
	vcc=0;
	for(i=0;i<numofsam;i++)
	{
		vcc+=(1.19*4096)/get_adc(vcc_channel);//Calculate reference voltage
	}
	vcc/=numofsam;
	for(i=0;i<numofsam;i++)
	{
		powvol+=20*vcc*(powvol_average[i]/4096);//Calculate supply voltage
		realtem+=realtem_average[i];//Calculate actual temperature
	}
	powvol/=numofsam;
	realtem/=numofsam;
	//realtem=pidflag;
	if(realtem>400 || realtem<0)
	{
		realtem=0;
	}
	if(pidflag){pid_p();pidflag=0;}
	if(modesel==0){mode0();}//Display mode 0
	else if(modesel==1){mode1();}//Display mode 1
	OLED_display();
	relkey_page0();
}

void relkey_page1(void)
{
	if(!key0 && keyi0>=presstime)//Hold key 0
	{
		if(pagenum>=100 && pagenum<110)
		{
			switch(pagenum%10)
			{
				case 0: if(kp<500) {kp++;eeprom_pid=0;} break;
				case 1: if(ki<500) {ki++;eeprom_pid=0;} break;
				case 2: if(kd<500) {kd++;eeprom_pid=0;} break;
			}
		}
		else if(pagenum>=200 && pagenum<210)
		{
			switch(pagenum%10)
			{
				case 0: if(maxtartem<350) {maxtartem++;eeprom_limtem=0;} break;
				case 1: if(mintartem<200) {mintartem++;eeprom_limtem=0;} break;
			}
		}
	}
	else if(key0 && keyj0)//Tap key 0
	{
		if(pagenum<100)
		{
			pagenum++;
		}
		else if(pagenum>=100 && pagenum<110)
		{
			switch(pagenum%10)
			{
				case 0: if(kp<500) {kp++;eeprom_pid=0;} break;
				case 1: if(ki<500) {ki++;eeprom_pid=0;} break;
				case 2: if(kd<500) {kd++;eeprom_pid=0;} break;
			}
		}
		else if(pagenum>=200 && pagenum<210)
		{
			switch(pagenum%10)
			{
				case 0: if(maxtartem<350) {maxtartem++;eeprom_limtem=0;} break;
				case 1: if(mintartem<200) {mintartem++;eeprom_limtem=0;} break;
			}
		}
		if(pagenum==page1_iconnum+1)
		{
			pagenum=1;
		}
		else if(pagenum==10+page1_PIDnum)
		{
			pagenum-=page1_PIDnum;
		}
		else if(pagenum==20+page1_TEMnum)
		{
			pagenum-=page1_TEMnum;
		}
		else if(pagenum==30+page1_MODEnum)
		{
			pagenum-=page1_TEMnum;
		}
		keyi0=0;
		keyj0=0;
	}
	if(!key1 && keyi1>=presstime)//Hold key 1
	{
		if(pagenum>=100 && pagenum<110)
		{
			switch(pagenum%10)
			{
				case 0: if(kp>0){kp--;eeprom_pid=0;} break;
				case 1: if(ki>0){ki--;eeprom_pid=0;} break;
				case 2: if(kd>0){kd--;eeprom_pid=0;} break;
			}
		}
		else if(pagenum>=200 && pagenum<210)
		{
			switch(pagenum%10)
			{
				case 0: if(maxtartem>200) {maxtartem--;eeprom_limtem=0;} break;
				case 1: if(mintartem>0)   {mintartem--;eeprom_limtem=0;} break;
			}
		}
	}
	else if(key1 && keyj1)//Tap key 1
	{
		if(pagenum<100)
		{
			pagenum--;
		}
		else if(pagenum>=100 && pagenum<110)
		{
			switch(pagenum%10)
			{
				case 0: if(kp>0){kp--;eeprom_pid=0;} break;
				case 1: if(ki>0){ki--;eeprom_pid=0;} break;
				case 2: if(kd>0){kd--;eeprom_pid=0;} break;
			}
		}
		else if(pagenum>=200 && pagenum<210)
		{
			switch(pagenum%10)
			{
				case 0: if(maxtartem>200) {maxtartem--;eeprom_limtem=0;} break;
				case 1: if(mintartem>0)   {mintartem--;eeprom_limtem=0;} break;
			}
		}
		if(pagenum==0)
		{
			pagenum=page1_iconnum;
		}
		else if(pagenum==9)
		{
			pagenum+=page1_PIDnum;
		}
		else if(pagenum==19)
		{
			pagenum+=page1_TEMnum;
		}
		else if(pagenum==29)
		{		
			pagenum+=page1_TEMnum;
		}
		keyi1=0;
		keyj1=0;
	}
	if(!key0 && !key1 && keyi>=presstime && keyj && keyp)//Hold both keys
	{
		if(pagenum<10)
		{
			if(tartem<mintartem)
			{
				tartem=mintartem;
			}
			else if(tartem>maxtartem)
			{
				tartem=maxtartem;
			}
			page=!page;
			pageflag=0;
			pagenum=0;
			swclose=0;
			heat=0;
			keyj=0;
			keyi=0;
			keyp=0;
		}
		else
		{
			pagenum/=10;
			keyj=0;
			keyi=0;
			keyp=0;
		}
	}
	else if(key1 && key0 && keyj && keyi<presstime && keyp)//Tap both keys
	{
		if(pagenum==page1_iconnum)
		{
			if(tartem<mintartem)
			{
				tartem=mintartem;
			}
			else if(tartem>maxtartem)
			{
				tartem=maxtartem;
			}
			page=!page;
			pageflag=0;
			pagenum=0;
			swclose=0;
			heat=0;
			keyj=0;
			keyi=0;
			keyp=0;
		}
		else if(pagenum>=100)
		{
			pagenum=pagenum/10+pagenum%10;
		}
		else if(pagenum==13 || pagenum==22)
		{
			pagenum/=10;
		}
		else if(pagenum<10)
		{
			pagenum=pagenum*10;
		}
		else if(pagenum>=30 && pagenum<40)// && pagenum%10!=page1_MODEnum-1)
		{
			if(pagenum%10!=page1_MODEnum-1)
			{
				modesel=pagenum%10;
				eeprom_mode=0;
			}
			else
			{
				pagenum/=10;
			}
		}
		else
		{
			pagenum=(pagenum/10)*100+pagenum%10;
		}
		keyj=0;
		keyi=0;
	}
	if(key1 && key0)//Release keys
	{
		keyi=0;
		keyj=0;
		keyp=1;
		if(eeprom_pid==0)
		{
			eepkp[0]=(kp%256);
			eepkp[1]=(kp/256);
			eepki[0]=(ki%256);
			eepki[1]=(ki/256);
			eepkd[0]=(kd%256);
			eepkd[1]=(kd/256);
			EEPROM_SectorErase(0x0200);
			EEPROM_write_n(0x0200,&eepkp[0],2);
			EEPROM_write_n(0x0204,&eepki[0],2);
			EEPROM_write_n(0x0208,&eepkd[0],2);
			eeprom_pid=1;
		}
		if(eeprom_limtem==0)
		{
			eepmaxt[0]=maxtartem%256;
			eepmaxt[1]=maxtartem/256;
			eepmint[0]=mintartem%256;
			eepmint[1]=mintartem/256;
			EEPROM_SectorErase(0x0400);
			EEPROM_write_n(0x0400,&eepmaxt[0],2);
			EEPROM_write_n(0x0404,&eepmint[0],2);
			eeprom_limtem=1;
		}
		if(eeprom_mode==0)
		{
			EEPROM_SectorErase(0x0600);
			EEPROM_write_n(0x0600,&modesel,1);
			eeprom_mode=1;
		}
	}
	if(!pageflag)
	{
		pageflag=1;
	}
}

void page1()
{
	OLED_display_clear();
	relkey_page1();
	//Draw_realnum(pagenum);
	if(pagenum<10)//Top-level page
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrw);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlw);
		OLED_DrawBMP_2(48,0,32,64,page1_icon[pagenum-1]);
	}
	else if(pagenum>=10 && pagenum < 20)//PID submenu
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrw);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlw);
		OLED_DrawBMP_2(52,0,54,32,kpid[pagenum%10]);
		if(pagenum%10<page1_PIDnum-1)
		{
			OLED_DrawBMP_2(22,0,28,56,PIDopp[pagenum%10]);
		}
		else if(pagenum%10==page1_PIDnum-1)
		{
			OLED_DrawBMP_2(22,0,28,56,PID[page1_PIDnum-1]);
		}
		for(i=0;i<page1_PIDnum;i++)
		{
			if(i!=pagenum%10)
			{
				OLED_DrawBMP_2((72/(page1_PIDnum-1))*i+22,7,12,8,tab);
			}
			else
			{
				OLED_DrawBMP_2((72/(page1_PIDnum-1))*i+22,7,12,8,tab2);
			}
		}
	}
	else if(pagenum>=20 && pagenum < 30)//Temperature submenu
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrw);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlw);
		OLED_DrawBMP_2(52,0,54,32,templimit[pagenum%10]);
		if(pagenum%10<page1_TEMnum-1)
		{
			OLED_DrawBMP_2(22,0,28,56,TEMPopp[pagenum%10]);
		}
		else if(pagenum%10==page1_TEMnum-1)
		{
			OLED_DrawBMP_2(22,0,28,56,TEMP[pagenum%10]);
		}
		for(i=0;i<page1_TEMnum;i++)
		{
			if(i!=pagenum%10)
			{
				OLED_DrawBMP_2((72/(page1_TEMnum-1))*i+22,7,12,8,tab);
			}
			else
			{
				OLED_DrawBMP_2((72/(page1_TEMnum-1))*i+22,7,12,8,tab2);
			}
		}
	}
	else if(pagenum>=30 && pagenum<=40)//Mode submenu
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrw);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlw);
		OLED_DrawBMP_2(52,0,54,32,modeexp[pagenum%10]);
		if(pagenum%10==page1_MODEnum-1)
		{
			OLED_DrawBMP_2(22,0,28,56,mode[pagenum%10]);
		}
		else if(modesel==pagenum%10)
		{
			OLED_DrawBMP_2(22,0,28,56,mode[pagenum%10]);
		}
		else
		{
			OLED_DrawBMP_2(22,0,28,56,modopp[pagenum%10]);
		}
		for(i=0;i<page1_MODEnum;i++)
		{
			if(i!=pagenum%10)
			{
				OLED_DrawBMP_2((72/(page1_MODEnum-1))*i+22,7,12,8,tab);
			}
			else
			{
				OLED_DrawBMP_2((72/(page1_MODEnum-1))*i+22,7,12,8,tab2);
			}
		}
	}
	else if(pagenum >=100 && pagenum<110)//PID settings page
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrb);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlb);
		OLED_DrawBMP_2(22,0,28,56,PID[pagenum%10]);
		OLED_DrawBMP_2(52,0,54,32,kpid[pagenum%10]);
		//Draw_midnum(53,4,pagenum,4);
		switch(pagenum%10)
		{
			case 0: Draw_midnum(53,4,kp,4); break;
			case 1: Draw_midnum(53,4,ki,4); break;
			case 2: Draw_midnum(53,4,kd,4); break;
		}
		for(i=0;i<page1_PIDnum;i++)
		{
			if(i!=pagenum%10)
			{
				OLED_DrawBMP_2((72/(page1_PIDnum-1))*i+22,7,12,8,tab);
			}
			else
			{
				OLED_DrawBMP_2((72/(page1_PIDnum-1))*i+22,7,12,8,tab2);
			}
		}
	}
	else if(pagenum>=200 && pagenum<210)//Temperature settings page
	{
		OLED_DrawBMP_2(109,1,17,48,page1_arrrb);
		OLED_DrawBMP_2(2,1,17,48,page1_arrlb);
		OLED_DrawBMP_2(22,0,28,56,TEMP[pagenum%10]);
		OLED_DrawBMP_2(52,0,54,32,templimit[pagenum%10]);
		switch(pagenum%10)
		{
			case 0: Draw_midnum(53,4,maxtartem,3); break;
			case 1: Draw_midnum(53,4,mintartem,3); break;
		}
		for(i=0;i<page1_TEMnum;i++)
		{
			if(i!=pagenum%10)
			{
				OLED_DrawBMP_2((72/(page1_TEMnum-1))*i+22,7,12,8,tab);
			}
			else
			{
				OLED_DrawBMP_2((72/(page1_TEMnum-1))*i+22,7,12,8,tab2);
			}
		}
	}
	OLED_display();
}

void mode0()
{
	Draw_realnum(0,0,realtem);//Display measured temperature
	Draw_tarnum(48,3,tartem,1);//Draw target temperature to buffer
	Draw_voltage(48,0,powvol);//Draw supply voltage to buffer
	if(realtem>=mintartem && realtem <= maxtartem)
	{
		Draw_Loading(8,6,0,((realtem-mintartem)*100)/(maxtartem-mintartem));//Draw left progress bar
	}
	else if(realtem>maxtartem)
	{
		Draw_Loading(8,6,0,100);
	}
	else
	{
		Draw_Loading(8,6,0,0);//Draw left progress bar
	}
	if(showpwm!=pwm && swclose){showpwm_opp=(pwm/10-showpwm);showpwm_opp=showpwm_opp*0.8;showpwm=pwm/10-showpwm_opp;}
	else if(!swclose){showpwm*=0.8;}
	Draw_Loading(65,6,1,showpwm+1);//Draw right progress bar
	Draw_Sign(11,48,((tartem-(mintartem))*100)/((maxtartem)-(mintartem)),tartem,realtem);//Draw left progress bar marker
	if(swclose==0){OLED_DrawBMP_2(84, 0, 42, 48, state[2]);}
	else if(err>5){OLED_DrawBMP_2(84, 0, 42, 48, state[1]);}
	else{OLED_DrawBMP_2(84, 0, 42, 48, state[0]);}
}

void mode1()
{
	Draw_tarnum(0,0,realtem,0);//Draw target temperature to buffer
	Draw_tarnum(0,3,tartem,0);//Draw target temperature to buffer
	if(swclose==0){OLED_DrawBMP_2(4,6,16,16,switch_clo);}
	else{OLED_DrawBMP_2(4,6,16,16,switch_ope);}
	//OLED_DrawLine(26,60,128,60,1);
	OLED_DrawBMP_2(25,0,103,64,xy);//Draw axes
	for(i=26;i<128;i++)
	{
		if((i+1)%4==0)
		{
			OLED_DrawPixel(i,60-((tartem*60)/(maxtartem-mintartem)),1);
		}
	}
	if(!blinker)
	{
		for(i=0;i<100;i++)
		{
			mapline[i]=mapline[i+1];
		}
		blinker=1;
		mapline[100]=realtem;
	}
	for(i=0;i<101;i++)
	{
		OLED_DrawPixel(27+i,60-((mapline[i]*60)/maxtartem),1);
	}
}

void pid_p(void)
{
	err=tartem-realtem;//Error
	if(err<10 && err>-10){integral=integral+err;}
	derivative = err-lasterr;//Derivative
	if(integral>500){integral=500;}
	if(integral<-500){integral=-500;}//Limit integral growth
	if(kp*err>1000){err=1000/kp;}
	if(ki*integral>1000){integral=1000/ki;}
	if(kd*derivative>1000){integral=1000/kd;}	
	pwm=kp*err+ki*integral+kd*derivative;
	if(pwm>1000){pwm=1000;}
	if(pwm<0){pwm=0;}//Prevent overflow
	lasterr=err;
}
