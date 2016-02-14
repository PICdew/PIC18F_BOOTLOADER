#
##########################################
#  GNU Makefile for PIC MCC18 C Compiler
##########################################
#  �g����:
#  �EWinAVR �ł��Ȃ��݂� GNU Make���g���ăr���h���܂�.
#    (make.exe : �ʏ�� C:/WinAVR/utils/bin/ �ɂ���܂�.)
#
#  �Emcc18�� MPLAB-C18-Std-Eval-v3_32.zip ���g�p���܂���.
#    (�C���X�g�[����: �ʏ�� C:/mcc18/bin/mcc18.exe )
#
#  �E�r���h����Linux�̏ꍇ�� GNU Make�ɂ��r���h�o���܂�.
#    Linux�̏ꍇ��wine�����炩���߃C���X�g�[�����Ă�������.
#    $ wine ./srec2bin.exe �ȂǂƂ���āA ~/.wine/�f�B���N�g�����쐬����
#    ���ƂŁA~/.wine/drive_c/mcc18/ �̂悤�Ƀf�B���N�g�����@���āA������
#    Windows���� C:\mcc18 �����̂܂܃R�s�[���Ďg���܂�.
#
#  �E�p�X�̒ʂ���:
#    PATH %PATH%;C:\mcc18\bin;C:\mcc18\mpasm;C:\WinAVR\utils\bin;
#                ~~~~~~~~~    ~~~~~~~~ ��������mcc18�̃C���X�g�[����ɉ����ēǂݑւ��Ă�������.
#    Linux�̏ꍇ�̓p�X��ʂ��K�v�͂���܂���.
#
#  �EMPLAB�̂ق��͓��ɃC���X�g�[������K�v�͂���܂���.
#    (mcc18��mpasm���܂܂�Ă��܂�)
#
#  �EWindows�ŁAmcc18�̃C���X�g�[���悪�قȂ�ꍇ�́A���L
#    MCC18 = C:/MCC18
#   �����������邩�A���ϐ� �uMCC18�v �ɃC���X�g�[������L�q���Ă�������.
#

#######################################################
# �f�o�C�X���:
DEVICE=18F14K50
#DEVICE=18F2550
#DEVICE=18F4550


#######################################################
# ���������: Linux / Windows
#
 ifdef ComSpec
EXEC_PREFIX=
EXE_PREFIX=
 else

 ifdef COMSPEC
EXEC_PREFIX=
EXE_PREFIX=
 else
EXEC_PREFIX=wine ~/.wine/drive_c/mcc18/bin/
EXE_PREFIX=wine ./
 endif

 endif

AS = $(EXEC_PREFIX)MPASMWIN.exe
CC = $(EXEC_PREFIX)mcc18.exe
LD = $(EXEC_PREFIX)mplink.exe
AR = $(EXEC_PREFIX)mplib.exe
RM = rm


TARGET = picmon-$(DEVICE)


##########################################
#  Set mcc18 INSTALL PATH
#
ifndef MCC18
MCC18 = C:/MCC18
endif

##########################################
#  Object List
#
OBJS = \
	main.o		\
	monit.o		\
	picwrt.o	\
	timer2.o	\
	print.o		\
	usercmd.o	\
	usbdsc.o	\
	usb/hid.o	\
	usb/usb9.o	\
	usb/usbctrltrf.o	\
	usb/usbdrv.o		\
	usb/usbmmap.o		\

#	ps2keyb.o	\
#	keybtest.o	\


##########################################
#  Compile Option
#
# EEPROM�ɃV���A���ԍ���ݒ肷��ꍇ
CFLAGS = -DRAM_SERIAL -p=$(DEVICE) /i$(MCC18)/h /iusb

# ROM�ɃV���A���ԍ��𖄂ߍ��ޏꍇ
#CFLAGS = -p=$(DEVICE) /i$(MCC18)/h /iusb
#CFLAGS = -DRAM_SERIAL -p=$(DEVICE) /i$(MCC18)/h /iusb -w=1
#CFLAGS = -DRAM_SERIAL -p=$(DEVICE) /i$(MCC18)/h /iusb -w=2

# ��: ����  �x�����x����1�ɉ����Ă��܂����A���ɖ߂��ق����]�܂���.


##########################################
#  Rules
#
%.o : %.c
	$(CC) $(CFLAGS) $< -fo=$@


##########################################
#  Build Target
#
$(TARGET).cof : $(OBJS)
	$(LD) -p$(DEVICE) /l$(MCC18)/lib /k$(MCC18)/lkr rm$(DEVICE).lkr $(OBJS) \
	/u_CRUNTIME /z__MPLAB_BUILD=1 /i /m$(TARGET).map /o$(TARGET).cof



# v3.34�܂ł͂�����.
#	$(LD) 			  /l$(MCC18)/lib /k$(MCC18)/lkr rm$(DEVICE).lkr $(OBJS) \
#	/u_CRUNTIME /z__MPLAB_BUILD=1 /i /m$(TARGET).map /o$(TARGET).cof

##########################################
#  Dependency
#
monit.o : monit.c usi_pic18.h usi_pic18s.h


##########################################
#  Phony Target
#
all:
	$(MAKE) clean
	$(MAKE) DEVICE=18F14K50
	$(MAKE) clean
	$(MAKE) DEVICE=18F2550

clean : 
	-$(RM) $(OBJS) $(TARGET).cof $(TARGET).map
	-$(RM) *.cof *.map *.dmp *.cod *.lst *.err *.src

##########################################
#  HEX�t�@�C����HEX�_���v�ɕϊ�����.
dumphex : 
	$(EXE_PREFIX)srec2bin.exe $(TARGET).hex  nul > $(TARGET).dmp

##########################################
#  LST�t�@�C���������������₷������.
dumplst : 
	$(EXE_PREFIX)mplistconv.exe -m80 $(TARGET).lst $(TARGET).src

#[EOF]