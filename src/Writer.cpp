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
 *  a private static method that takes in a pointer to the alignment object
 *  and writes the alignment to a file.
 *  @param File A pointer to the deisired file name
 *  @param alignment A pointer to the aligned genotypes
 */
static void Writer::AlignWrite(std::string *File, Alignment *alignment)
{

}

/**
 *  a private static method that takes in a pointer to the sequence object
 *  and writes the sequence to a file.
 *  @param File A pointer to the desired file name
 *  @param sequence A pointer to the sequence of the genotypes
 */
static void Writer::SeqWrite(std::string *File, Sequence *sequence)
{

}

/**
 *  a private static method that takes in a pointer to the result object
 *  and writes the result to a file.
 *  @param File A pointer to the desired file name
 *  @param result A pointer to the result from the aligned genotypes
 */
static void Writer::AlignWrite(std::string *File, Result *result)
{

}

/**
 *  a public static method that calls the private method AlignWrite
 *  @param Path
 *  @param alignment A pointer to the aligned genotypes
 */
static void Writer::Write(std::string Path, Alignment *alignment)
{

}

/**
 *  a public static method that calls the private method SeqWrite
 *  @param Path
 *  @param sequence A pointer to the sequence of the genotypes
 */
static void Writer::Write(std::string Path, Sequence *sequence)
{

}

/**
 *  a public static method that calls the private method AlignWrite that writes the results
 *  @param Path
 *  @param result A pointer to the result of the aligned genotypes
 */
static void Writer::Write(std::string Path, Result *result)
{

}
