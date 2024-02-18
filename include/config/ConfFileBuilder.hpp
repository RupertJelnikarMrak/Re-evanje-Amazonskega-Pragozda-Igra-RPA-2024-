#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <variant>


struct ConfEntry
{
    std::string key;
    std::string comment;
};

class ConfFileBuilder
{
    using ConfValue = std::variant<std::string, int, float, double, bool>;

    std::string _filepath;
    std::vector<std::pair<ConfEntry, ConfValue>> _entries;

    void makeFile(); // Overrides or creates the file if it doesn't already exist.
    std::unordered_map<std::string, ConfValue> loadDefaults(); // Returns a map of default values.
public:
    ConfFileBuilder(std::string p_filename);

    void addEntry(ConfEntry p_entry, ConfValue p_default_value); // Adds an entry to the file.
    std::unordered_map<std::string, ConfValue> build(); // Makes the file, or reads it if it already exists.
};