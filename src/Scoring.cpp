/**
 * @file Scoring.cpp
 */
#include <iostream>
#include <string>
#include "Scoring.h"

using namespace std;

void Scoring::GetDefaultMatrix(int scoreMatrix[4][4])
{
    scoreMatrix[0][0] = 10;
    scoreMatrix[0][1] = -1;
    scoreMatrix[0][2] = -3;
    scoreMatrix[0][3] = -4;
    scoreMatrix[1][0] = -1;
    scoreMatrix[1][1] = 7;
    scoreMatrix[1][2] = -5;
    scoreMatrix[1][3] = -3;
    scoreMatrix[2][0] = -3;
    scoreMatrix[2][1] = -5;
    scoreMatrix[2][2] = 9;
    scoreMatrix[2][3] = 0;
    scoreMatrix[3][0] = -4;
    scoreMatrix[3][1] = -3;
    scoreMatrix[3][2] = 0;
    scoreMatrix[3][3] = 8;
}

void Scoring::GetSWMatrix(int scoreMatrix[4][4])
{
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j)
                scoreMatrix[i][j] = 2;
            else
                scoreMatrix[i][j] = -1;
        }
    }
}

void Scoring::GetDefaultPenalty(int &penalty)
{
	penalty = -5;
}

/**
 * @brief Currently under Development
 * Computes the alignment score of two strings of equal length.
 * Does NOT provide a way to add gap penalties.
 * TODO: Reimplement for chars only so the Alignment class can
 *      use to create pairs.
 */
int Scoring::Score(char a, char b, int scoreMatrix[4][4], int penalty)
{
    if(GetMatrixValue(a) == -1 || GetMatrixValue(b) == -1)
        return penalty;
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
    else return -1;
}

void Scoring::PrintMatrix(int scoreMatrix[4][4])
{
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << scoreMatrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

/**
 * Compares to strings and returns a score
 * Both strings HAVE to be the same length
 */
int Scoring::ScoreStrings(string a, string b, int scoreMatrix[4][4], int penalty)
{
    int length;
    int total = 0;

    if(a.length() != b.length())
        return -1;
    length = a.length();

    for(int i = 0; i < length; i++) {
        total += Score(a.at(i), b.at(i), scoreMatrix, penalty);
    }

    return total;
}
