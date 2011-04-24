#ifndef _SCORING_H
#define _SCORING_H

#include <string>
#include "Alignment.h"
using namespace std;

class Scoring
{
    private:
		int scoreMatrix[4][4];
		int penalty;
    public:
        Scoring(int match, int miss);
        Scoring();
        int Score (char a, char b);
        int GetMatrixValue(char ACGT);
        void PrintMatrix();
        int ScoreStrings(string a, string b);
        void ScoreStrings(Alignment &align_in);
        int GetPenalty();
};

#endif /* _SCORING_H */
