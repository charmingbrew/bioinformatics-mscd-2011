#include "AlignedSequence.h"

void AlignedSequence::SetAlignedGenotype(string aligned_genotype)
{
    this->aligned_genotype = aligned_genotype;
}

string AlignedSequence::GetAlignedGenotype()
{
    return aligned_genotype;
}
