#include "stdafx.h"
#include "IniParser.h"

int main(void)
{
    IniParser parser;

    parser.loadFromFile("file.ini");

    exit(EXIT_SUCCESS);
}