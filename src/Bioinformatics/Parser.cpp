/**
 *  @file   Parser.cpp
 *  @brief  A class for reading Fasta and Align files
 *  @author Tony Do,
 *          Dane Elshof,
 *          Jonathan Nicholson,
 *          Dan Thode
 *  @date   17. April 2011
 */

#include "Parser.h"

/**
 *  A static method for parsing Fasta genotype files
 *  @param Name A pointer to the desired name string
 *  @param Sequence A pointer to the desired sequence string
 *  @param size_name The maximum buffer size for Name
 *  @param size_sequence The maximum buffer size for Sequence
 */
static void Parser::FastaParse(std::string *Name, std::string *Sequence, int size_name, int size_sequence);

/**
 *  A static method for parsing Alignment files
 *
 */
static void Parser::AlignParse();

/**
 *  A static method for creating Sequences from paths to Fasta files
 *  @param Path A full path to a Fasta file
 *  @return Returns a new Sequence file
 */
static Sequence Parser::SeqFromFile(std::string Path);

/**
 *  A static method for creating Sequences from a genotype
 *  @param Sequence A string containing the genotype
 *  @return Returns a new Sequence file
 */
static Sequence Parser::SeqFromString(std::string Sequence, std::string Name);

/**
 *
 *
 */
static Alignment Parser::AlignFromFile(std::string Path);
