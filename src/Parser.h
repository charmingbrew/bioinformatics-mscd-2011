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
