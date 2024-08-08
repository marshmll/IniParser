#include "stdafx.h"
#include "IniParser.h"

const bool IniParser::load_sstream(const std::string path)
{
    std::ifstream ifs(path);

    if (ifs.is_open())
    {
        char buf;
        while (ifs >> std::noskipws >> buf)
            fileSstream << buf;
        this->loaded = true;

        std::cout << fileSstream.str() << "\n";

        ifs.close();

        return true;
    }

    return false;
}

void IniParser::tokenize()
{
    lexer = new Lexer(fileSstream);

    tokens = lexer->tokenize();

    for (auto &token : tokens)
    {
        std::cout << "\n______TOKEN______" << "\n"
                  //   << "type: " << token.getType() << "\n"
                  //   << "start: " << token.getSpan().start << "\n"
                  //   << "end: " << token.getSpan().end << "\n"
                  << "literal: \"" << token.getSpan().literal << "\"\n";

        switch (token.getType())
        {
        case TokenType::INTEGER:
            std::cout << "value: " << std::atoi(token.getSpan().literal.c_str()) << "\n";
            break;

        case TokenType::STRING:
            std::cout << "value: " << token.getSpan().literal.substr(1, token.getSpan().literal.size() - 2) << "\n";
            break;

        case TokenType::BOOLEAN:
            std::cout << "value: " << (token.getSpan().literal == "true") << "\n";
            break;

        default:
            break;
        }
    }
}

IniParser::IniParser() : loaded(false) {}

IniParser::~IniParser()
{
    delete lexer;
}

const bool IniParser::loadFromFile(const std::string path)
{
    loaded = load_sstream(path);

    if (!loaded)
        std::cerr << "[IniParser::IniParser] (ERROR): Unable to load file (" << path << "). Aborting." << "\n";
    else
        tokenize();

    return loaded;
}

const std::vector<IniProperty> IniParser::getAllProperties()
{
    if (!loaded)
    {
        std::cerr << "[IniParser::getAllProperties] (ERROR): No file loaded." << "\n";
    }
    return std::vector<IniProperty>();
}

const std::vector<IniProperty> IniParser::getAllProperties(const std::string section)
{
    return std::vector<IniProperty>();
}
