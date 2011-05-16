/**
 *	@file	Scoring.h
 *  @class  Scoring
 *	@brief	Static functions to score two sequences
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#include <string>

#ifndef _SCORING_H
#define _SCORING_H

using namespace std;

class Scoring
{
    public:
		static void GetDefaultMatrix(int scoreMatrix[4][4]);
		static void GetDefaultPenalty(int &penalty);
        static int Score (char a, char b, int scoreMatrix[4][4], int penalty);
        static int GetMatrixValue(char ACGT);
        static void PrintMatrix(int scoreMatrix[4][4]);
        static int ScoreStrings(string a, string b, int scoreMatrix[4][4], int penalty);
        static void GetSWMatrix(int scoreMatrix[4][4]);
};

#endif /* _SCORING_H */
