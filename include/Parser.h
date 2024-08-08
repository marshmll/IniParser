#pragma once

#include "Token.h"

class Parser
{
private:
    std::vector<Token> &tokens;

public:
    
    Parser(std::vector<Token> &tokens);

    ~Parser();

};