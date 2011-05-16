#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

/**
 *  @file   Alignment.h
 *  @class  Alignment
 *  @brief  Class that controls Aligning Sequences.
 *          Alignment glues together two Sequences
 *          together. Alignments can be put together
 *          either locally (SWAlign) or globally (NWAlign)
 */

#include "Sequence.h"
#include "AlignedSequence.h"

#include <vector>
#include <string>
using namespace std;

class Alignment
{
	protected:
		string SeqA;
		AlignedSequence AlignedA;

		string SeqB;
		AlignedSequence AlignedB;

		bool isAligned;
		int score;

		/* Members used in alignment */
		int penalty;
		int scoreMatrix[4][4];
	public:
        Alignment();
        /// Constructor creates an alignment between A and B
        Alignment(string A, string B);
		string ToString(void);
		vector< vector<int> > BuildNWMatrix(string A, string B);
		vector< vector<int> > BuildSWMatrix(string A, string B, vector< vector<int> > &iBacktrace, vector< vector<int> > &jBacktrace);
		/**
		 *  Needleman-Wunsch Alignment method
		 */
		void NWAlign();
		/**
		 *  Smith-Waterman Alignment method
		 */
		void SWAlign();

		string GetSeqA();
		string GetSeqB();

		void SetSeqA(string seq_in);
		void SetSeqB(string seq_in);

		AlignedSequence GetAlignedA();
		AlignedSequence GetAlignedB();

		bool IsAligned();
		int GetScore();
};

/**
 *  Compares the three integers and returns the largest.
 *  @param match A direct match up with a letter.
 *  @param deleted Top string is alligned with a gap
 *  @param insert Bottom string is aligned with a gap
 *  @return the higest score of the three in an alignment matrix.
 */
int MaxScore(int match, int deleted, int insert);

#endif /* _ALIGNMENT_H */
