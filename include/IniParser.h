#pragma once

#include <fstream>

#include "Lexer.h"

#define NO_SECTION NULL

typedef struct
{
    const std::string section;
    const std::string identifier;
    const std::string value;
} IniProperty;

class IniParser
{
private:
    Lexer *lexer;

    std::stringstream fileSstream;
    std::vector<Token> tokens;

    bool loaded;

    const bool load_sstream(const std::string path);

    void tokenize();

public:
    IniParser();

    ~IniParser();

    const bool loadFromFile(const std::string path);

    const std::vector<IniProperty> getAllProperties();

    const std::vector<IniProperty> getAllProperties(const std::string section);
};