#include "pch.h"
#include "injector.h"
#include <string> 
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include "write2memory.h"


char* WCharToChar(const wchar_t* wideString) {
    int len = WideCharToMultiByte(CP_ACP, 0, wideString, -1, NULL, 0, NULL, NULL);
    if (len == 0) { return nullptr; }
    // Allocate a buffer for the narrow character string
    char* narrowString = new char[len];
    // Convert the wide character string to narrow character
    WideCharToMultiByte(CP_ACP, 0, wideString, -1, narrowString, len, NULL, NULL);
    return narrowString;
}
DWORD getProcessIDByName(const char* processName) {
    DWORD pid = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &processEntry)) {
        do {
            if (strcmp(WCharToChar(processEntry.szExeFile), processName) == 0) {
                pid = processEntry.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &processEntry));
    }

    CloseHandle(snapshot);
    return pid;
} 
//
// 
/*char _evilDLL[] = "C:\\Users\\tobal\\source\\repos\\Dll1\\x64\\Debug\\Dll1.dll";*/
const wchar_t*  processNameEXE =  L"NSUNS4.exe";
int _pidd;
int injectDllActivate() {
    if (FindProcessId(processNameEXE) == 0){return -112;}
    return 0;
    /*
    HANDLE ph; // process handle
    HANDLE rt; // remote thread
    LPVOID rb; // remote buffer
    //*********
      _pidd = getProcessIDByName(processNameEXE);
    unsigned int evilLen = sizeof(_evilDLL) + 1;
    //*********
    //*********
    //IF PROCESS IS RUNNING
    if ( _pidd == 0) {
        //err
         return -112;
    }
    // handle to kernel32 and pass it to GetProcAddress
    HMODULE hKernel32 = GetModuleHandle(L"Kernel32");
    VOID* lb = GetProcAddress(hKernel32, "LoadLibraryA");

    // parse process ID
    if (_pidd == 0) {
        return -115;
    }
    printf("PID: %i", _pidd);
    ph = OpenProcess(PROCESS_ALL_ACCESS, FALSE, DWORD(_pidd));

    // allocate memory buffer for remote process
    rb = VirtualAllocEx(ph, NULL, evilLen, (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);

    // "copy" evil DLL between processes;
    WriteProcessMemory(ph, rb, _evilDLL, evilLen, NULL);

    // our process start new thread
    rt = CreateRemoteThread(ph, NULL, 0, (LPTHREAD_START_ROUTINE)lb, rb, 0, NULL);
    CloseHandle(ph);

    listenforKey();
    return 0;
    */
}


//#########
// F4 to activate cheat
// 1 top ninja tool
// 2 right ninja too001l
// 3 bottom ninja tool
// 4 left ninja tool
//
bool hackIsActivated;
HHOOK hKeyboardHook;
wchar_t* _appnameExe_input = (wchar_t*)processNameEXE;
int _baseAddress = 0x0161C940;
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT* kb = (KBDLLHOOKSTRUCT*)lParam;
            if (!hackIsActivated) {
                if (kb->vkCode == VK_F4) {
                    hackIsActivated = true;
                }
            }
            else {
                if (kb->vkCode == '1'){
                    //right ninja tool
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x0,0x0,0x7C },67);
                    //top ninja tool
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x0,0x10,0x70 }, 78);
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x8,0x8,0x0,0x70 }, 77);
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x8,0x0,0x70 }, 76);//
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x70 }, 75);//real
                    //left ninja tool
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x0,0x8,0x78 }, 99);
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x78 }, 98);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x20,0x10,0x10,0x0,0x78 }, 97);
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x20,0x10,0x0,0x0,0x78 }, 96);
                    //bottom ninja tool
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x0,0x0,0x74 }, 81);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0xB0,0x48,0x60,0x8,0x10,0x10,0x74 }, 80);
                }else if (kb->vkCode == '2') {
                    //chakra
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x8,0x8,0x0,0x40 }, 4122.23f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x40,0x60,0x0,0x40 }, 3321.11f);
                    //subtitusion
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x0,0x0,0x48}, 100.0f);
                    //health
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x0,0x0,0x38 }, 100.0f);
                    //ecrete techniq
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x6C }, 100.0f);
                    //first helper
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x8,0x54 }, 5000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x8,0x54 }, 6000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x0,0x8,0x54 }, 7000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x10,0x8,0x54 }, 9000.0f);//real
                    //second helper
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x10,0x54 }, 5000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x0,0x10,0x54 }, 6000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x10,0x10,0x54 }, 7000.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x10,0x10,0x54 }, 9000.0f);//real
                }else if (kb->vkCode == '3') {
                    //kill enemy instantly
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x10,0x90,0x38 }, 50.0f);//real
                    writeToMemory4(_appnameExe_input, _baseAddress, { 0x40,0x0,0x0,0x90,0x38 }, 0.0f);//real
                }
                hackIsActivated = false;
            }
        }
    }
    return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}
void listenforKey() {
    // Set up the keyboard hook
    hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
    if (hKeyboardHook == NULL) {
        OutputDebugString(L"Failed to set up the keyboard hook.");
        return  ;
    }
    // Message loop to keep the program running
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // Unhook the keyboard hook
    UnhookWindowsHookEx(hKeyboardHook);
    return;
}
