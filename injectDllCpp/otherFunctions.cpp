#include "pch.h"
#include "otherFunctions.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <filesystem>
#include <vector>
#include <bitset>
#include <msclr/marshal_cppstd.h>
#include <string>
#include <sstream>

AppToolStatic AppTool;

std::string escapeString = "::: ";
std::string AppDataRoaming = std::string(getenv("APPDATA")) + "\\" + AppTool.name;
const char* AppDataRoamingPath = AppDataRoaming.c_str();
std::string storageFile = AppDataRoaming + "\\storage.dwf";
std::string stringToBinary(const std::string& input) {
    std::string binaryString = "";
    for (char c : input) {
        // Convert each character to its binary representation
        binaryString += std::bitset<8>(c).to_string();
    } return binaryString;
}
std::string binaryToString(const std::string& binary) {
    std::string result;
    for (size_t i = 0; i < binary.length(); i += 8) {
        std::string byte = binary.substr(i, 8);  // Extract 8 binary digits
        char character = static_cast<char>(std::bitset<8>(byte).to_ulong());  // Convert to decimal
        result += character;
    }
    return result;
}
int initializeFilesAndFolder(){
    //folder **************
    DWORD AppDataRoamingPathResult = GetFileAttributesA(AppDataRoamingPath);
    if (AppDataRoamingPathResult == INVALID_FILE_ATTRIBUTES && GetLastError() == ERROR_FILE_NOT_FOUND) {
        // The directory doesn't exist, so create it.
        if (CreateDirectoryA(AppDataRoamingPath, NULL)) {
            OutputDebugStringA("Folder created");
        } else {
            OutputDebugStringA("Failed to create folder");
            return false;
        }
    } else if (!(AppDataRoamingPathResult & FILE_ATTRIBUTE_DIRECTORY)) {
        OutputDebugStringA("Invalid directory");
        return false;
    }
    //file ***************
    //output mode and if !exist
    std::ofstream file(storageFile, std::ios::app);
    // Check successfully opened
    if (file.good()) {
        //success 
        file.close();
    }
}



bool LocalStorage::store(std::string IndexbyteToStore, System::String^ byteToStoreSystemString) {
    initializeFilesAndFolder();
    std::string byteToStore = msclr::interop::marshal_as<std::string>(byteToStoreSystemString);
    // Open the file for reading
    std::ifstream file(storageFile);
    if (!file.is_open()) {
        OutputDebugStringA("Failed to open file for reading.");
        return false;
    }

    std::string line;
    std::vector<std::string> lines;
    bool IndexFound = false;

    // Read and search each line in the file
    while (std::getline(file, line)) {
        if (line.find(IndexbyteToStore + escapeString) != std::string::npos) {
            // Replace the line
            lines.push_back(IndexbyteToStore + escapeString + stringToBinary(byteToStore));
            IndexFound = true;
        }
        else {
            // Keep the original line
            lines.push_back(line);
        }
    }

    file.close(); // Close the file

    // Open the file for writing
    std::ofstream outputFile(storageFile);

    if (!outputFile.is_open()) {
        OutputDebugStringA("Failed to open file for writing.");
        return false;
    }

    // Write the modified lines back to the file
    for (const std::string& modifiedLine : lines) {
        outputFile << modifiedLine << '\n';
    }

    outputFile.close();

    if (!IndexFound) {
        // If 'IndexbyteToStore' was not found, append a new line
        std::string textToAdd = IndexbyteToStore + escapeString + stringToBinary(byteToStore);
        std::ofstream outputFileAppend(storageFile, std::ios::app);
        if (outputFileAppend.is_open()) {
            outputFileAppend << textToAdd << '\n';
            outputFileAppend.close();
        }
        else {
            OutputDebugStringA("Failed to open file for appending.");
        }
    }

    return true;
}
std::string LocalStorage::get(std::string IndexbyteToGet) {
    initializeFilesAndFolder();
    std::string foundLineText;
    std::ifstream inputFile(storageFile);
    if (!inputFile.is_open()) {
        OutputDebugStringA("Failed to open the input file.");//<< std::endl;
        return "";
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.find(IndexbyteToGet + escapeString) != std::string::npos) {
            foundLineText = line;
            break;
        }
    }
    std::string token = "";
    try {
        inputFile.close();
        token = foundLineText.substr((IndexbyteToGet + escapeString).size()); // token is "scott"
        OutputDebugStringA(binaryToString(token.c_str()).c_str());
    }
    catch (const std::exception& e) { }
    return token;
}
