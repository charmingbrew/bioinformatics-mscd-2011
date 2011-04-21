#include "AlignedSequence.h"

void AlignedSequence::SetAlignedGenotype(string gene_in)
{
    alignedgenotype = gene_in;
}

string AlignedSequence::GetAlignedGenotype()
{
    return alignedgenotype;
}
