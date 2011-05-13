#include "Writer.h"
#include "MSA.h"
#include "Sequence.h"
#include <vector>
#include "Tree.h"
#include "Alignment.h"

MSA::MSA()
{
    this->score = 0;
}

void MSA::NeighborJoin(vector<Sequence *> seqvector, bool align_nw)
{
    vector<Tub *> tubvector;
    Tub *temp;
    Tree *thetree = new Tree();
    int current_id = 1;

    for(int i = 0; i < seqvector.size(); i++) {
        temp = new Tub(seqvector[i]);
        tubvector.push_back(temp);
        tubvector[i]->SetVecPos(i);
    }

    while(tubvector.size() > 2) {
        AlignSeqs(tubvector, align_nw);
        Qcalc(tubvector, thetree, current_id);
        current_id++;
    }

    this->newick = GetMSA(thetree);

}

void MSA::AlignSeqs(vector<Tub *> &tubvector, bool align_nw)
{
    int seq_align_index;

    for(int i = 0; i < tubvector.size() - 1; i++) {
        if(tubvector[i]->HasLeft())
            this->SetSeqA(tubvector[i]->GetLeftSeq()->GetSequence());
        seq_align_index = 0;

        for(int j = i + 1; j < tubvector.size(); j++) {
            this->SetSeqB(tubvector[j]->GetLeftSeq()->GetSequence());
            align_nw ? NWAlign() : SWAlign();

            tubvector[i]->SetAlignScore(seq_align_index, GetScore());

            tubvector[i]->AddToMSA(GetScore());
            tubvector[j]->AddToMSA(GetScore());

            seq_align_index++;
        }
    }
}

void MSA::Qcalc(vector<Tub *> &tubvector, Tree *phytree, int id)
{
    // store the index in the tub vector of the two tubs with the lowest q score
    int lowest_one, lowest_two;
    double lowest_score;
    int q_index;

    lowest_score = 1000000;

    for(int i = 0; i < tubvector.size() - 1; i++) {
        q_index = 0;

        for(int j = i + 1; j < tubvector[i]->GetAlignScoreLength(); j++) {
            // set q scores
            tubvector[i]->SetQScore(q_index, ((tubvector.size() - 2) * (tubvector[i]->GetAlignScore(q_index)) - tubvector[i]->GetMSA() - tubvector[j]->GetMSA()));

            if(tubvector[i]->GetQScore(q_index) < lowest_score) {
                lowest_one = i;
                lowest_two = j;
            }
            q_index++;
        }
    }

    QtoTree(lowest_one, lowest_two, tubvector, phytree, id);
}

void MSA::QtoTree(int atub, int btub, vector<Tub *> &tubvector, Tree *phytree, int id)
{
    // sequence to sequence
    if(tubvector[atub]->GetID() < 1 && tubvector[btub]->GetID() < 1) {
        tubvector[atub]->SetRightSeq(tubvector[btub]->GetLeftSeq());
        tubvector[atub]->SetID(id);

        delete tubvector[btub];
        tubvector.erase(tubvector.begin() + btub);

        phytree->Add(tubvector[atub]);

        tubvector[atub]->ClearSeqs();
    }
    // sequence to alignment
    else if((!tubvector[atub]->HasBoth() && tubvector[btub]->HasLeft()) || (!tubvector[btub]->HasBoth() && tubvector[atub]->HasLeft())) {
        if(!tubvector[atub]->HasBoth()) {
            tubvector[btub]->FlipSeqs();
            tubvector[btub]->SetID(id);
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            delete tubvector[btub];
            tubvector.erase(tubvector.begin() + btub);

            tubvector[atub]->ClearSeqs();
        }
        if(!tubvector[btub]->HasBoth()) {
            tubvector[atub]->FlipSeqs();
            tubvector[atub]->SetID(id);
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            delete tubvector[atub];
            tubvector.erase(tubvector.begin() + atub);

            tubvector[btub]->ClearSeqs();
        }
    }
    // alignment to alignment
    else {
        if(tubvector[atub]->GetID() < tubvector[btub]->GetID()) {
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            delete tubvector[btub];
            tubvector.erase(tubvector.begin() + btub);
        }
        else {
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[atub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            delete tubvector[atub];
            tubvector.erase(tubvector.begin() + atub);
        }
    }
}

string MSA::GetMSA(Tree *phytree)
{
    return phytree->ToNewick();
}

string MSA::GetNewick()
{
    return this->newick;
}
