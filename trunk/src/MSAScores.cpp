#include "MSAScores.h"

MSAScores::MSAScores()
{
    this->d_score = 0;
    this->q_score = 0;
}

double MSAScores::GetDscore()
{
    return this->d_score;
}

double MSAScores::GetQscore()
{
    return this->q_score;
}

void MSAScores::SetDscore(double num_in)
{
    this->d_score = num_in;
}

void MSAScores::SetQscore(double num_in)
{
    this->q_score = num_in;
}
