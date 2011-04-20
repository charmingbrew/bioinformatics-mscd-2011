/**
 *  @file   Alignment.cpp
 *  @brief  A class for aligning Sequences
 *  @author Tony Do,
 *          Dane Elshof,
 *          Jonathan Nicholson,
 *          Dan Thode
 *  @date   20 April 2011
 */

#include "Alignment.h"
#include <string>
#include <iostream>
using namespace std;

int Alignment::Match(string A, string B)
{
    int score = 0;
    for (int i = 0; i < A.length() && B.length(); i++ ) {
        if (A[i] == B[i]) score += 2;
        else score -= 1;
    }
    return score;
}

int main ()
{
    cout << "Testing a simple (and stupid) algorithm for two strings" << endl;
    int score;
    Alignment *a = new Alignment();
    score = a->Match("Hello World", "Hello Moon");
    cout << score << endl;
}
