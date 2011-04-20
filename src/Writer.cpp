/**
 *  @file   Writer.cpp
 *  @brief  A class for writing the newly alligned FASTA files
 *  @author Tony Do,
 *          Dane Elshof,
 *          Jonathan Nicholson,
 *          Dan Thode
 *  @date   18. April 2011
 */

#include "Writer.h"

/**
 *  Default Constructor
 *
 */
Writer::Writer()
{

}

~Writer::Writer()
{

}

/**
 *  a private static method for writing the aligned Fasta files to a file
 *  @param File A pointer to the deisired file name
 *  @return alignment The aligned genotypes
 */
static void Writer::AlignWrite(std::string *File, Alignment alignment)
{

}

/**
 *  a private static method for writing the Sequences from a genotype to a file
 *  @param File A pointer to the desired file name
 *  @return sequence The sequence of the genotype
 */
static void Writer::SeqWrite(std::string *File, Sequence sequence)
{

}

/**
 *  a private static method for writing the results of the Alignmed genotypes to a file
 *  @param File A pointer to the desired file name
 *  @return result The result from the aligned genotype
 */
static void Writer::AlignWrite(std::string *File, Result result)
{

}

/**
 *  a public static method that calls the private method AlignWrite
 *  @param Path
 *
 */
static void Writer::Write(std::string Path, Alignment alignment)
{

}

static void Writer::Write(std::string Path, Sequence sequence)
{

}

static void Writer::Write(std::string Path, Result result)
{

}
