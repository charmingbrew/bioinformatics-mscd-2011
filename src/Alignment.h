#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

//#include "AlignedSequence.h"
#include <vector>
#include <string>
using namespace std;

enum ALIGN_METHOD
{
	NWUNSCH,
	PAIRWISE
};

class Alignment
{
	private:
		//AlignedSequence AlignedSeqA;
		//AlignedSequence AlignedSeqB;
		bool isAligned;
        
		//void NWAlign(AlignedSequence A, AlignedSequence B);
		//void PWAlign(AlignedSequence A, AlignedSequence B);
	public:
		string ToString(void);
		void RunAlignment(ALIGN_METHOD method);
		
};

int MaxScore(int match, int deleted, int insert);
void Align(string A, string B);

#endif /* _ALIGNMENT_H */
