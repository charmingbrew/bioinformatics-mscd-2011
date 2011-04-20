#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Sequence.h"

using namespace std;


/**
 *  @brief Testing Purposes Only!
 *  Method that Parses through a FASTA format File,
 *  stores it as a Sequence, and prints the name and the
 *  genotype to the console screen.
 *  TODO: Use Writer to write to screen.
 *  @param Path absolute or relative path to the FASTA file.
 */
void Parser::ParseNPrint(char * Path)
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
	Sequence *s = new Sequence(name, genome);
	cout << s->GetName() << endl << s->GetSequence() << endl;
	delete s;
}

