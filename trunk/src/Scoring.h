#include <string>

#ifndef _SCORING_H
#define _SCORING_H

using namespace std;

class Scoring
{
    public:
		static void GetDefaultMatrix(int scoreMatrix[4][4]);
		static void GetDefaultPenalty(int *penalty);
        static int Score (char a, char b, int scoreMatrix[4][4], int penalty);
        static int GetMatrixValue(char ACGT);
        static void PrintMatrix(int scoreMatrix[4][4]);
        static int ScoreStrings(string a, string b, int scoreMatrix[4][4], int penalty);
};

#endif /* _SCORING_H */
