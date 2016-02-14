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
#DEVICE	= 18F2550
DEVICE	= 18F14K50

#######################################################
#	bootload �̏풓�Ԓn
#   �{�Ԑݒ�=0000   
#   ����loader���g�p���ăf�o�b�O=0800

VECTOR=0000
#VECTOR=0800
#VECTOR=1000

.PHONY: all clean print

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


CC = $(EXEC_PREFIX)mcc18.exe
LD = $(EXEC_PREFIX)mplink.exe
AR = $(EXEC_PREFIX)mplib.exe
ASM		= $(EXEC_PREFIX)mpasmwin.exe
LINK	= $(EXEC_PREFIX)mplink.exe
MP2HEX	= $(EXEC_PREFIX)mp2hex.exe

RM = rm

TARGET = loader-$(DEVICE)



##########################################
#  Set mcc18 INSTALL PATH
#
ifndef MCC18
MCC18 = C:/MCC18
endif

SRCS		= boot.asm usb.asm usb_desc.asm vectors.asm flash.asm hidmon.asm
INCS		= boot_if.inc boot.inc io_cfg.inc usb_defs.inc usb_desc.inc usb.inc 
OBJS		= $(foreach f, $(SRCS), $(basename $(f)).o )

COF			= $(TARGET).cof
HEX			= $(TARGET).hex
MAP			= $(TARGET).map

#MPLAB_DIR	= "C:\Program Files\Microchip\MPASM Suite\"
LKR			= sd$(DEVICE)-$(VECTOR).lkr

ASMFLAGS	=

all: $(HEX)

$(HEX): $(COF)
	$(MP2HEX) -q $(COF)

$(COF): $(OBJS)
	$(LINK) -p$(DEVICE) -q $(LKR) $(OBJS) -m$(MAP) -o$@

%.o: %.asm $(INCS)
	$(ASM) -q -p$(DEVICE) -dVECT=0x$(VECTOR) $< -e -l -o$@ $(ASMFLAGS)

clean:
	rm -f *.o *.ERR *.LST *.map *.cod *.cof
# *.hex

print:
	@echo "SRCS = $(SRCS)"
	@echo "INCS = $(INCS)"
	@echo "OBJS = $(OBJS)"

dis:
	gpdasm -y -p 18f2550 $(TARGET).hex >1
	-tabconv -d8 1 2
#	 $(TARGET).dis

dump:
	srec2bin $(TARGET).hex 1 >2

#