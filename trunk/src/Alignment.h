#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#include "Sequence.h"
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

};

int MaxScore(int match, int deleted, int insert);

#endif /* _ALIGNMENT_H */
