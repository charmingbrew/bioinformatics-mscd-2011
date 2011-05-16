/**
 *  @file   AlignedSequence.h
 *  @class  AlignedSequence
 *  @brief  Holds a sequence string after it is aligned
 */

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

		void SetScore(int score);
		int GetScore();
};

#endif
