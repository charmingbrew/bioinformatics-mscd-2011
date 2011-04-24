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

        /**
         *  Parse a fasta file to a sequence
         */
        static Sequence *ParseToSequence(string path)
        {
            string name, temp, genotype, id;
            ifstream file (path.c_str());
            int i, j;

            i = j = 0;
            // find the index in the path where .fasta extension starts
            i = path.find(".fasta");
            j = i;
            // find the beginning of the actual filename inside the path
            while(path.at(j) != '\\' && path.at(j) != '/' && j > 0)
                j--;
            // set the name of the sequence to the filename without the .fasta extension
            if(j > 0)
                name = path.substr(j + 1, i - j);
            else
                name = path.substr(j, i);

            // path is changed to the ouput file's path
            path = path.substr(0, i);
            path += ".txt";
            // parse sequence from file, removing new lines
            if (file.is_open()) {
                if(file.good()) getline(file, id);
                while (file.good()) {
                    getline(file, temp);
                    genotype += temp;
                }
            }
            return new Sequence(name, id, genotype, path);
        }
};

#endif
