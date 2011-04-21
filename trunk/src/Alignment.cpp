/**
 *  @file   Alignment.cpp
 *  @brief  A class for aligning Sequences
            Class creates a Matrix based on a the
            Scoring class and find the most absolute
            path through that Matrix to create the best
            match possible.
            Thank you Needleman-Wunsch for your great work:
            <http://en.wikipedia.org/wiki/Needleman-Wunsch_algorithm>
    @see    Scoring.cpp
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

int Alignment::CreateMatrix(string A, string B)

int Alignment::Align(string A, string B)
{
    int i = A.length();
    int j = B.length();
  while (i > 0 and j > 0)
  {
    Score ← F(i,j)
    ScoreDiag ← F(i - 1, j - 1)
    ScoreUp ← F(i, j - 1)
    ScoreLeft ← F(i - 1, j)
    if (Score == ScoreDiag + S(Ai, Bj))
    {
      AlignmentA ← Ai + AlignmentA
      AlignmentB ← Bj + AlignmentB
      i ← i - 1
      j ← j - 1
    }
    else if (Score == ScoreLeft + d)
    {
      AlignmentA ← Ai + AlignmentA
      AlignmentB ← "-" + AlignmentB
      i ← i - 1
    }
    otherwise (Score == ScoreUp + d)
    {
      AlignmentA ← "-" + AlignmentA
      AlignmentB ← Bj + AlignmentB
      j ← j - 1
    }
  }
  while (i > 0)
  {
    AlignmentA ← Ai + AlignmentA
    AlignmentB ← "-" + AlignmentB
    i ← i - 1
  }
  while (j > 0)
  {
    AlignmentA ← "-" + AlignmentA
    AlignmentB ← Bj + AlignmentB
    j ← j - 1
  }
}
