#include <iostream>
#include "Parser.h"
#include "Writer.h"

int main(void)
{
    char path[256];
    string filename;
    Sequence *seq;

    std::cout << "Enter name of file or path to file: ";
    std::cin >> path;

    seq = Parser::ParseToSequence(path);

    std::cout << "Enter file name to save to (do not include .txt): ";
    std::cin >> filename;
    seq->SetFilename(filename);

    Parser::PrintFromSequence(*seq);

    Writer::FileWrite(*seq);

    return 0;
}
