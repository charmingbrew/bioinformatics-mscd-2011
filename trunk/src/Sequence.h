#ifndef _SEQUENCE_H
#define _SEQUENCE_H

#include <string>

using std::string;

class Sequence {
	private:
        string name;
		string genotype;
	public:
        Sequence(string name, string genome);
        Sequence();
		void SetSequence(string genome);
		string GetSequence();
		void SetName(string name);
		string GetName();
};

#endif /* _SEQUENCE_H */
