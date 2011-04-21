#ifndef _ALIGNEDSEQEUNCE_H
#define _ALIGNEDSEQUENCE_H

#include <string>
#include "Sequence.h"
using namespace std;

class AlignedSequence : public Sequence {
    private:
        string alignedgenotype;
        int score;
    public:
        void SetAlignedGenotype(string gene_in);
        string GetAlignedGenotype();
};

#endif
