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

    std::string _filename;
    std::vector<std::pair<ConfEntry, ConfValue>> _entries;

public:
    ConfFileBuilder(std::string p_filename);
    ~ConfFileBuilder();

    void addEntry(ConfEntry p_entry, ConfValue p_default_value);
    std::unordered_map<std::string, ConfValue> build();
};