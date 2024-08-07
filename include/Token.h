#pragma once

#include "TextSpan.h"

enum TokenType
{
    BOOL,
    INTEGER,
    FLOAT,
    STRING,
    WHITESPACE,
    NEWLINE,
    UNKOWN,
    END,
};

class Token
{
private:
    TokenType type;
    TextSpan span;

public:
    Token(const TokenType type, const TextSpan span);
    ~Token();

    const TokenType &getType() const;
    const TextSpan &getSpan() const;
};