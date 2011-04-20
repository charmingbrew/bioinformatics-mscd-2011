/*
 *  Sequence.h
 *
 *
 *  Created by Jonathan Nicholson on 4/18/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
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
