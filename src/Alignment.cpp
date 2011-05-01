/**
 *  @file   Alignment.cpp
 *  @brief  A class for aligning Sequences
 *          Class creates a Matrix based on the
 *          Scoring class and find the most absolute
 *          path through that Matrix to create the best
 *          match possible.
 *
 *          Needleman-Wunsch algorithm adapted from:
 *          <http://en.wikipedia.org/wiki/Needleman-Wunsch_algorithm>
 *  @see    Scoring.cpp
 *  @author Tony Do,
 *          Dane Elshof,
 *          Jonathan Nicholson,
 *          Dan Thode
 *  @date   20 April 2011
 */

#include "Alignment.h"
#include "Scoring.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define debug

Alignment::Alignment(Sequence A, Sequence B)
{
	this->SeqA = A;
	this->SeqB = B;
	this->score = 0;
}

/**
 *  Compares the three integers and returns the largest.
 *  @param match A direct match up with a letter.
 *  @param deleted Top string is alligned with a gap
 *  @param insert Bottom string is aligned with a gap
 *  @return the higest score of the three in an alignment matrix.
 */
int MaxScore(int match, int deleted, int insert)
{
    if (match > deleted)
        return match > insert ? match : insert;
    else if (deleted > match)
        return deleted > insert ? deleted : insert;
}

vector< vector<int> > Alignment::BuildNWMatrix(string A, string B)
{
    vector< vector<int> > AlignmentMatrix;
	AlignmentMatrix.resize(A.length(), vector<int>(B.length()) );
    for (int a = 0; a < A.length(); a++)
        AlignmentMatrix[a][0] = penalty * a;
    for (int b = 0; b < B.length(); b++)
        AlignmentMatrix[0][b] = penalty * b;
    for (int i = 1; i < A.length(); i++) {
        for (int j = 1; j < B.length(); j++) {
            int match = AlignmentMatrix[i-1][j-1] + Scoring::Score(A[i],B[j], scoreMatrix, penalty);
            int deleted = AlignmentMatrix[i-1][j] + penalty;
            int insert = AlignmentMatrix[i][j-1] + penalty;
            AlignmentMatrix[i][j] = MaxScore(match, deleted, insert);
        }
    }

	return AlignmentMatrix;
}

vector< vector<int> > Alignment::BuildSWMatrix(string A, string B, vector< vector<int> > &iBacktrace, vector< vector<int> > &jBacktrace)
{
    vector< vector<int> > AlignmentMatrix;
	int temp[4];
	int ind;
	AlignmentMatrix.resize(A.length() + 1, vector<int>(B.length() + 1) );
	iBacktrace.resize(A.length() + 1, vector<int>(B.length() + 1) );
	jBacktrace.resize(A.length() + 1, vector<int>(B.length() + 1) );

	/* Initialize with row and column of zeros */
	for(int i = 0; i < A.length() + 1; i++)
	{
		AlignmentMatrix[i][0];
	}

	for(int j = 0; j < B.length() + 1; j++)
	{
		AlignmentMatrix[0][j];
	}

	for(int i = 1; i <= A.length(); i++)
	{
		for(int j = 1; j <= B.length(); j++)
		{
			temp[0] = AlignmentMatrix[i - 1][j - 1] + Scoring::Score(A[i - 1], B[j - 1], scoreMatrix, penalty);
			temp[1] = AlignmentMatrix[i - 1][j] - penalty;                  
			temp[2] = AlignmentMatrix[i][j - 1] - penalty;                 
			temp[3] = 0;

			/* Find the max value */
			double max = temp[0];
			ind = 0;

			for(int i = 1; i < 4; i++)
			{
				if(temp[i] > max)
				{
					max = temp[i];
				}
			}
			
			AlignmentMatrix[i][j] = max;

			switch(ind){
				case 0:                                  // score in (i,j) stems from a match/mismatch
					iBacktrace[i][j] = i-1;
					jBacktrace[i][j] = j-1;
					break;
				case 1:                                  // score in (i,j) stems from a deletion in sequence A
					iBacktrace[i][j] = i-1;
					jBacktrace[i][j] = j;
					break;
				case 2:                                  // score in (i,j) stems from a deletion in sequence B
					iBacktrace[i][j] = i;
					jBacktrace[i][j] = j-1;
					break;
				case 3:                                  // (i,j) is the beginning of a subsequence
					iBacktrace[i][j] = i;
					jBacktrace[i][j] = j;	
					break;
			}
		}
	}

	return AlignmentMatrix;
}

/**
 *  Beginning stub for the alignment method.
 *  @todo Matches up Alignments into AlignedSequence A and B
 */
