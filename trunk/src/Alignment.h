#include "Sequence.h"
#include "AlignedSequence.h"

#include <vector>
#include <string>
using namespace std;

#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

class Alignment
{
	private:
		Sequence SeqA;
		AlignedSequence AlignedA;

		Sequence SeqB;
		AlignedSequence AlignedB;

		bool isAligned;
		int score;

		/* Members used in alignment */
		int penalty;
		int scoreMatrix[4][4];
	public:
        Alignment(Sequence A, Sequence B);
		string ToString(void);

		vector<vector<int>> BuildMatrix(string A, string B);
		void NWAlign();
		void SWAlign();

		Sequence GetSeqA();
		Sequence GetSeqB();

		AlignedSequence GetAlignedA();
		AlignedSequence GetAlignedB();

		bool IsAligned();
		int GetScore();
};

int MaxScore(int match, int deleted, int insert);

#endif /* _ALIGNMENT_H */
