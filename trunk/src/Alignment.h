#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#include "Sequence.h"
#include <vector>
#include <string>
using namespace std;

class Alignment
{
	private:
		//AlignedSequence AlignedSeqA;
		//AlignedSequence AlignedSeqB;
		bool isAligned;
        
		void NWAlign(Sequence A, Sequence B);
	public:
		string ToString(void);
		Alignment(Sequence A, Sequence B);
		
};

int MaxScore(int match, int deleted, int insert);
void Align(string A, string B);

#endif /* _ALIGNMENT_H */
