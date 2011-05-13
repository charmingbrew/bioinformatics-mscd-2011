#ifndef _TUB_H
#define _TUB_H

#include <vector>
#include "Sequence.h"

class Tub
{
    private:
        int self_id, compare_id, vector_pos;
        Sequence *left, *right;
        vector<double> align_scores;
        vector<double> q_scores;
        double msa_score;
    public:
        Tub(Sequence *seq_in);
        ~Tub();

        int GetID();
        void SetID(int id_in);
        int GetCompare();
        void SetCompare(int compare_in);

        Sequence *GetLeftSeq();
        Sequence *GetRightSeq();
        void SetLeftSeq(Sequence *seq_in);
        void SetRightSeq(Sequence *seq_in);
        void ClearSeqs();
        void FlipSeqs();

        void SetAlignScore(int index, double num_in);
        double GetAlignScore(int index);
        int GetAlignScoreLength();

        void SetQScore(int index, double num_in);
        double GetQScore(int index);

        void AddToMSA(int add);
        void CalcMSA(int divisor);
        double GetMSA();

        void SetVecPos(int index);

        bool HasLeft();
        bool HasRight();
        bool HasBoth();
};

#endif
