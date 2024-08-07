#include "Lexer.h"

std::optional<Token> Lexer::get_next_token()
{
    if (currentPosition > fSize)
        return {};

    if (currentPosition == fSize)
    {
        ++currentPosition;

        std::string eof_literal = "\\0";

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
    else if (is_newline(c))
    {
        type = TokenType::NEWLINE;
        consume();
    }
    else
    {
        consume();
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
