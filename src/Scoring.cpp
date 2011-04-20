/**
 * @file Scoring.cpp
 */
#include <iostream>
#include <string>
#include "Scoring.h"

using namespace std;

int Scoring::Score(string A, string B)
{
    int score = 0;
    for (int i = 0; i < A.length(); i++ ) {
        if (A[i] == B[i])
            score += 2;
        else
            score -= 1;
    }
    return score;
}

int main ()
{
    cout << "Testing a simple score for two strings" << endl;
    int score;
    Scoring *s = new Scoring();
    score = s->Score("Hello World", "Hello Moon");
    cout << score << endl;
}
