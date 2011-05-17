#ifndef _MSASCORES_H
#define _MSASCORES_H

class MSAScores
{
    private:
        double d_score, q_score;
    public:
        /**
         * Default constructor
         */
        MSAScores();

        /**
         * Returns the Dscore
         */
        double GetDscore();
        /**
         * Returns the Qscore
         */
        double GetQscore();

        /**
         * Sets the Dscore
         * @param num_in The number to set the d score to
         */
        void SetDscore(double num_in);
        /**
         * Sets the Qscore
         * @param num_in The number to set the q score to
         */
        void SetQscore(double num_in);
};

#endif
