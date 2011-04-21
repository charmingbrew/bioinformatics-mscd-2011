/**
 * @file Scoring.cpp
 */
#include <iostream>
#include <string>
#include "Scoring.h"

using namespace std;

/**
 * Constructor that allows different scores for score matrix.
 *
 */
Scoring::Scoring(int match, int miss)
{
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++ ) {
            if(i == j) scoreMatrix[i][j] = match;
            else scoreMatrix[i][j] = miss;
        }
    }
}

/**
 * @brief Currently under Development
 * Computes the alignment score of two strings of equal length.
 * Does NOT provide a way to add gap penalties.
 * TODO: Reimplement for chars only so the Alignment class can
 *      use to create pairs.
 */
int Scoring::Score(char a, char b)
{
    return scoreMatrix[GetMatrixValue(a)][GetMatrixValue(b)];
}

/**
 *  Returns a index position for a specific character
 *  for the scoreMatrix.
 *  TODO: BITPACK: if ( A = 0001, C = 0010, G = 0100, T = 1000 )
 *          and we ACGT%5, we get the right index.
 *                   A % 5 = 1
 *                   C % 5 = 2
 *                   G % 5 = 4
 *                   T % 5 = 3
 *  @param ACGT The characer 'A', 'C', 'G', or 'T'
 *  @return the paramater's index position in the array.
 */
int Scoring::GetMatrixValue(char ACGT)
{
    if (ACGT == 'A') return 0;
    else if (ACGT == 'C') return 1;
    else if (ACGT == 'G') return 2;
    else if (ACGT == 'T') return 3;
}
