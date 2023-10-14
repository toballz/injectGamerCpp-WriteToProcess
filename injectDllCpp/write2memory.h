#pragma once
#include <vector>
#ifndef write2memory_H
#define write2memory_H
/// <summary>
/// 
/// </summary>
/// <param name="fileNameEXE">NSUNS4.exe</param>
/// <param name="baseAddress">0x0161C940</param>
/// <param name="offsets">{ 0x40,0x10,0x0,0x0,0x7C }</param>
/// <param name="dataToWrite">72</param>
/// <returns></returns>
int writeToMemory4(wchar_t* fileNameEXE, int baseAddress, std::vector<unsigned int> offsets, int dataToWrite);
int FindProcessId(const wchar_t* procName);

#endif
