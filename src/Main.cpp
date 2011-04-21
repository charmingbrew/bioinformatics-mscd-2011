#include <iostream>
#include "Parser.h"

int main(void)
{
    char path[256];

    std::cout << "Enter path to fasta file: ";
    std::cin >> path;

    Parser::ParseNPrint(path);

    return 0;
}
