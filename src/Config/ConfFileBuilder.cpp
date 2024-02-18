/*
I probably should have just used an external parser library, but I wanted to try to do it myself.
The parser has a couple of limitations like being unable to process multiple line values, replacing all values if one is missing/corrupted, etc,
but it serves it's purpose.
*/

#include "config/ConfFileBuilder.hpp"

#include "helper/FileUtils.hpp"
#include "helper/Constants.hpp"
#include "spdlog/spdlog.h"

#include <string>
#include <unordered_map>
#include <filesystem>
#include <fstream>
#include <stdexcept>

ConfFileBuilder::ConfFileBuilder(std::string p_filepath)
{
    _filepath = Const::getExePath() + '/' + p_filepath;
}

void ConfFileBuilder::addEntry(ConfEntry p_entry, ConfValue p_default_value)
{
    _entries.push_back(std::make_pair(p_entry, p_default_value));
}

void ConfFileBuilder::makeFile()
{
    // Make or overwrite the file
    std::ofstream file(_filepath, std::ofstream::out | std::ofstream::trunc);

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

std::unordered_map<std::string, ConfFileBuilder::ConfValue> ConfFileBuilder::build()
{
    // If file does not exist, create it
    if (!fileutils::fileExists(_filepath))
    {
        makeFile();
        return loadDefaults();
    }

    std::unordered_map<std::string, ConfValue> read_map;
    std::unordered_map<std::string, ConfValue> casted_map;

    std::ifstream file(_filepath);
    std::string line;

    // Read all entries from the file as strings
    while (std::getline(file, line))
    {
        // Remove comments
        std::size_t pos = line.find('#');
        if (pos != std::string::npos)
        {
            line = line.substr(0, pos);
        }

        pos = line.find('=');
        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos - 1);
            std::string value = line.substr(pos + 2);
            read_map[key] = value;
        }
    }
    
    // The file can contain errors, so let's compare the read map with the vector of specified entries while casting read values as strings to their correct types
    for (auto &entry : _entries)
    {
        std::string key = entry.first.key;
        ConfValue default_value = entry.second;
        if (read_map.find(key) == read_map.end())
        {
            spdlog::warn("[ConfFileBuilder::build] Key \"{}\" not found in the configuration file. File will be overwritten", key);
            makeFile();            // Overwrite the corrupted file
            return loadDefaults(); // Return the default values
        }
        std::string read_value = std::get<std::string>(read_map[key]);

        // Cast the read value to the correct type
        if (std::holds_alternative<bool>(default_value))
        {
            if (read_value == "true")
                casted_map[key] = true;
            else if (read_value == "false")
                casted_map[key] = false;
            else if (read_value == "1")
                casted_map[key] = true;
            else if (read_value == "0")
                casted_map[key] = false;
            else
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not a boolean. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
        }
        else if (std::holds_alternative<std::string>(default_value))
        {
            casted_map[key] = read_value; // No possible errors here
        }
        else if (std::holds_alternative<int>(default_value))
        {
            try
            {
                casted_map[key] = std::stoi(read_value);
            }
            catch (const std::invalid_argument &ia)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not an integer. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
            catch (const std::out_of_range &oor)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not an integer. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
        }
        else if (std::holds_alternative<float>(default_value))
        {
            try
            {
                casted_map[key] = std::stof(read_value);
            }
            catch (const std::invalid_argument &ia)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not a float. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
            catch (const std::out_of_range &oor)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not a float. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
        }
        else if (std::holds_alternative<double>(default_value))
        {
            try
            {
                casted_map[key] = std::stod(read_value);
            }
            catch (const std::invalid_argument &ia)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not a double. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
            catch (const std::out_of_range &oor)
            {
                spdlog::warn("[ConfFileBuilder::build] Value \"{}\" for key \"{}\" is not a double. File will be overwritten", read_value, key);
                makeFile();            // Overwrite the corrupted file
                return loadDefaults(); // Return the default values
            }
        }
    }
    // No entries are missing/corrupted, so it's safe to return the casted map
    return casted_map;
}

std::unordered_map<std::string, ConfFileBuilder::ConfValue> ConfFileBuilder::loadDefaults()
{
    std::unordered_map<std::string, ConfValue> defaults;
    for (auto &entry : _entries)
    {
        defaults[entry.first.key] = entry.second;
    }
    return defaults;
}