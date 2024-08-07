#pragma once

#include <stdbool.h>

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#define NO_SECTION NULL

typedef struct IniProperty
{
    const std::string section;
    const std::string identifier;
    const std::string value;
} IniProperty;

class IniParser
{
private:
    std::stringstream ss;
    bool loaded;

public:
    IniParser();

    ~IniParser();

    const bool loadFromFile(const std::string path);

    const std::vector<IniProperty> getAllProperties();

    const std::vector<IniProperty> getAllProperties(const std::string section);
};