#include "stdafx.h"
#include "Token.h"

Token::Token(const TokenType type, const TextSpan span) : type(type), span(span) {}

Token::Token(const TokenType type) : type(type), span(0, 0, "NULL") {}

Token::~Token() {}

const TokenType &Token::getType() const { return type; }

const TextSpan &Token::getSpan() const { return span; }
