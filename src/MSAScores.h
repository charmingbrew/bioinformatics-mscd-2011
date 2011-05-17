#ifndef _MSASCORES_H
#define _MSASCORES_H

class MSAScores
{
    private:
        double d_score, q_score;
    public:
        MSAScores();

        double GetDscore();
        double GetQscore();

        void SetDscore(double num_in);
        void SetQscore(double num_in);
};

#endif
