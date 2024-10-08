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

        // std::cout << fileSstream.str() << "\n";

        ifs.close();

        return true;
    }

    return false;
}

IniParser::IniParser() : loaded(false)
{
    lexer = new Lexer();
    parser = new Parser();
}

IniParser::~IniParser()
{
    delete lexer;
    delete parser;
}

const bool IniParser::loadFromFile(const std::string path)
{
    loaded = load_sstream(path);

    if (!loaded)
    {
        std::cerr << "[IniParser::IniParser] (ERROR): Unable to load file (" << path << "). Aborting." << "\n";
    }
    else
    {
        tokens = lexer->tokenize(fileSstream);

        // for (auto &token : tokens)
        // {
        //     std::cout << "\n______TOKEN______" << "\n"
        //               << "type: " << token.getTypeName() << "\n"
        //               << "start: " << token.getSpan().start << "\n"
        //               << "end: " << token.getSpan().end << "\n"
        //               << "literal: \"" << token.getSpan().literal << "\"\n"
        //               << "value: \"" << token.getValue() << "\"\n";
        // }

        parser->loadTokens(tokens);
    }

    return loaded;
}

const std::string IniParser::getProperty(const std::string section, const std::string identifier)
{
    if (!loaded)
    {
        std::cerr << "[IniParser::getAllProperties] (ERROR): No file loaded." << "\n";
    }

    return parser->getProperty(section, identifier);
}

const std::vector<std::pair<std::string, std::string>> IniParser::getAllProperties()
{
    if (!loaded)
    {
        std::cerr << "[IniParser::getAllProperties] (ERROR): No file loaded." << "\n";
    }

    return parser->getAllProperties();
}

const std::vector<std::pair<std::string, std::string>> IniParser::getAllProperties(const std::string section)
{
    if (!loaded)
    {
        std::cerr << "[IniParser::getAllProperties] (ERROR): No file loaded." << "\n";
    }

    return parser->getAllProperties(section);
}
