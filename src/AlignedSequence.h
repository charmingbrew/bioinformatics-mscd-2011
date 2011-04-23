#ifndef _ALIGNEDSEQUENCE_H
#define _ALIGNEDSEQUENCE_H

#include <string>
using namespace std;

class AlignedSequence {
    private:
        string aligned_genotype;
        int score;
    public:
        void SetAlignedGenotype(string aligned_genotype);
        string GetAlignedGenotype();
};

#endif
