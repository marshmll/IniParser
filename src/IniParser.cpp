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

        std::cout << fileSstream.str();

        ifs.close();

        return true;
    }

    return false;
}

void IniParser::tokenize()
{
    for (char &c : fileSstream.str())
    {
        std::cout << c << "\n";
    }
}

IniParser::IniParser() : loaded(false) {}

IniParser::~IniParser()
{
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
