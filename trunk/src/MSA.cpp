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
    int changed_index = 0;

    for(int i = 0; i < seqvector.size(); i++) {
        temp = new Tub(seqvector[i]);
        tubvector.push_back(temp);
    }

    this->score_matrix.resize(seqvector.size() + 1, vector<MSAScores>(seqvector.size() + 1));

    for(int i = 0; i < tubvector.size(); i++) {
        cout << i << " - " << tubvector[i]->GetLeftSeq()->GetName() << endl;
    }
    cout << endl;

    while(tubvector.size() > 1) {
        CreateD(tubvector, align_nw, changed_index);
        changed_index = Qcalc(tubvector, thetree, current_id);
        current_id++;
        cout << "tubvector length: " << tubvector.size() << endl;
        for(int i = 0; i < tubvector.size(); i++) {
            cout << i << " - " << tubvector[i]->GetLeftSeq()->GetName() << endl;
        }
        cout << endl;
    }

    this->newick = GetMSA(thetree);

}

void MSA::CreateD(vector<Tub *> &tubvector, bool align_nw, int index)
{
    // only one row/column changes every loop after the initial dmatrix is built
    if(index > 0) {
        for(int i = 0; i < tubvector.size() - 1; i++) {
            // don't calculate a tub vs itself
            if(i == index)
                continue;
            else {
                // tubvector[index] will always be an alignment
                this->SetSeqA("");
                if(tubvector[i]->HasLeft())
                    this->SetSeqB(tubvector[i]->GetLeftSeq()->GetSequence());
                else
                    this->SetSeqB("");

                tubvector[i]->SubtractFromMSA(score_matrix[tubvector[index]->GetOldPosA()][i].GetDscore());
                tubvector[i]->SubtractFromMSA(score_matrix[tubvector[index]->GetOldPosB()][i].GetDscore());
                AlignDCalc(tubvector, index, i);
                tubvector[index]->AddToMSA(GetScore());
                tubvector[i]->AddToMSA(GetScore());
            }
        }
        cout << "Matrix:" << endl;
        for(int i = 0; i < score_matrix.size(); i++) {
            for(int j = 0; j < score_matrix[0].size(); j++) {
                cout << score_matrix[i][j].GetDscore() << "  ";
                if(score_matrix[i][j].GetDscore() == 0)
                    cout << "   ";
            }
            cout << endl;
        }
    }
    else {
        for(int i = 0; i < tubvector.size() - 1; i++) {
            if(tubvector[i]->HasLeft())
                this->SetSeqA(tubvector[i]->GetLeftSeq()->GetSequence());
            else
                this->SetSeqA("");

            for(int j = i + 1; j < tubvector.size(); j++) {
                if(tubvector[j]->HasLeft())
                    this->SetSeqB(tubvector[j]->GetLeftSeq()->GetSequence());
                else
                    this->SetSeqB("");

                if(this->GetSeqA().size() != 0 && this->GetSeqB().size() != 0) {
                    align_nw ? NWAlign() : SWAlign();
                    this->score_matrix[i][j].SetDscore(this->GetScore());
                    this->score_matrix[j][i].SetDscore(this->GetScore());
                }
                else
                    AlignDCalc(tubvector, i, j);

                tubvector[i]->AddToMSA(GetScore());
                tubvector[j]->AddToMSA(GetScore());
            }
        }
        cout << "initial dmatrix: " << endl;
        for(int i = 0; i < score_matrix.size(); i++) {
            for(int j = 0; j < score_matrix[0].size(); j++) {
                cout << score_matrix[i][j].GetDscore() << "  ";
                if(score_matrix[i][j].GetDscore() == 0)
                    cout << "   ";
            }
            cout << endl;
        }
    }
}

