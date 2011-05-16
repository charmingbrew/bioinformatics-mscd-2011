/**
 *	@file	Module.h
 *	@brief	A wrapper for SWIG, so that we dont have to make modules for every single associated class
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#include "Module.h"
#include <iostream>
#include <string>

void Align(char* fasta_files[], int num_files, int algorithms, char* save_path)
{
    for(int i = 0; i < num_files; i += 2)
    {
        char* path;
        Sequence *seq1 = Parser::ParseToSequence(fasta_files[i]);
        Sequence *seq2 = Parser::ParseToSequence(fasta_files[i+1]);
        Alignment *alignment = new Alignment(seq1->GetSequence(), seq2->GetSequence());

        if(algorithms == 1)
            alignment->NWAlign();
        else
            alignment->SWAlign();

        sprintf(path, "%s.%d", save_path, i);
        Writer::FileWrite(*alignment, path);
    }
}
