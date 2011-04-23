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
#include "Scoring.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
 *  Creates a matrix of all allignments that are
 *  possible and diagnalizes the best alignment in
 *  comparison of both strings.
 *  @todo REMOVE PRINTING.
 */
void Alignment::CreateMatrix(string A, string B)
{
    int penalty = -2;
    Scoring *score = new Scoring(2,-1);
    AlignmentMatrix.resize(A.length(), vector<int>(B.length()) );
    for (int a = 0; a < A.length(); a++)
        AlignmentMatrix[a][0] = penalty * a;
    for (int b = 0; b < B.length(); b++)
        AlignmentMatrix[0][b] = penalty * b;
    for (int i = 1; i < A.length(); i++) {
        for (int j = 1; j < B.length(); j++) {
            int match = AlignmentMatrix[i-1][j-1] + score->Score(A[i],B[j]);
            int deleted = AlignmentMatrix[i-1][j] + penalty;
            int insert = AlignmentMatrix[i][j-1] + penalty;
            AlignmentMatrix[i][j] = MaxScore(match, deleted, insert);
        }
    }

    for(int k = 0; k < A.length(); k++) {
        for (int l = 0; l < B.length(); l++) {
            cout << AlignmentMatrix[k][l] << " ";
        }
        cout << endl;
    }
}

/**
 *  Compares the three integers and returns the largest.
 *  @param match A direct match up with a letter.
 *  @param deleted Top string is alligned with a gap
 *  @param insert Bottom string is aligned with a gap
 *  @return the higest score of the three in an alignment matrix.
 */
int Alignment::MaxScore(int match, int deleted, int insert)
{
    if (match > deleted) {
        if (match > insert)
            return match;
        return insert;
    } else if (deleted > match) {
        if (deleted > insert)
            return deleted;
        return insert;
    }
}

/**
 *  Beginning stub for the alignment method.
 *  @todo Matches up Alignments into AlignedSequence A and B
 */
int Alignment::Align(string A, string B)
{
    //TODO: SUBCLASS SCORE AND PUT PENALTY IN THE CONSTRUCTOR
    Scoring *s = new Scoring(2,-1);
    int penalty = -2;
    CreateMatrix(A, B);
    string alignment_a = "";
    string alignment_b = "";
    int i = A.length()-1;
    int j = B.length()-1;
    while (i > 0 && j > 0) {
        int score = AlignmentMatrix[i][j];
        int score_diag = AlignmentMatrix[i - 1][j - 1];
        int score_up = AlignmentMatrix[i][j-1];
        int score_left = AlignmentMatrix[i-1][j];
        if (score == score_diag + s->Score(A[i], B[j])) {
            alignment_a = A[i] + alignment_a;
            alignment_b = B[j] + alignment_b;
            --i;
            --j;
        } else if (score == score_left + penalty) {
            alignment_a = A[i] + alignment_a;
            alignment_b = "-" + alignment_b;
            --i;
        } else if (score == score_up + penalty) {
            alignment_a = "-" + alignment_a;
            alignment_b = B[j] + alignment_b;
            --j;
        }
    }
    while (i > 0) {
        alignment_a = A[i] + alignment_a;
        alignment_b = "-" + alignment_b;
        --i;
    }
    while (j > 0) {
        alignment_a = "-" + alignment_a;
        alignment_b = B[j] + alignment_b;
        --j;
    }

    cout << alignment_a << endl;
    cout << alignment_b << endl;
}

int main () {
    Alignment *A = new Alignment();
    A->Align("GAAGTATACCTATGGGACCTAGG", "TATAAGACAAGCACAT");
    return 0;
}
