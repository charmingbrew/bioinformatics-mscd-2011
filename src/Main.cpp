#include <iostream>
#include <string>
#include "Parser.h"
#include "Writer.h"
#include "Scoring.h"
#include "Alignment.h"
#include "Sequence.h"
#include <limits>

#define clear_cin std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

int main(void)
{
    string path1, path2, choice;
    Alignment *phil;
    Sequence *seq1,  *seq2;
    vector<Sequence *> seqvector;
    bool keep_going = true;

    while(keep_going) {
        std::cout << "m - enter two files manually" << endl;
        std::cout << "a - enter a directory containing fasta files" << endl;
        std::cout << "e - exit" << endl;
        std::cout << "enter choice: ";
        cin >> choice;
        clear_cin;

        if(choice.compare("m") == 0) {
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

            keep_going = false;
        }
        else if(choice.compare("a") == 0) {
            std::cout << "Enter folder path to fasta files, or local for local fasta files: ";
            std::getline(std::cin, path1);

            Parser::ReadFromFolder(path1, seqvector);

            /*
            for(int i = 0; i < seqvector.size(); i++)
                Writer::FileWrite(*(seqvector[i]));
            */

            keep_going = false;
        }
        else if(choice.compare("e") == 0) {
            keep_going = false;
        }
    }

    std::cout << "press something then press enter" << endl;
    std::cin >> path1;

    return 0;
}
