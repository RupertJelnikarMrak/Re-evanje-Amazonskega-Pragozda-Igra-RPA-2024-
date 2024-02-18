#include "helper/FileUtils.hpp"

#include <filesystem>

bool fileutils::fileExists(const std::string& p_filename)
{
    return std::filesystem::exists(p_filename);
}