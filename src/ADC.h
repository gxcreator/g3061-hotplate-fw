#ifndef __ADC_H__
#define __ADC_H__

void delayus (unsigned int nn);
void adc_init();
unsigned int get_adc(unsigned int p);
unsigned int transform(unsigned int adc,double p1,double p2,double p3,double p4);

#endif