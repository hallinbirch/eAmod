/****************************************************************************!
*                            _                                               *
*                           / \                         _                    *
*                   ___    / _ \   _ __ ___   ____  ___| |                   *
*                  / _ \  / /_\ \ | '_ ` _ \./  _ \/  _  |                   *
*                 |  __/ /  ___  \| | | | | |  (_) ) (_) |                   *
*                  \___|/__/   \__\_| |_| |_|\____/\_____/                   *
*                                                                            *
*                            eAmod Source File                               *
*                                                                            *
******************************************************************************
* src/common/utils.h                                                         *
******************************************************************************
* Copyright (c) eAmod Dev Team                                               *
* Copyright (c) rAthena Dev Team                                             *
* Copyright (c) brAthena Dev Team                                            *
* Copyright (c) Hercules Dev Team                                            *
* Copyright (c) 3CeAM Dev Team                                               *
* Copyright (c) Athena Dev Teams                                             *
*                                                                            *
* Licensed under GNU GPL                                                     *
* For more information read the LICENSE file in the root of the emulator     *
*****************************************************************************/

#ifndef _UTILS_H_
#define _UTILS_H_

#include "../common/cbasetypes.h"
#include <stdio.h> // FILE*

// generate a hex dump of the first 'length' bytes of 'buffer'
void WriteDump(FILE *fp, const void *buffer, size_t length);
void ShowDump(const void *buffer, size_t length);

void findfile(const char *p, const char *pat, void (func)(const char *));
bool exists(const char *filename);

//Caps values to min/max
#define cap_value(a, min, max) ((a >= max) ? max : (a <= min) ? min : a)

#define add2limit(a, b, max) \
	do { \
		if( (max - a) < b ) { \
			a = max; \
		} else { \
			a += b; \
		} \
	} while(0)

#define sub2limit(a, b, min) \
	do { \
		if( (b + min) > a ) { \
			a = min; \
		} else { \
			a -= b; \
		} \
	} while(0)

/// calculates the value of A / B, in percent (rounded down)
unsigned int get_percentage(const unsigned int A, const unsigned int B);

//////////////////////////////////////////////////////////////////////////
// byte word dword access [Shinomori]
//////////////////////////////////////////////////////////////////////////

extern uint8 GetByte(uint32 val, int idx);
extern uint16 GetWord(uint32 val, int idx);
extern uint16 MakeWord(uint8 byte0, uint8 byte1);
extern uint32 MakeDWord(uint16 word0, uint16 word1);

#endif /* _UTILS_H_ */
