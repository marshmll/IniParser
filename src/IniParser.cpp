#include "IniParser.h"

IniParser::IniParser() : loaded(false) {}

IniParser::~IniParser()
{
}

const bool IniParser::loadFromFile(const std::string path)
{
    std::ifstream ifs(path);

    if (ifs.is_open())
    {
        char buf;
        while (ifs >> std::noskipws >> buf)
            ss << buf;
        this->loaded = true;

        std::cout << ss.str();

        ifs.close();
    }
    else
    {
        std::cerr << "[IniParser::IniParser] (ERROR): Unable to load file (" << path << "). Aborting." << "\n";
    }

    return loaded;
}

const std::vector<IniProperty> IniParser::getAllProperties()
{
    if (!loaded)
    {
        std::cerr << "[IniParser::getAllProperties] (ERROR): No file loaded." << "\n";
        return std::vector<IniProperty>();
    }
}

const std::vector<IniProperty> IniParser::getAllProperties(const std::string section)
{
    return std::vector<IniProperty>();
}
