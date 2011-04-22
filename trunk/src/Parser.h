#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Sequence.h"
using namespace std;

class Parser
{
	public:
        /**
         *  @brief Testing Purposes Only!
         *  Method that Parses through a FASTA format File,
         *  stores it as a Sequence, and prints the name and the
         *  genotype to the console screen.
         *  TODO: Use Writer to write to screen.
         *  @param Path absolute or relative path to the FASTA file.
         */
        static void ParseNPrint(char * Path)
        {

            Sequence *s = ParseToSequence(Path);
            cout << s->GetName() << endl << s->GetSequence() << endl;
            delete s;
        }

        static void PrintFromSequence(Sequence seq)
        {
            cout << seq.GetName() << endl << seq.GetSequence() << endl;
        }

        static Sequence * ParseToSequence(char * Path)
        {
            string name, temp, genome;
            std::ifstream file (Path);
            if (file.is_open()) {
                if(file.good()) getline(file, name);
                    while (file.good()) {
                        getline(file, temp);
                        genome += temp;
                    }
            }
            return new Sequence(name, genome);
        }
};

#endif
