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
    SetName(name);
    SetSequence(genome);
}

/**
 *  Constructor that initializes all three fields.
 *  @param name The name of the sequence
 *  @param genome The sequence of the genotype itself
 *  @param filename The output file name
 */
Sequence::Sequence(string name, string genome, string file_in)
{
    SetName(name);
    SetSequence(genome);
    SetFilename(file_in);
}

void Sequence::SetSequence(string genome)
{
    genotype = genome;
}

string Sequence::GetSequence() {
	return genotype;
}

void Sequence::SetName(string name)
{
    this->name = name;
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