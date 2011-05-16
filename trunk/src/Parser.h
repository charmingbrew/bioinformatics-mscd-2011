/**
 *	@file	Parser.h
 *	@brief	A class that reads FASTA files
 *	@return	Sequences
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Sequence.h"
#include "dirent.h"
#include <vector>

using namespace std;

class Parser
{
	public:
        /**
         * Prints gene sequence from sequence file to standard out
         * @param seq Sequence file to print from
         */
        static void PrintFromSequence(Sequence &seq)
        {
            cout << seq.GetName() << endl << seq.GetSequence() << endl;
        }

        /**
         * Takes a folder path in and parses all fasta files in that folder to sequence files
         * @param path Folder path stored in string
         * @param seqvector Vector of sequence pointers
         */
        static void ReadFromFolder(string path, vector<Sequence *> &seqvector)
        {
            DIR *dir;
            struct dirent *ent;
            string temp;

            if(path.compare("local") == 0) {
                path.resize(1);
                path.replace(0, 1, ".");
            }

            //dir = opendir(path.c_str());
            dir = opendir("/home/two/stuff/Code Blocks Projects/BioInfo/bin/Debug/");

            if(path.at(path.length() - 1) != '/' && path.at(path.length() - 1) != '\\')
                path += '/';

            if(dir != NULL) {
                while((ent = readdir(dir)) != NULL) {
                    temp = ent->d_name;
                    if(temp.find(".fasta") == temp.length() - 6) {
                        seqvector.push_back(ParseToSequence(path + ent->d_name));
                    }
                }
                closedir(dir);
            }
            else {
                // couldn't open directory
                perror("Couldn't open directory");
            }
        }


        /**
         *  Parse a fasta file to a sequence
         *  @param path String path to file to parse from
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
