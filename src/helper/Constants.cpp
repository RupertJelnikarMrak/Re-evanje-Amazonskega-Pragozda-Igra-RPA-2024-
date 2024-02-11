#include "helper/Constants.hpp"

#include <string>
#include <windows.h>

std::string Const::getExePath()
{
    // Get the path of the executable
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);
    std::string::size_type pos = std::string(path).find_last_of("\\/");
    return std::string(path).substr(0, pos);
}