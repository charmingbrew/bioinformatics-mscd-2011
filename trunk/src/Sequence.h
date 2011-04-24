#ifndef _SEQUENCE_H
#define _SEQUENCE_H

#include "AlignedSequence.h"
#include <string>

using std::string;

class Sequence {
	private:
        string file_path;
        string name;
		string genotype;
		string id;
		AlignedSequence aligned_sequence;
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

		AlignedSequence &GetAlignedSequence();
};

#endif /* _SEQUENCE_H */
