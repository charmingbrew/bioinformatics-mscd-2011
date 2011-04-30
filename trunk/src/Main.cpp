#include <iostream>
#include <string>
#include "Parser.h"
#include "Writer.h"
#include "Scoring.h"
#include "Alignment.h"

int main(void)
{
    string path1, path2;
    Alignment *phil;
    Sequence *seq1,  *seq2;
    Scoring *score = new Scoring();

    std::cout << "Sequence 1) Enter name of file or path to file: ";
    std::getline(std::cin, path1);
    std::cout << "Sequence 2) Enter name of file or path to file: ";
    std::getline(std::cin, path2);

    seq1 = Parser::ParseToSequence(path1);
    seq2 = Parser::ParseToSequence(path2);
    phil = new Alignment(*seq1, *seq2);
    //phil->NWAlign();
    phil->SWAlign();

    cout << "Score: " << phil->GetScore() << endl;

    Writer::FileWrite(*seq1);
    Writer::FileWrite(*seq2);
    Writer::FileWrite(*phil, "test");

    std::cout << "press something then press enter" << endl;
    std::cin >> path1;

    return 0;
}
