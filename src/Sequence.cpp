/*
 *  @file Sequence.cpp
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Sequence.h"
#include "Parser.h"
#include "Alignment.h"

using std::string;
using std::cout;

/**
 * Default Constructor
 */
Sequence::Sequence()
{

}

/**
 *  Constructor that allows both fields to be initialized.
 *  @param Name The name of the Genotype Sequence
 *  @param Genome The Sequence of the genotype itself
 */
Sequence::Sequence(string Name, string Genome)
{
    SetName(Name);
    SetSequence(Genome);
}

void Sequence::SetSequence(string Genome)
{
    genotype = Genome;
}

string Sequence::GetSequence() {
	return genotype;
}

void Sequence::SetName(string Name)
{
    name = Name;
}

string Sequence::GetName()
{
    return name;
}


/**
 *  @brief Testing Method
 *  Tests that the Parser and Sequence
 *  classes work together well.
 *  TODO: Allow to parse through multiple Sequences
 */
int main () {
	char hello [101];
	cout << "Please enter the filepath: ";
	std::cin.getline(hello, 101);
	Parser::ParseNPrint(hello);
	return 0;
}
