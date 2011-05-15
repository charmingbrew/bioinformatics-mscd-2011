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
        void AlignSeqs(vector<Tub *> &tubvector, bool align_new);
        void Qcalc(vector<Tub *> &tubvector, Tree *phytree, int id);
        void QtoTree(int atub, int btub, vector<Tub *> &tubvector, Tree *phytree, int id);
        void AlignDCalc(vector<Tub *> &tubvector, int aindex, int bindex);
        string GetMSA(Tree *phytree);
    public:
        MSA();
        void NeighborJoin(vector<Sequence *> seqvector, bool align_nw); // align_nw = true for NWAlign
        string GetNewick();
};

#endif
