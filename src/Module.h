/**
 *	@file	Module.h
 *	@brief	A wrapper for SWIG, so that we dont have to make modules for every single associated class
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#ifndef _MODULE_H
#define _MODULE_H

#include "AlignedSequence.h"
#include "Alignment.h"
#include "Direction.h"
#include "MSA.h"
#include "Node.h"
#include "Parser.h"
#include "Scoring.h"
#include "Sequence.h"
#include "Tree.h"
#include "Tub.h"
#include "Writer.h"

class Module
{};

void Align(char* fasta_files[], int num_files, int algorithms, char* save_path);

#endif
