;--------------------------------------------------------------------------
	CONFIG	PLLEN  = ON			; Oscillator multiplied by 4
	CONFIG  CPUDIV = NOCLKDIV	; CPU_clk = PLL
	CONFIG 	USBDIV = OFF		; USB Clock comes directly from the OSC1/OSC2 oscillator
	CONFIG 	FOSC   = HS			; HS oscillator
	CONFIG 	PCLKEN = ON         ; Primary clock enabled
	CONFIG  IESO   = OFF		; Int/Ext switchover mode
	CONFIG  PWRTEN = ON			; PowerUp Timer
	CONFIG  BOREN  = ON			; Brown Out
	CONFIG  BORV   = 27         ; Brown Out Voltage: VBOR set to 2.7 V nominal
	CONFIG  WDTEN  = OFF		; WatchDog Timer
	CONFIG  MCLRE  = ON			; MCLR pin enabled, RE3 input pin disabled
	CONFIG  STVREN = ON			; Stack Overflow Reset
	CONFIG  LVP    = OFF		; Low Voltage Programming

;   Extended Instruction Set Enable bit:
;���L�̋L�q�ɂ͓��ɒ��ӂ��邱�ƁB
	CONFIG  XINST = OFF			; Ext CPU Instruction Set
;
;;Bootloader�� XINST��ON/OFF�Ɋւ�炸���삷�邪�Abootloader���������v���O������
;;XINST ��On �� Off���œ��삵���肵�Ȃ������肷��B�i�������ɂ��j
;;���ɁAsdcc�ō쐬�����v���O�����͑S�� XINST=OFF �łȂ��ƈӖ��s���̓��������B
;;�g������(addfsr,subfsr��)��AFSR2���΃A�h���X( AccessBank��� )���g�p����
;;�v���O�����ł͕K�� XINST=ON�ŏĂ��Ȃ���΂Ȃ�Ȃ��B

;   Code Protection bit:
	CONFIG  CP0 = OFF			; Code Protect
	CONFIG  CP1 = OFF
;   Boot Block Size Select Bit:
;     BBSIZ = OFF          1kW boot block size
;     BBSIZ = ON           2kW boot block size
;   Boot Block Code Protection bit:
	CONFIG  CPB = OFF  			; Boot Sect Code Protect
	CONFIG  CPD = OFF  			; EEPROM Data Protect
;   Write Protection bit:
	CONFIG  WRT0 = OFF 			; Table Write Protect
	CONFIG  WRT1 = OFF
;	CONFIG  WRTB = ON  			; Boot Table Write Protect
	CONFIG  WRTB = OFF  			; Boot Table Write Protect
	CONFIG  WRTC = OFF 			; CONFIG Write Protect
	CONFIG  WRTD = OFF 			; EEPROM Write Protect
;   Table Read Protection bit:
	CONFIG  EBTR0 = OFF			; Ext Table Read Protect
	CONFIG  EBTR1 = OFF
	CONFIG  EBTRB = OFF			; Boot Table Read Protect
;[EOF]