#include "Lexer.h"

std::optional<Token> Lexer::get_next_token()
{
    if (currentPosition > fSize)
        return {};

    if (currentPosition == fSize)
    {
        ++currentPosition;

        std::string eof_literal = "\0";

        return Token(TokenType::END, TextSpan(0, 0, eof_literal));
    }

    char c = current_char().value();

    TokenType type = TokenType::UNKOWN;
    const unsigned start = currentPosition;

    if (is_num_start(c))
    {
        type = TokenType::INTEGER;
        consume_integer();
    }
    else if (is_string_start(c))
    {
        type = TokenType::STRING;
        consume_string();
    }
    else if (is_section_start(c))
    {
        type = TokenType::SECTION;
        consume_section();
    }
    else if (is_assignment(c))
    {
        type = TokenType::ASSIGNMENT;
        consume();
    }
    else if (is_whitespace(c))
    {
        type = TokenType::WHITESPACE;
        consume();
    }
    else if (is_newline(c))
    {
        type = TokenType::NEWLINE;
        consume();
    }
    else
    {
        type = TokenType::IDENTIFIER;
        consume_identifier();
    }

    const unsigned end = currentPosition;
    const std::string literal = fileString.substr(start, end - start);
    const TextSpan span = TextSpan(start, end, literal);

    return Token(type, span);
}

std::optional<char> Lexer::consume()
{
    std::optional<char> c = current_char();
    ++currentPosition;

    return c;
}

const int Lexer::consume_integer()
{
    int number = 0;

    while (current_char().has_value())
    {
        char c = current_char().value();

        if (isdigit(c))
        {
            consume();
            number = number * 10 + static_cast<int>(c);
        }
        else
        {
            break;
        }
    }

    return number;
}

const std::string Lexer::consume_string()
{
    std::string str;
    consume();

    while (current_char().has_value())
    {
        char c = current_char().value();

        if (c == '"')
        {
            consume();
            break;
        }

        str.push_back(c);
        consume();
    }

    return str;
}

const std::string Lexer::consume_section()
{
    std::string section;
    consume();

    while (current_char().has_value())
    {
        char c = current_char().value();

        if (c == ']')
        {
            consume();
            break;
        }

        section.push_back(c);
        consume();
    }

    return section;
}

const std::string Lexer::consume_identifier()
{
    std::string identifier;

    while (current_char().has_value())
    {
        char c = current_char().value();

        if (is_newline(c) || is_whitespace(c))
            break;

        identifier.push_back(c);
        consume();
    }

    return identifier;
}

std::optional<char> Lexer::current_char()
{
    if (currentPosition < fSize)
        return fileString.at(currentPosition);

    return {};
}

const bool Lexer::is_num_start(const char &c)
{
    return isdigit(c);
}

const bool Lexer::is_string_start(const char &c)
{
    return c == '"';
}

const bool Lexer::is_section_start(const char &c)
{
    return c == '[';
}

const bool Lexer::is_assignment(const char &c)
{
    return c == '=';
}

const bool Lexer::is_whitespace(const char &c)
{
    return isblank(c);
}

const bool Lexer::is_newline(const char &c)
{
    return c == '\n';
}

Lexer::Lexer(std::stringstream &file_sstream)
{
    fileString = file_sstream.str();
    fSize = (unsigned)fileString.size();

    currentPosition = 0;
}

Lexer::~Lexer()
{
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    std::optional<Token> token = get_next_token();

    while (token.has_value())
    {
        tokens.push_back(token.value());

        token = get_next_token();
    }

    return tokens;
}
