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
        static void ParseNPrint(char *Path)
        {

            Sequence *s = ParseToSequence(Path);
            cout << s->GetName() << endl << s->GetSequence() << endl;
            delete s;
        }

        static void PrintFromSequence(Sequence &seq)
        {
            cout << seq.GetName() << endl << seq.GetSequence() << endl;
        }

        static Sequence *ParseToSequence(char *Path)
        {
            string name, temp, filename, genotype;
            std::ifstream file (Path);
            if (file.is_open()) {
                if(file.good()) getline(file, name);
                filename = name.substr(name.find("gb|") + 3, 6);
                while (file.good()) {
                    getline(file, temp);
                    genotype += temp;
                }
            }
            return new Sequence(name, genotype, filename);
        }
};

#endif