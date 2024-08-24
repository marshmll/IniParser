#include "stdafx.h"
#include "IniParser.h"

int main(void)
{
    IniParser parser;

    parser.loadFromFile("file.ini");

    for (auto &[identifier, value] : parser.getAllProperties("Graphics"))
    {
        std::cout << "identifier: " << identifier << "\n"
                  << "value: " << value << "\n";
    }

    exit(EXIT_SUCCESS);
}