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
		AlignedSequence aligned_sequence;
	public:
        Sequence(string name, string genotype);
		Sequence(string name, string genotype, string file_path);

		void SetSequence(string genotype);
		string GetSequence();

		void SetName(string name);
		string GetName();

		void SetFilePath(string file_path);
		string GetFilePath();
};

#endif /* _SEQUENCE_H */
