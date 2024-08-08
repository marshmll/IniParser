#pragma once

#include "TextSpan.h"

enum TokenType
{
    INTEGER,
    STRING,
    SECTION,
    ASSIGNMENT,
    WHITESPACE,
    NEWLINE,
    BOOLEAN,
    IDENTIFIER,
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
    Token(const TokenType type);
    ~Token();

    const TokenType &getType() const;
    const TextSpan &getSpan() const;
};
