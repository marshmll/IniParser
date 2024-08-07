#pragma once

#include <stdbool.h>

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#define NO_SECTION NULL

enum TokenType
{
    BOOL = 0,
    INTEGER,
    FLOAT,
    STRING,
    WHITESPACE,
    UNKOWN,
    END,
};

typedef struct
{
    const unsigned start;
    const unsigned end;
    const std::string literal;
} TextSpan;

typedef struct
{
    const TokenType type;
    const TextSpan span;

} Token;

typedef struct
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

    void tokenize();

public:
    IniParser();

    ~IniParser();

    const bool loadFromFile(const std::string path);

    const std::vector<IniProperty> getAllProperties();

    const std::vector<IniProperty> getAllProperties(const std::string section);
};