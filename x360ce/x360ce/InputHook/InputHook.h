/*  x360ce - XBOX360 Controler Emulator
 *  Copyright (C) 2002-2010 ToCA Edit
 *
 *  x360ce is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  x360ce is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with x360ce.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _InputHook_H_
#define _InputHook_H_

#include <CGuid.h>
#include "EasyHook.h"

extern ULONG ACLEntries[1];

struct InputHook_GAMEPAD_CONIFG
{
	BOOL  bEnabled;
	GUID  productGUID;
	GUID  instanceGUID;
	DWORD dwVID;
	DWORD dwPID;
	InputHook_GAMEPAD_CONIFG()
	{
		ZeroMemory(this,sizeof(InputHook_GAMEPAD_CONIFG));
	}
};

struct InputHook_CONIFG
{
	BOOL  bEnabled;
	DWORD dwHookMode;
	DWORD dwHookVID;
	DWORD dwHookPID;
	DWORD dwHookWinTrust;
	InputHook_CONIFG()
	{
		ZeroMemory(this,sizeof(InputHook_CONIFG));
	}
};

void HookWMI();
void HookDI();
void HookWinTrust();

void HookWMIClean();
void HookDIClean();
void HookWinTrustClean();

InputHook_CONIFG* InputHook_Config();
InputHook_GAMEPAD_CONIFG* InputHook_GamepadConfig(DWORD dwUserIndex);

VOID InputHook_Enable(BOOL state);
BOOL InputHook_LastState();
BOOL InputHook_Enable();

BOOL InputHook_Init(InputHook_CONIFG* fconfig, InputHook_GAMEPAD_CONIFG* gconfig);
BOOL InputHook_Clean();

#endif