void MSA::AlignDCalc(vector<Tub *> &tubvector, int aindex, int bindex)
{
    double temp;

    // tubvector[aindex] is an alignment and tubvector[bindex] is a sequence
    if(!tubvector[aindex]->HasLeft() && tubvector[bindex]->HasLeft()) {
        temp = (1 / 2) * (score_matrix[tubvector[aindex]->GetOldPosA()][bindex].GetDscore() + score_matrix[tubvector[aindex]->GetOldPosB()][bindex].GetDscore() -
                          score_matrix[tubvector[aindex]->GetOldPosA()][tubvector[aindex]->GetOldPosB()].GetDscore());
    }
    // tubvector[bindex] is an alignment and tubvector[aindex] is a sequence
    else if(!tubvector[bindex]->HasLeft() && tubvector[aindex]->HasLeft()) {
        temp = (1 / 1) * (score_matrix[tubvector[bindex]->GetOldPosA()][aindex].GetDscore() + score_matrix[tubvector[bindex]->GetOldPosB()][aindex].GetDscore() -
                          score_matrix[tubvector[bindex]->GetOldPosA()][tubvector[bindex]->GetOldPosB()].GetDscore());
    }
    // both tubvector indeces are alignments
    // only the most recent alignment will have access to its previous d scores, and will be used for the calculation
    // this is probably wrong as there are number that can possibly be different in the calculation
    else {
        // if either of tubvector[aindex]'s old pos values is equal to the length of the tubvector, then this was the most recently created tub
        if(tubvector[aindex]->GetOldPosA() == tubvector.size() || tubvector[aindex]->GetOldPosB() == tubvector.size()) {
            temp = (1 / 2) * (score_matrix[tubvector[aindex]->GetOldPosA()][bindex].GetDscore() + score_matrix[tubvector[aindex]->GetOldPosB()][bindex].GetDscore() -
                                score_matrix[tubvector[aindex]->GetOldPosA()][tubvector[aindex]->GetOldPosB()].GetDscore());
        }
        // the above test should never fail now due to only one row/column being recalc'd every time
        // if the above test fails, then tubvector[bindex] was the most recently created
        else {
            temp = (1 / 2) * (score_matrix[tubvector[bindex]->GetOldPosA()][aindex].GetDscore() + score_matrix[tubvector[bindex]->GetOldPosB()][aindex].GetDscore() -
                                score_matrix[tubvector[bindex]->GetOldPosA()][tubvector[bindex]->GetOldPosB()].GetDscore());
        }
    }
    score_matrix[aindex][bindex].SetDscore(temp);
    score_matrix[bindex][aindex].SetDscore(temp);
}

int MSA::Qcalc(vector<Tub *> &tubvector, Tree *phytree, int id)
{
    int changed_index;
    // store the index in the tub vector of the two tubs with the lowest q score
    int lowest_one, lowest_two;
    double lowest_score, q_score;

    // initialize lowest_score to a number greater than any alignment should return
    // lowest_score will then be set to whatever the first alignment score is
    lowest_score = 1000000000;

    for(int i = 0; i < tubvector.size() - 1; i++) {
        for(int j = i + 1; j < tubvector.size(); j++) {
            // set q scores
            q_score = ((tubvector.size() - 2) * score_matrix[i][j].GetDscore()) - tubvector[i]->GetMSA() - tubvector[j]->GetMSA();
            score_matrix[i][j].SetQscore(q_score);
            score_matrix[j][i].SetQscore(q_score);

            if(q_score < lowest_score) {
                lowest_score = q_score;
                lowest_one = i;
                lowest_two = j;
            }
        }
    }
    cout << "Q Matrix:" << endl;
    for(int i = 0; i < score_matrix.size(); i++) {
        for(int j = 0; j < score_matrix[0].size(); j++) {
            cout << score_matrix[i][j].GetQscore() << " ";
            if(score_matrix[i][j].GetQscore() == 0)
                cout << "     ";
        }
        cout << endl;
    }

    changed_index = QtoTree(lowest_one, lowest_two, tubvector, phytree, id);
}

