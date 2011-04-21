#ifndef _SCORING_H
#define _SCORING_H

#include <string>
using namespace std;

class Scoring
{
    private:
		int scoreMatrix[4][4];
    public:
        Scoring(int match, int miss);
        int Score (char a, char b);
        int GetMatrixValue(char ACGT);
};

#endif /* _SCORING_H */
