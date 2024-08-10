#pragma once

#include "Token.h"

class Parser
{
private:
    std::vector<Token> tokens;
    unsigned short currentPosition;

    std::optional<Token> current_token();

    std::optional<Token> consume_token();

    const std::optional<std::string> parse_assignment_expression(const std::string &identifier, const bool in_section = false);

    const bool seek_section(const std::string section);

    void set_position(const unsigned short position);

    void reset_position();

public:
    Parser();

    ~Parser();

    void loadTokens(std::vector<Token> &tokens);
};