int MSA::QtoTree(int atub, int btub, vector<Tub *> &tubvector, Tree *phytree, int id)
{
    int changed_index;
    // sequence to sequence
    if(tubvector[atub]->GetID() < 1 && tubvector[btub]->GetID() < 1) {
        tubvector[atub]->SetRightSeq(tubvector[btub]->GetLeftSeq());
        tubvector[atub]->SetID(id);

        phytree->Add(tubvector[atub]);

        tubvector[atub]->ClearSeqs();

        cout << "joined tubvector positions: " << atub << "s : " << btub << "s" << endl;
        cout << "into new tub: " << tubvector[atub]->GetID() << endl << endl;

        RearrangeScoreMatrix(tubvector.size(), btub);

        tubvector.erase(tubvector.begin() + btub - 1);
        tubvector[atub]->SetOldPosA(atub);
        tubvector[atub]->SetOldPosB(tubvector.size());

        changed_index = atub;
    }
    // sequence to alignment
    else if((!tubvector[atub]->HasBoth() && tubvector[btub]->HasLeft()) || (!tubvector[btub]->HasBoth() && tubvector[atub]->HasLeft())) {
        if(!tubvector[atub]->HasBoth()) {
            tubvector[btub]->FlipSeqs();
            tubvector[btub]->SetID(id);
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << "a : " << tubvector[btub]->GetID() << "a" << endl;

            tubvector[atub]->ClearSeqs();

            RearrangeScoreMatrix(tubvector.size(), btub);

            tubvector.erase(tubvector.begin() + (btub - 1));
            tubvector[atub]->SetOldPosA(atub);
            tubvector[atub]->SetOldPosB(tubvector.size());

            changed_index = atub;
        }
        else {
            tubvector[atub]->FlipSeqs();
            tubvector[atub]->SetID(id);
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[btub]->GetID() << "a : " << tubvector[btub]->GetID() << "s" << endl;

            tubvector[btub]->ClearSeqs();

            RearrangeScoreMatrix(tubvector.size(), atub);

            tubvector.erase(tubvector.begin() + atub - 1);
            tubvector[btub]->SetOldPosA(btub);
            tubvector[btub]->SetOldPosB(tubvector.size());

            changed_index = btub;
        }
    }
    // alignment to alignment
    else {
        if(tubvector[atub]->GetID() < tubvector[btub]->GetID()) {
            tubvector[btub]->SetCompare(tubvector[atub]->GetID());

            phytree->Add(tubvector[btub]);

            cout << "joined " << tubvector[atub]->GetID() << "a : " << tubvector[btub]->GetID() << "a" << endl;

            RearrangeScoreMatrix(tubvector.size(), btub);

            tubvector.erase(tubvector.begin() + btub - 1);
            tubvector[atub]->SetOldPosA(atub);
            tubvector[atub]->SetOldPosB(tubvector.size());

            changed_index = atub;
        }
        else {
            tubvector[atub]->SetCompare(tubvector[btub]->GetID());

            phytree->Add(tubvector[atub]);

            cout << "joined " << tubvector[atub]->GetID() << "a : " << tubvector[btub]->GetID() << "a" << endl;

            RearrangeScoreMatrix(tubvector.size(), atub);

            tubvector.erase(tubvector.begin() + atub - 1);
            tubvector[btub]->SetOldPosA(btub);
            tubvector[btub]->SetOldPosB(tubvector.size());

            changed_index = btub;
        }
    }

    return changed_index;
}

string MSA::GetMSA(Tree *phytree)
{
    return phytree->ToNewick();
}

string MSA::GetNewick()
{
    return this->newick;
}

void MSA::RearrangeScoreMatrix(int size, int index)
{
    for(int i = 0; i < size; i++) {
        score_matrix[size - 1][i].SetDscore(score_matrix[index][i].GetDscore());
    }

    score_matrix.erase(score_matrix.begin() + index - 1);

    for(int i = 0; i < size; i++) {
        score_matrix[i].erase(score_matrix[i].begin() + index);
    }
}
