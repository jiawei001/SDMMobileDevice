/*
 *  SDMMD_Error.h
 *  SDM_MD_Demo
 *
 *  Copyright (c) 2013, Sam Marshall
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *  3. All advertising materials mentioning features or use of this software must display the following acknowledgement:
 *  	This product includes software developed by the Sam Marshall.
 *  4. Neither the name of the Sam Marshall nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY Sam Marshall ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Sam Marshall BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _SDM_MD_ERROR_H_
#define _SDM_MD_ERROR_H_

#import <CoreFoundation/CoreFoundation.h>

typedef enum SDMMD_ErrorCodes {
	MDERR_OK = 0x0,
	MDERR_SYSCALL = 0x01,
	MDERR_OUT_OF_MEMORY = 0x03,
	MDERR_QUERY_FAILED = 0x04,
	MDERR_INVALID_ARGUMENT = 0x0B,
	MDERR_DICT_NOT_LOADED = 0x25
} SDMMD_ErrorCodes;

#define sdmmd_return_t enum SDMMD_ErrorCodes

typedef enum SDMMD_AFCErrorCodes {
	MDERR_AFC_OK = 0x0,
	MDERR_AFC_OUT_OF_MEMORY = 0x03,
	MDERR_AFC_NOT_FOUND = 0x08,
	MDERR_AFC_ACCESS_DENIED = 0x09
} SDMMD_AFCErrorCodes;

#define sdmmd_afc_return_t enum SDMMD_AFCErrorCodes

typedef enum SDMMD_NotificationErrorCodes {
	MDERR_NOTIFICATION_MSG_CONNECTED = 1,
	MDERR_NOTIFICATION_MSG_DISCONNECTED = 2,
	MDERR_NOTIFICATION_MSG_UNKNOWN = 3
} SDMMD_NotificationErrorCodes;

#define sdmmd_notification_return_t enum SDMMD_NotificationErrorCodes

typedef enum SDMMD_USBMuxErrorCodes {
	MDERR_USBMUX_OK = 0x0,
	MDERR_USBMUX_ARG_NULL = 0x16,
	MDERR_USBMUX_FAILED = 0xffffffff
} SDMMD_USBMuxErrorCodes;

#define sdmmd_usbmux_return_t enum SDMMD_USBMuxErrorCodes

#define SDM_MD_CallSuccessful(result_code) ((result_code == MDERR_OK) || (result_code == MDERR_AFC_OK) || (result_code == MDERR_USBMUX_OK))


typedef struct SDMMD_SIMStatusCode {
	CFStringRef codeName;
	uint32_t resultCode;
} SDMMD_SIMStatusCode;

#define sdmmd_sim_return_t struct SDMMD_SIMStatusCode

#define kKnownSIMCodesNum 13

static struct SDMMD_SIMStatusCode KnownSIMCodes[kKnownSIMCodesNum] = {
	{CFSTR("kCTSIMSupportSIMStatusUnavailable"), 0},
	{CFSTR("kCTSIMSupportSIMStatusReady"), 1},
	{CFSTR("kCTSIMSupportSIMStatusNotReady"), 2},
	{CFSTR("kCTSIMSupportSIMStatusPINLocked"), 3},
	{CFSTR("kCTSIMSupportSIMStatusPUKLocked"), 4},
	{CFSTR("kCTSIMSupportSIMStatusNetworkLocked"), 5},
	{CFSTR("kCTSIMSupportSIMStatusCorporateLocked"), 6},
	{CFSTR("kCTSIMSupportSIMStatusOperatorLocked"), 7},
	{CFSTR("kCTSIMSupportSIMStatusOperatorSubsetLocked"), 8},
	{CFSTR("kCTSIMSupportSIMStatusServiceProviderLocked"), 9},
	{CFSTR("kCTSIMSupportSIMStatusMemoryFailure"), 10},
	{CFSTR("kCTSIMSupportSIMStatusFixedDialingLocked"), 11},
	{CFSTR("kCTSIMSupportSIMStatusBlacklisted"), 12}
};

typedef struct SDMMD_ActivationState {
	CFStringRef statusName;
	uint32_t statusCode;
} SDMMD_ActivationState;

#define sdmmd_activation_return_t struct SDMMD_ActivationState

#define kKnownActivationStatesNum 9

static struct SDMMD_ActivationState KnownActivationStates[kKnownActivationStatesNum] = {
	{CFSTR("Unactivated"), 0},
	{CFSTR("Activated"), 1},
	{CFSTR("FactoryActivated"), 2},
	{CFSTR("SoftActivated"), 3},
	{CFSTR("MismatchedIMEI"), 4},
	{CFSTR("MismatchedICCID"), 5},
	{CFSTR("MissingSIM"), 6},
	{CFSTR("WildcardActivated"), 7},
	{CFSTR("Expired"), 8},
};

struct SDMMD_DebugReturnCode {
	enum SDMMD_ErrorCodes result;
	CFDataRef data;
} SDMMD_DebugReturnCode;

#define sdmmd_debug_return_t struct SDMMD_DebugReturnCode

#endif