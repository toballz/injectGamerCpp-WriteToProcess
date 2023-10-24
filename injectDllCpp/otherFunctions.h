#pragma once 
#ifndef otherFunctions_H
#define otherFunctions_H
#include <string> 
class LocalStorage {
public:
    /// <param name="IndexbyteToStore">->string</param>
    /// <param name="byteToStore">->string</param>
    static bool LocalStorage::store(std::string IndexbyteToStore, System::String^ byteToStoreSystemString);
    static std::string LocalStorage::get(std::string IndexbyteToGet);
};
class AppToolStatic {
public:
         std::string name = "injectCppHack";
};
#endif