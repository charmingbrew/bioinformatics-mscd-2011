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
    for(int i = 0; i < tubvector.size() - 1; i++) {
        if(tubvector[i]->HasLeft())
            this->SetSeqA(tubvector[i]->GetLeftSeq()->GetSequence());
        else
            this->SetSeqA(NULL);
        tubvector[i]->SetAlignScore(i, 0); // Padding for alignment distance calcs

        for(int j = i + 1; j < tubvector.size(); j++) {
            if(tubvector[j]->HasLeft())
                this->SetSeqB(tubvector[j]->GetLeftSeq()->GetSequence());
            else
                this->SetSeqB(NULL);

            if(this->GetSeqA().size() == 0 && this->GetSeqB().size() == 0) {
                align_nw ? NWAlign() : SWAlign();
                tubvector[i]->SetAlignScore(j, GetScore());
                tubvector[j]->SetAlignScore(i, GetScore());
            }
            else {
                AlignDCalc(tubvector, i, j);
            }

            tubvector[i]->AddToMSA(GetScore());
            tubvector[j]->AddToMSA(GetScore());

            cout << "tubvector[" << i << "] vs [" << j << "]" << endl;
        }
    }
}

void MSA::AlignDCalc(vector<Tub *> &tubvector, int aindex, int bindex)
{
    double temp = (1/2)*(tubvector[aindex]->GetOldA(bindex) + tubvector[aindex]->GetOldB(bindex) - tubvector[aindex]->GetOldA(aindex));

    tubvector[aindex]->SetAlignScore(bindex, temp);
    tubvector[bindex]->SetAlignScore(aindex, temp);
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
    Tub *temp;
    // sequence to sequence
    if(tubvector[atub]->GetID() < 1 && tubvector[btub]->GetID() < 1) {
        tubvector[atub]->SetRightSeq(tubvector[btub]->GetLeftSeq());
        tubvector[atub]->SetID(id);

        phytree->Add(tubvector[atub]);

        tubvector[atub]->ClearSeqs();
        tubvector[atub]->Combine(tubvector[btub], btub);

        cout << "joined " << atub << " : " << btub << endl;

        tubvector.erase(tubvector.begin() + btub - 1);
    }
    // sequence to alignment
    else if((!tubvector[atub]->HasBoth() && tubvector[btub]->HasLeft()) || (!tubvector[btub]->HasBoth() && tubvector[atub]->HasLeft())) {
        if(!tubvector[atub]->HasBoth()) {
            tubvector[btub]->FlipSeqs();
            tubvector[btub]->SetID(id);
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            tubvector[atub]->ClearSeqs();
            tubvector[atub]->Combine(tubvector[btub], btub);

            tubvector.erase(tubvector.begin() + btub);
        }
        if(!tubvector[btub]->HasBoth()) {
            tubvector[atub]->FlipSeqs();
            tubvector[atub]->SetID(id);
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            tubvector[btub]->ClearSeqs();
            tubvector[btub]->Combine(tubvector[atub], atub);

            tubvector.erase(tubvector.begin() + atub);
        }
    }
    // alignment to alignment
    else {
        if(tubvector[atub]->GetID() < tubvector[btub]->GetID()) {
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            tubvector[atub]->Combine(tubvector[btub], btub);

            tubvector.erase(tubvector.begin() + btub);
        }
        else {
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[atub]);

            cout << "joined " << tubvector[atub]->GetID() << " : " << tubvector[btub]->GetID() << endl;

            tubvector[btub]->Combine(tubvector[atub], atub);

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
