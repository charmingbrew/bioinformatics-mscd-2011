/**
 *	@file	MSA.h
 *	@brief	
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#ifndef _MSA_H
#define _MSA_H

#include <string>
#include <vector>
#include "Sequence.h"
#include "Tub.h"
#include "Tree.h"
#include "Alignment.h"

class MSA : public Alignment
{
    private:
        string newick;
        /**
         * Creates a distance matrix between tubs
         * @param tubvector Vector of tubs to build dmatrix from
         * @param align_nw Boolean flag for which alignment method to use
         */
        void AlignSeqs(vector<Tub *> &tubvector, bool align_new);
        /**
         * Calculates Qscores for elements in the Dmatrix
         * @param tubvector Vector of tubs that creates the dmatrix
         * @param phytree The tree which is built from the q matrix
         * @param id The id that will be assigned to new alignments
         */
        void Qcalc(vector<Tub *> &tubvector, Tree *phytree, int id);
        /**
         * Using the Qmatrix a tub is added to the guide tree
         * @param atub Index in the tubvector of first tub
         * @param btub Index in the tubvector of second tub
         * @param tubvector Vector of tubs from which the tree is built
         * @param phytree Tree created from the tubvector
         * @param id Id number of tub that is created
         */
        void QtoTree(int atub, int btub, vector<Tub *> &tubvector, Tree *phytree, int id);
        /**
         * Creates D score for two tubs which represent previous alignments
         * @param tubvector Vector of tubs to be used in creation of dmatrix
         * @param aindex Index of first tub in tubvector
         * @param bindex Index of second tub in tubvector
         */
        void AlignDCalc(vector<Tub *> &tubvector, int aindex, int bindex);
        /**
         * Creates a Newick format string of the phylo tree
         * @param phytree Phylogeny tree
         */
        string GetMSA(Tree *phytree);
    public:
        /**
         * Default constructor initializes score to 0
         */
        MSA();
        /**
         * NeighborJoin is the main multiple sequence alignment function, it creates a vector
         * of tubs based on the vector of sequences passed into it, then performs msa
         * @param seqvector Vector of sequences
         * @param align_nw Boolean used as flag for which alignment method to use
         */
        void NeighborJoin(vector<Sequence *> seqvector, bool align_nw); // align_nw = true for NWAlign
        /**
         * Returns the newick string of the phylo tree
         */
        string GetNewick();
};

#endif
