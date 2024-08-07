#include "Token.h"

Token::Token(const TokenType type, const TextSpan span)
    : type(type), span(span)
{
}

Token::~Token()
{
}

const TokenType &Token::getType() const
{
    return type;
}

const TextSpan &Token::getSpan() const
{
    return span;
}
