#include "pch.h"
#include "injector.h"
#include <string> 
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include "write2memory.h"


char* WCharToChar(const wchar_t* wideString) {
    int len = WideCharToMultiByte(CP_ACP, 0, wideString, -1, NULL, 0, NULL, NULL);
    if (len == 0) {
        // Handle the error, e.g., return nullptr or throw an exception
        return nullptr;
    }
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
std::wstring convertInt2wstring(int IntVal) {
    std::wstring wideString = std::to_wstring(IntVal);
    return wideString.c_str();
}
//
// 



//
//
//
// 
//
//
//


/*char _evilDLL[] = "C:\\Users\\tobal\\source\\repos\\Dll1\\x64\\Debug\\Dll1.dll";*/
const wchar_t*  processNameEXE =  L"NSUNS4.exe";
int _pidd;
int injectDllActivate() {
    if (FindProcessId(processNameEXE) == 0){
        return -112;
    }

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

    listenforKey('w');
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
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT* kb = (KBDLLHOOKSTRUCT*)lParam;
            if (!hackIsActivated) {
                if (kb->vkCode == VK_F4) {
                    OutputDebugString(L"Cheat Activated :)");
                    hackIsActivated = true;
                }
            }
            else {
                if (kb->vkCode == '1'){
                    //righ ninja tool
                    writeToMemory4(L"NSUNS4.exe", 0x0161C940, { 0x40,0x10,0x0,0x0,0x7C },387);
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
