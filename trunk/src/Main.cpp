#include <iostream>
#include "Parser.h"
#include "Writer.h"
#include "Scoring.h"

int main(void)
{
    char path1[256], path2[256];
    int seq_score;
    //string filename;
    Sequence *seq1,  *seq2;
    Scoring *score = new Scoring();

    std::cout << "Sequence 1) Enter name of file or path to file: ";
    std::cin >> path1;
    std::cout << "Sequence 2) Enter name of file or path to file: ";
    std::cin >> path2;

    seq1 = Parser::ParseToSequence(path1);
    seq2 = Parser::ParseToSequence(path2);

    seq_score = score->ScoreStrings(seq1->GetSequence(), seq2->GetSequence());
    std::cout << "Score of two sequences: " << seq_score << endl;

    Writer::FileWrite(*seq1);
    Writer::FileWrite(*seq2);

    std::cout << "press something then press enter" << endl;
    std::cin >> path1;

    return 0;
}
