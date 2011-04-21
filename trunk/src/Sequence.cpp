/**
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
Sequence::Sequence(string name, string genome)
{
    this.SetName(Name);
    this.SetSequence(genome);
}

void Sequence::SetSequence(string genome)
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

void Sequence::SetFilename(string filename_in)
{
    filename = filename_in;
}

string Sequence::GetFilename()
{
    return filename;
}

/**
 *  @brief Testing Method
 *  Tests that the Parser and Sequence
 *  classes work together well.
 *  TODO: Allow to parse through multiple Sequences
 */
