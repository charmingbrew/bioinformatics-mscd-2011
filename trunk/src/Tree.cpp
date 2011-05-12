#include "Tree.h"
#include "Sequence.h"
#include <vector>

Tree::Tree()
{
    roots = new vector<Node *>();
}

/**
 *  We want Alignments to be set on the Left of each
 *  branch of the tree, unless it already exists. Then
 *
 */
void Tree::Add(Tub *t)
{
    int newnode = t->GetID();
    int rootnumber = t->GetCompare();
    Sequence *left = t->GetLeftSeq();
    Sequence *right = t->GetRightSeq();

    if(rootnumber < 0 ) {
        roots->push_back(new Node(left, right, newnode));
    }
    else if(left == NULL && right == NULL) {
        Node *destination, *mover;
        for(int i = 0; i < roots->size(); i++) {
            if(newnode == roots[i]->GetID()) {
                mover = roots[i];
                roots->erase(roots.begin()+i);
            }
            if(rootnumber == roots[i]->GetCompare()) {
                destination = roots[i];
            }
        }
        if(destination->isAlignment())
            destination = new Node(destination, mover);
        else
            destination->SetRight(mover);
    }
    else if(left == NULL && right != NULL) {
        Node *destination;
        Node *newseq = new Node(right, newnode);
        for(int i = 0; i < roots->size(); i++) {
            if(rootnumber == roots[i]->GetCompare()) {
                destination = roots[i];
            }
        }
        if(destination->isAlignment())
            destination = new Node(destination, mover);
        else
            destination->SetRight(mover);
    }
}

string Tree::ToNewick()
{
    return ToNewick(roots[0]) + ";";
}

string Tree::ToNewick(Node *n)
{
    string newick = "";
    return "(" + ToNewick(n, newick) + ")";
}

string Tree::ToNewick(Node *n, string &s)
{
    if(n->GetLeftSequence() == NULL) {
        s += ToNewick(n->GetLeftNode());
    }
    else if(n->GetRightSequence() == NULL) {
        s += "," ToNewick(n->GetRightNode());
    }
    else {
        if(n->GetLeftSequence() != NULL) {
            s +=  n->GetLeftSequence()->GetName();
        }
        if(n->GetRightSequence() != NULL) {
            s += "," n->GetRightSequence()->GetName();
        }
        return s
    }
}
