/*
 *  @file Sequence.cpp
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Sequence.h"

using std::string;
using std::cout;

void Sequence::SetSequence(string genome) {
	genotype = genome;
}

string Sequence::GetSequence() {
	return genotype;
}

int main () {
	Sequence *s = new Sequence();
	char hello [101];
	cout << "Please enter the filepath: ";
	std::cin.getline(hello, 101);
	string name;
	string temp;
	string genome;
	std::ifstream file (hello);
	if (file.is_open()) {
		if(file.good()) getline(file, name);
		while (file.good()) {
			getline(file, temp);
			genome += temp;
		}
	}
	s->SetSequence(genome);
	cout << s->GetSequence();
	return 0;
}