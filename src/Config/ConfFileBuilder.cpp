#include "config/ConfFileBuilder.hpp"

#include "helper/FileUtils.hpp"
#include "helper/Constants.hpp"

#include <string>
#include <unordered_map>
#include <filesystem>
#include <fstream>

ConfFileBuilder::ConfFileBuilder(std::string p_filename)
{
    _filename = p_filename;
}

ConfFileBuilder::~ConfFileBuilder()
{
}

void ConfFileBuilder::addEntry(ConfEntry p_entry, ConfValue p_default_value)
{
    _entries.push_back(std::make_pair(p_entry, p_default_value));
}

std::unordered_map<std::string, ConfFileBuilder::ConfValue> ConfFileBuilder::build()
{
    std::string conf_path = Const::getExePath() + '/';
    // If file does not exist, create it
    if (!fileutils::fileExists(conf_path + _filename))
    {
        // Make the file
        std::ofstream file(conf_path + _filename);

        // Write the configuration to the file
        for (auto &entry : _entries)
        {
            file << "# " << entry.first.comment << '\n'
                 << entry.first.key << " = ";
            if (std::holds_alternative<bool>(entry.second))
            {
                if (std::get<bool>(entry.second))
                    file << "true";
                else
                    file << "false";
            }
            else if (std::holds_alternative<std::string>(entry.second))
            {
                file << "\"" << std::get<std::string>(entry.second) << "\"";
            }
            else if (std::holds_alternative<int>(entry.second))
            {
                file << std::get<int>(entry.second);
            }
            else if (std::holds_alternative<float>(entry.second))
            {
                file << std::get<float>(entry.second);
            }
            else if (std::holds_alternative<double>(entry.second))
            {
                file << std::get<double>(entry.second);
            }
            file << std::endl;
        }
    }

    return std::unordered_map<std::string, ConfFileBuilder::ConfValue>();
}