#include "helper/Constants.hpp"

#include <windows.h>
#include <string>

void Const::init()
{
    // Get the path of the executable
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);
    std::string::size_type pos = std::string(path).find_last_of("\\/");
    Const::EXE_PATH = std::string(path).substr(0, pos);
}