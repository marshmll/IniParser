#include "stdafx.h"
#include "Parser.h"

std::optional<Token> Parser::current_token()
{
    if (currentPosition < tokens.size())
        return tokens.at(currentPosition);

    return {};
}

std::optional<Token> Parser::consume_token()
{
    ++currentPosition;

    if (currentPosition - 1 < tokens.size())
        return tokens.at(currentPosition - 1);

    return {};
}

const std::optional<std::string> Parser::parse_assignment_expression(const std::string &identifier, const bool in_section)
{
    if (!in_section)
    {
        reset_position();
    }

    while (current_token().has_value())
    {
        if (current_token().value().getType() == TokenType::IDENTIFIER)
        {
            if (current_token().value().getSpan().literal == identifier)
            {
                consume_token();

                while (current_token().has_value())
                {
                    if (current_token().value().getType() == TokenType::ASSIGNMENT)
                    {
                        consume_token();

                        while (current_token().has_value())
                        {
                            if (current_token().value().getType() == TokenType::WHITESPACE)
                            {
                                consume_token();
                            }
                            else if (current_token().value().getType() == TokenType::NEWLINE ||
                                     current_token().value().getType() == TokenType::SECTION ||
                                     current_token().value().getType() == TokenType::IDENTIFIER ||
                                     current_token().value().getType() == TokenType::ASSIGNMENT ||
                                     current_token().value().getType() == TokenType::UNKOWN ||
                                     current_token().value().getType() == TokenType::END)
                            {
                                std::cerr << "Syntax error." << "\n";
                                return {};
                            }
                            else
                            {
                                return current_token().value().getValue();
                            }
                        }
                    }
                    else
                    {
                        consume_token();
                    }
                }
            }
            else
            {
                consume_token();
            }
        }
        else if (current_token().value().getType() == TokenType::SECTION && in_section)
        {
            return {};
        }
        else
        {
            consume_token();
        }
    }

    return {};
}

const bool Parser::seek_section(const std::string section)
{
    reset_position();
    while (current_token().has_value())
    {
        if (current_token().value().getType() == TokenType::SECTION)
        {
            if (current_token().value().getValue() == section)
            {
                consume_token();
                return true;
            }
        }

        consume_token();
    }

    reset_position();
    return false;
}

void Parser::set_position(const unsigned short position)
{
    currentPosition = position;
}

void Parser::reset_position()
{
    set_position(0);
}

Parser::Parser() : currentPosition(0)
{
}

Parser::~Parser()
{
}

void Parser::loadTokens(std::vector<Token> &tokens)
{
    this->tokens = tokens;

    std::cout << parse_assignment_expression("Fullscreen").value_or("Not found.") << "\n";
}
