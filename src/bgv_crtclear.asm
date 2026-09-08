; Preserve factory BGV in IDATA EF (high) and F0 (low) until main copies it.
; The target has 256 bytes of IRAM. Leave all other startup stages intact.

	.area GSINIT4 (CODE)

__mcs51_genRAMCLEAR::
	clr a
	mov r0,#(l_IRAM-1)
00001$:
	cjne r0,#0xf0,00002$
	mov r0,#0xee
00002$:
	mov @r0,a
	djnz r0,00001$
; Fall through to the remaining runtime initialization, not RET.
