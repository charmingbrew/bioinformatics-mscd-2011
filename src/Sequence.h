/**
 *	@file	Sequence.h
 *  @class  Sequence
 *	@brief	Stores a gene sequence, and its information
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#ifndef _SEQUENCE_H
#define _SEQUENCE_H

#include <string>
#include <vector>
#include "Alignment.h"

using std::string;

class Sequence {
	private:
        /**
         * file_path after parsing stores the output path ../folder/filename.txt
         * name stores the actual name of the file (the file.fasta without the .fasta)
         * genotype stores the gene sequence
         * id stores the first line of the fasta file (numerical id and other info)
         */
        string file_path;
        string name;
		string genotype;
		string id;
	public:
		Sequence();
        Sequence(string name, string genotype);
		Sequence(string name, string genotype, string file_path);
		Sequence(string name, string id, string genotype, string file_path);

		void SetSequence(string genotype);
		string GetSequence();

		void SetName(string name);
		string GetName();

		void SetFilePath(string file_path);
		string GetFilePath();

		void SetId(string id_in);
		string GetId();
};

#endif /* _SEQUENCE_H */
