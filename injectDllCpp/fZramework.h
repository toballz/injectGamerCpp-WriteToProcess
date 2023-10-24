// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "tZargetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <SDKDDKVer.h>

#define IDS_APP_TITLE			103
//
#define IDR_MAINFRAME			128
//#define IDD_EXTERNALOVERLAY_DIALOG	102
//#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
//#define IDI_EXTERNALOVERLAY			107
//#define IDI_SMALL				108
#define IDC_EXTERNALOVERLAY			109
//#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif