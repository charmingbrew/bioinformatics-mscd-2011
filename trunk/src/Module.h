
#ifndef _MODULE_H
#define _MODULE_H

#include "AlignedSequence.h"
#include "Alignment.h"
#include "Node.h"
#include "Parser.h"
#include "Scoring.h"
#include "Sequence.h"
#include "Tree.h"
#include "Writer.h"

class Module
{};

void Align(char* fasta_files[], int num_files, int algorithms, char* save_path);

#endif
