#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#include "Sequence.h"
#include "Scoring.h"
#include <vector>
#include <string>
using namespace std;

class Alignment
{
	private:
		Sequence SeqA;
		Sequence SeqB;
		bool isAligned;
		int score;

	public:
        Alignment(Sequence A, Sequence B);
		string ToString(void);
		void NWAlign();
		Sequence GetSeqA();
		Sequence GetSeqB();
		bool IsAligned();
		void SetScore(int score_in);
		int GetScore();
		void SWAlign();
		void MatrixSpawner();
        string A;
        string B;

        Scoring *scoring;
        int penalty;
        vector< vector<int> > AlignmentMatrix;

};

int MaxScore(int match, int deleted, int insert);

#endif /* _ALIGNMENT_H */
