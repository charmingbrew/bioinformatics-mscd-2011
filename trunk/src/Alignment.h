#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#include "AlignedSequence.h"
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
		AlignedSequence A;
		AlignedSequence B;
		bool isAligned;

		void NWAlign(AlignedSequence A, AlignedSequence B);
		void PWAlign(AlignedSequence A, AlignedSequence B);
	public:
		Alignment(Sequence A, Sequence B);
		Alignment(void);
		~Alignment(void);

		string ToString(void);
		void RunAlignment(ALIGN_METHOD method);
};

#endif /* _ALIGNMENT_H */