void Alignment::NWAlign()
{
	string A = SeqA.GetSequence();
	string B = SeqB.GetSequence();

	Scoring::GetDefaultMatrix(scoreMatrix);
	Scoring::GetDefaultPenalty(penalty);

	/* Create Needleman-Wunsch Alignment Matrix */
	vector< vector<int> > AlignmentMatrix = BuildNWMatrix(A, B);

	#ifdef debug
    for(int k = 0; k < A.length(); k++) {
        for (int l = 0; l < B.length(); l++) {
            cout << AlignmentMatrix[k][l] << " ";
        }
        cout << endl;
    }
	#endif

    string alignment_a = "";
    string alignment_b = "";
    int i = A.length()-1;
    int j = B.length()-1;
    while (i > 0 && j > 0) {
        int score = AlignmentMatrix[i][j];
        int score_diag = AlignmentMatrix[i - 1][j - 1];
        int score_up = AlignmentMatrix[i][j-1];
        int score_left = AlignmentMatrix[i-1][j];
        if (score == score_diag + Scoring::Score(A[i], B[j], scoreMatrix, penalty)) {
            alignment_a = A[i] + alignment_a;
            alignment_b = B[j] + alignment_b;
            i--;
            j--;
        } else if (score == score_left + penalty) {
            alignment_a = A[i] + alignment_a;
            alignment_b = "-" + alignment_b;
            i--;
        } else if (score == score_up + penalty) {
            alignment_a = "-" + alignment_a;
            alignment_b = B[j] + alignment_b;
            j--;
        }
    }
    while (i > 0) {
		alignment_a = A[i] + alignment_a;
        alignment_b = "-" + alignment_b;
        i--;
    }
    while (j > 0) {
        alignment_a = "-" + alignment_a;
        alignment_b = B[j] + alignment_b;
        j--;
    }
	if (i == 0 && j == 0)
	{
		alignment_a = A[0] + alignment_a;
		alignment_b = B[0] + alignment_b;
	}

	#ifdef debug
    cout << alignment_a << endl << alignment_b <<endl;
	#endif

	AlignedA.SetAlignedGenotype(alignment_a);
	AlignedB.SetAlignedGenotype(alignment_b);

	this->score = Scoring::ScoreStrings(AlignedA.GetAlignedGenotype(), AlignedB.GetAlignedGenotype(), scoreMatrix, penalty);

	this->isAligned = true;
}

void Alignment::SWAlign()
{
    string A = SeqA.GetSequence();
	string B = SeqB.GetSequence();

	Scoring::GetSWMatrix(scoreMatrix);
	penalty = -1;

	vector< vector<int> > iBacktrace;
	vector< vector<int> > jBacktrace;
	vector< vector<int> > AlignmentMatrix = BuildSWMatrix(A, B, iBacktrace, jBacktrace);

	// search H for the maximal score
    double H_max = 0.;
    int i_max=0,j_max=0;
    for(int i=1;i<A.length();i++){
        for(int j=1;j<B.length();j++){
            if(AlignmentMatrix[i][j]>H_max){
                H_max = AlignmentMatrix[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }

    int current_i = i_max;
	int current_j = j_max;
	int next_i = iBacktrace[current_i][current_j];
	int next_j = jBacktrace[current_i][current_j];
	int tick = 0;

	string alignment_a = "";
    string alignment_b = "";

	while(((current_i != next_i) || (current_j != next_j)) && (next_j != 0) && (next_i != 0))
	{
		if(next_i==current_i)
		{
			alignment_a = '-' + alignment_a;              // deletion in A
		}
		else
		{
			alignment_a = A[current_i-1] + alignment_a;   // match/mismatch in A
		}

		if(next_j==current_j)
		{
			alignment_b = '-' + alignment_b;              // deletion in B
		}
		else
		{
			alignment_b = B[current_j-1] + alignment_b;   // match/mismatch in B
		}

		current_i = next_i;
		current_j = next_j;
		next_i = iBacktrace[current_i][current_j];
		next_j = jBacktrace[current_i][current_j];
		tick++;
    }

	#ifdef debug
    cout << alignment_a << endl << alignment_b <<endl;
	#endif

	AlignedA.SetAlignedGenotype(alignment_a);
	AlignedB.SetAlignedGenotype(alignment_b);

	this->score = Scoring::ScoreStrings(AlignedA.GetAlignedGenotype(), AlignedB.GetAlignedGenotype(), scoreMatrix, penalty);

	this->isAligned = true;

}

/**
 *  Sequence Accessors
 */
Sequence Alignment::GetSeqA()
{
    return SeqA;
}
Sequence Alignment::GetSeqB()
{
    return SeqB;
}

AlignedSequence Alignment::GetAlignedA()
{
	return this->AlignedA;
}
AlignedSequence Alignment::GetAlignedB()
{
	return this->AlignedB;
}

bool Alignment::IsAligned()
{
    return isAligned;
}

int Alignment::GetScore()
{
    return this->score;
}
