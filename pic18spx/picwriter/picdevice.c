/*********************************************************************
 *	P I C d e v i c e
 *********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "monit.h"
#include "picdevice.h"


/*********************************************************************
 *
 *********************************************************************
 */

static	DeviceSpec device_spec_list[]={
	{
        /*DeviceName*/	 "PIC18F242",
        /*DeviceIDWord*/	 0x0480,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 2,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F252",
        /*DeviceIDWord*/	 0x0400,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 4,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F442",
        /*DeviceIDWord*/	 0x04A0,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 2,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F452",
        /*DeviceIDWord*/	 0x0420,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 4,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F248",
        /*DeviceIDWord*/	 0x0800,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 2,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F258",
        /*DeviceIDWord*/	 0x0840,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 4,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F448",
        /*DeviceIDWord*/	 0x0820,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 2,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F458",
        /*DeviceIDWord*/	 0x0860,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x0F,0x0F,0x00,0x01,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 4,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F1220",
        /*DeviceIDWord*/	 0x07E0,
        /*ProgramMemorySize*/	 4096,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x80,0x85,0x00,0x03,0xC0,0x03,0xE0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x80,0x85,0x00,0x03,0xC0,0x03,0xE0,0x03,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F1320",
        /*DeviceIDWord*/	 0x07C0,
        /*ProgramMemorySize*/	 8192,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x80,0x85,0x00,0x03,0xC0,0x03,0xE0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x80,0x85,0x00,0x03,0xC0,0x03,0xE0,0x03,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F2220",
        /*DeviceIDWord*/	 0x0580,
        /*ProgramMemorySize*/	 4096,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F2320",
        /*DeviceIDWord*/	 0x0500,
        /*ProgramMemorySize*/	 8192,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F4220",
        /*DeviceIDWord*/	 0x05A0,
        /*ProgramMemorySize*/	 4096,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F4320",
        /*DeviceIDWord*/	 0x0520,
        /*ProgramMemorySize*/	 8192,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0xCF,0x0F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command80,
        /*EEWriteType*/	 FixWaitTime,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F2450",
        /*DeviceIDWord*/	 0x2420,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 0,
        /*WriteBufferSize*/	 16,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x86,0xED,0x00,0x03,0x40,0x03,0x60,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x82,0x85,0x00,0x03,0x40,0x03,0x60,0x03,0x40},
        /*EraseCommand*/	 Command3F8F,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F2455",
        /*DeviceIDWord*/	 0x1260,
        /*ProgramMemorySize*/	 24576,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 32,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x87,0xE5,0x00,0x07,0xC0,0x07,0xE0,0x07,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x83,0x85,0x00,0x07,0xC0,0x07,0xE0,0x07,0x40},
        /*EraseCommand*/	 Command3F8F,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F2550",
        /*DeviceIDWord*/	 0x1240,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 32,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x87,0xE5,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F4450",
        /*DeviceIDWord*/	 0x2400,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 0,
        /*WriteBufferSize*/	 16,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x86,0xED,0x00,0x03,0x40,0x03,0x60,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x82,0x85,0x00,0x03,0x40,0x03,0x60,0x03,0x40},
        /*EraseCommand*/	 Command3F8F,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F4455",
        /*DeviceIDWord*/	 0x1220,
        /*ProgramMemorySize*/	 24576,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 32,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x87,0xE5,0x00,0x07,0xC0,0x07,0xE0,0x07,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x83,0x85,0x00,0x07,0xC0,0x07,0xE0,0x07,0x40},
        /*EraseCommand*/	 Command3F8F,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F4550",
        /*DeviceIDWord*/	 0x1200,
        /*ProgramMemorySize*/	 32768,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 32,
        /*ConfigMask*/	 {0x3F,0xCF,0x3F,0x1F,0x00,0x87,0xE5,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*ConfigValue*/	 {0x00,0x05,0x1F,0x1F,0x00,0x83,0x85,0x00,0x0F,0xC0,0x0F,0xE0,0x0F,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F14K50",
        /*DeviceIDWord*/	 0x4760,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 16,
        /*ConfigMask */	 {0x38,0xff,0x1f,0x1f,0x00,0x88,0x4d,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x1f,0x1f,0x00,0x88,0x05,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18F13K50",
        /*DeviceIDWord*/	 0x4740,
        /*ProgramMemorySize*/	 8192,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask */	 {0x38,0xff,0x1f,0x1f,0x00,0x88,0x4d,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x1f,0x1f,0x00,0x88,0x05,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},

	{
        /*DeviceName*/	 "PIC18LF14K50",
        /*DeviceIDWord*/	 0x4720,
        /*ProgramMemorySize*/	 16384,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 16,
        /*ConfigMask */	 {0x38,0xff,0x1f,0x1f,0x00,0x88,0x4d,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x1f,0x1f,0x00,0x88,0x05,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},
	{
        /*DeviceName*/	 "PIC18LF13K50",
        /*DeviceIDWord*/	 0x4700,
        /*ProgramMemorySize*/	 8192,
        /*EEDataMemorySize*/	 256,
        /*WriteBufferSize*/	 8,
        /*ConfigMask */	 {0x38,0xff,0x1f,0x1f,0x00,0x88,0x4d,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x1f,0x1f,0x00,0x88,0x05,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*EraseCommand*/	 Command81,
        /*EEWriteType*/	 PollWRbit,
        /*PanelNum*/	 1,
        /*PanelSize*/	 8192,
        /*ProgrammingWaitP*/	 10,
        /*ProgrammingWaitD*/	 50,
        /*ProgrammingWaitC*/	 50,
        /*ProgrammingWaitID*/	 50,
        /*EraseWait*/	 100,
	},



	// =============== End of Record
	{
        /*DeviceName*/	 	NULL,
        /*DeviceIDWord*/	 0,
        /*ProgramMemorySize*/0,
        /*EEDataMemorySize*/ 0,
        /*WriteBufferSize*/	 0,
        /*ConfigMask */	 {0x38,0xff,0x1f,0x1f,0x00,0x88,0xcd,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*ConfigValue*/	 {0x00,0x27,0x1f,0x1f,0x00,0x88,0x85,0x00,0x03,0xc0,0x03,0xe0,0x03,0x40},
        /*EraseCommand*/	 0,
        /*EEWriteType*/	 	 0,
        /*PanelNum*/	 	 0,
        /*PanelSize*/	 	 0,
        /*ProgrammingWaitP*/	 0,
        /*ProgrammingWaitD*/	 0,
        /*ProgrammingWaitC*/	 0,
        /*ProgrammingWaitID*/	 0,
		/*EraseWait*/	 	 0,
	},
};

/*********************************************************************
 *
 *********************************************************************
 */
DeviceSpec *FindDevice(int id)
{
	DeviceSpec *p = device_spec_list;
	id &= ~(0x1f);	// Revision�̓}�X�N.

	while(	p->DeviceName) {
		if( p->DeviceIDWord == id) {
			return p;
		}
		p++;
	}
	return NULL;
}
/*********************************************************************
 *
 *********************************************************************
 */
