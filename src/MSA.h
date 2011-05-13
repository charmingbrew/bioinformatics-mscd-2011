#ifndef _MSA_H
#define _MSA_H

#include <string>
#include <vector>
#include "Sequence.h"
#include "Tub.h"
#include "Tree.h"

class MSA
{
    private:
        void AlignSeqs(vector<Tub *> &tubvector, bool align_new);
        void Qcalc(vector<Tub *> &tubvector, Tree *phytree, int id);
        void QtoTree(int atub, int btub, vector<Tub *> &tubvector, Tree *phytree, int id);
    public:
        void NeighborJoin(vector<Sequence *> &seqvector, bool align_nw); // align_nw = true for NWAlign
};

#endif
