/**
 *  @file   Alignment.cpp
 *  @brief  A class for aligning Sequences
 *          Class creates a Matrix based on the
 *          Scoring class and find the most absolute
 *          path through that Matrix to create the best
 *          match possible.
 *          Thank you Needleman-Wunsch for your great work:
 *          <http://en.wikipedia.org/wiki/Needleman-Wunsch_algorithm>
 *  @see    Scoring.cpp
 *  @author Tony Do,
 *          Dane Elshof,
 *          Jonathan Nicholson,
 *          Dan Thode
 *  @date   20 April 2011
 */

#include "Alignment.h"
//#include "Scoring.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//#define debug

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

void Alignment::MatrixSpawner()
{
    A = SeqA.GetSequence();
	B = SeqB.GetSequence();

	Scoring *scoring = new Scoring();
	penalty = scoring->GetPenalty();
    vector< vector<int> > AlignmentMatrix;

    AlignmentMatrix.resize(A.length(), vector<int>(B.length()) );
    for (int a = 0; a < A.length(); a++)
        AlignmentMatrix[a][0] = penalty * a;
    for (int b = 0; b < B.length(); b++)
        AlignmentMatrix[0][b] = penalty * b;
    for (int i = 1; i < A.length(); i++) {
        for (int j = 1; j < B.length(); j++) {
            int match = AlignmentMatrix[i-1][j-1] + scoring->Score(A[i],B[j]);
            int deleted = AlignmentMatrix[i-1][j] + penalty;
            int insert = AlignmentMatrix[i][j-1] + penalty;
            AlignmentMatrix[i][j] = MaxScore(match, deleted, insert);
        }
    }
}

/**
 *  Beginning stub for the alignment method.
 *  @todo Matches up Alignments into AlignedSequence A and B
 */
void Alignment::NWAlign()
{

	MatrixSpawner();

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
        if (score == score_diag + scoring->Score(A[i], B[j])) {
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

	SeqA.GetAlignedSequence().SetAlignedGenotype(alignment_a);
	SeqB.GetAlignedSequence().SetAlignedGenotype(alignment_b);

	this->isAligned = true;
}

void Alignment::SWAlign()
{
    string A = SeqA.GetSequence();
	string B = SeqB.GetSequence();

	Scoring *scoring = new Scoring();
	int penalty = scoring->GetPenalty();
	vector< vector<int> > AlignmentMatrix;

	MatrixSpawner();

	#ifdef debug
    for(int k = 0; k < A.length(); k++) {
        for (int l = 0; l < B.length(); l++) {
            cout << AlignmentMatrix[k][l] << " ";
        }
        cout << endl;
    }
	#endif

	// search H for the maximal score
    double H_max = 0.;
    int i_max=0,j_max=0;
    for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            if(AlignmentMatrix[i][j]>H_max){
                H_max = AlignmentMatrix[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }

    string alignment_a = "";
    string alignment_b = "";
    int i = A.length()-1;
    int j = B.length()-1;
    while ((i_max > i || j_max > j) && AlignmentMatrix[i][j] != 0) {
        int score = AlignmentMatrix[i_max][j_max];
        int score_diag = AlignmentMatrix[i - 1][j - 1];
        int score_up = AlignmentMatrix[i][j-1];
        int score_left = AlignmentMatrix[i-1][j];
        if (score == score_diag + scoring->Score(A[i], B[j])) {
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

	SeqA.GetAlignedSequence().SetAlignedGenotype(alignment_a);
	SeqB.GetAlignedSequence().SetAlignedGenotype(alignment_b);

	this->isAligned = true;

}

/**
 *  Thing
 */
Sequence Alignment::GetSeqA()
{
    return SeqA;
}
Sequence Alignment::GetSeqB()
{
    return SeqB;
}

bool Alignment::IsAligned()
{
    return isAligned;
}

void Alignment::SetScore(int score_in)
{
    this->score = score_in;
}

int Alignment::GetScore()
{
    return this->score;
}
