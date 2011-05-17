#include "Tub.h"

Tub::Tub(Sequence *seq_in)
{
    this->left = seq_in;
    this->right = NULL;
    this->self_id = 0;
    this->compare_id = -1;
    this->msa_score = 0;
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

void Tub::AddToMSA(int add)
{
    this->msa_score += add;
}

void Tub::SubtractFromMSA(double sub)
{
    this->msa_score -= sub;
}

void Tub::CalcMSA(int divisor)
{
    this->msa_score = this->msa_score / divisor;
}

double Tub::GetMSA()
{
    return this->msa_score;
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

int Tub::GetOldPosA()
{
    return this->old_pos_a;
}

void Tub::SetOldPosA(int pos)
{
    this->old_pos_a = pos;
}

int Tub::GetOldPosB()
{
    return this->old_pos_b;
}

void Tub::SetOldPosB(int pos)
{
    this->old_pos_b = pos;
}
