#include "Tub.h"

Tub::Tub(Sequence *seq_in)
{
    this->left = seq_in;
    this->right = NULL;
    this->self_id = 0;
    this->compare_id = -1;
}

Tub::~Tub()
{

}

int Tub::GetID()
{
    return this->self_id;
}

void Tub::SetID(int id_in)
{
    this->self_id = id_in;
}

int Tub::GetCompare()
{
    return this->compare_id;
}

void Tub::SetCompare(int compare_in)
{
    this->compare_id = compare_in;
}

Sequence *Tub::GetLeftSeq()
{
    return this->left;
}

Sequence *Tub::GetRightSeq()
{
    return this->right;
}

void Tub::SetLeftSeq(Sequence *seq_in)
{
    this->left = seq_in;
}

void Tub::SetRightSeq(Sequence *seq_in)
{
    this->right = seq_in;
}

void Tub::ClearSeqs()
{
    this->left = NULL;
    this->right = NULL;
}

void Tub::FlipSeqs()
{
    this->right = this->left;
    this->left = NULL;
}

void Tub::SetAlignScore(int index, double num_in)
{
    if(this->align_scores.size() >= index)
    {
        align_scores.push_back(num_in);
    }
    else
        this->align_scores[index] = num_in;
}

double Tub::GetAlignScore(int index)
{
    return this->align_scores[index];
}

int Tub::GetAlignScoreLength()
{
    return this->align_scores.size();
}

void Tub::SetQScore(int index, double num_in)
{
    if(this->q_scores.size() >= index)
        q_scores.push_back(num_in);
    else
        this->q_scores[index] = num_in;
}

double Tub::GetQScore(int index)
{
    return this->q_scores[index];
}

void Tub::AddToMSA(int add)
{
    this->msa_score += add;
}

void Tub::CalcMSA(int divisor)
{
    this->msa_score = this->msa_score / divisor;
}

double Tub::GetMSA()
{
    return this->msa_score;
}

void Tub::SetVecPos(int index)
{
    this->vector_pos = index;
}

bool Tub::HasLeft()
{
    return this->GetLeftSeq() != NULL;
}

bool Tub::HasRight()
{
    return this->GetRightSeq() != NULL;
}

bool Tub::HasBoth()
{
    return HasRight() && HasLeft();
}

void Tub::SetOldA(Tub *tub_in)
{
    this->old_scores_a = tub_in->align_scores;
}

void Tub::SetOldB(Tub *tub_in)
{
    this->old_scores_b = tub_in->align_scores;
}

double Tub::GetOldA(int index)
{
    return this->old_scores_a[index];
}

double Tub::GetOldB(int index)
{
    return this->old_scores_b[index];
}

void Tub::Combine(Tub *tub_in, int pos)
{
    tub_in->align_scores.erase(tub_in->align_scores.begin() + pos);
    this->align_scores.erase(this->align_scores.begin() + pos);
    this->SetOldA(this);
    this->SetOldB(tub_in);
    //this->old_scores_a.erase(old_scores_a.begin() + pos);
    //this->old_scores_b.erase(old_scores_b.begin() + pos);
}
