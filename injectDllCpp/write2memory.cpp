#include "pch.h"
#include "write2memory.h"
#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <tchar.h>
#include <stdlib.h>


int FindProcessId(const wchar_t* procName)
{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                if (!_wcsicmp(procEntry.szExeFile, procName))
                {
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));

        }
    }
    CloseHandle(hSnap);
    return procId;
}
uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
    uintptr_t modBaseAddr = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry))
        {
            do
            {
                if (!_wcsicmp(modEntry.szModule, modName))
                {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return modBaseAddr;
}
uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    return addr;
}

int writeToMemory4(wchar_t* fileNameEXE,int baseAddress, std::vector<unsigned int> offsets,int dataToWrite) {
    DWORD procId = FindProcessId(fileNameEXE);
    //************************************************************
    //Getmodulebaseaddress
    uintptr_t moduleBase = GetModuleBaseAddress(procId, fileNameEXE);
    //Get Handle to Process
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
    //Resolve base address of the pointer chain
    uintptr_t dynamicPtrBaseAddr = moduleBase + baseAddress;
    //Resolve the pointer chain
    uintptr_t addr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, offsets);


    //************
    // Write data to the calculated address
    SIZE_T bytesWritten;
    if (WriteProcessMemory(hProcess, (LPVOID)addr, &dataToWrite, sizeof(dataToWrite), &bytesWritten)) {
        std::cout << "Data written to process memory" << std::endl;
    }else{
        std::cout << "Failed to write data to process memory. Error code: " << GetLastError() << std::endl;
    }

    CloseHandle(hProcess);
    return 0;
}
