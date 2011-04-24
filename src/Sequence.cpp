/**
 *  @file Sequence.cpp
 *
 */
#include <string>
#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "Parser.h"
#include "Alignment.h"
#include "AlignedSequence.h"

using std::string;
using std::cout;

Sequence::Sequence()
{
}

/**
 *  Constructor that allows both fields to be initialized.
 *  @param name The name of the Genotype Sequence
 *  @param genotype The Sequence of the genotype
 */
Sequence::Sequence(string name, string genotype)
{
	this->name = name;
	this->genotype = genotype;
}

/**
 *  Constructor that initializes all three fields.
 *  @param name The name of the sequence
 *  @param genotype The sequence of the genotype
 *  @param filename The output file name
 */
Sequence::Sequence(string name, string genotype, string file_path)
{
    SetName(name);
    SetSequence(genotype);
    SetFilePath(file_path);
}

Sequence::Sequence(string name, string id, string genotype, string file_path)
{
    SetName(name);
    SetId(id);
    SetSequence(genotype);
    SetFilePath(file_path);
}

void Sequence::SetSequence(string genotype)
{
    this->genotype = genotype;
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

void Sequence::SetFilePath(string file_path)
{
    this->file_path = file_path;
}

string Sequence::GetFilePath()
{
    return file_path;
}

void Sequence::SetId(string id_in)
{
    this->id = id_in;
}

string Sequence::GetId()
{
    return id;
}

AlignedSequence &Sequence::GetAlignedSequence()
{
	return this->aligned_sequence;
}
