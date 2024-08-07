#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <optional>

#include "Token.h"

class Lexer
{
private:
    std::string fileString;
    unsigned fSize;

    unsigned currentPosition;

    std::optional<Token> get_next_token();

    std::optional<char> consume();

    const int consume_integer();

    std::optional<char> current_char();

    const bool is_num_start(const char &c);

    const bool is_newline(const char &c);

public:
    Lexer(std::stringstream &file_sstream);

    ~Lexer();

    std::vector<Token> tokenize();
};