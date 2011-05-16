/**
 *	@file	Module.h
 *	@brief	A wrapper for SWIG, so that we dont have to make modules for every single associated class
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#include "Tree.h"
#include "Sequence.h"
#include <vector>
#include <string>
#include "Node.h"

Tree::Tree()
{

}

/*
 *  Because the tree gets alignments in order, we can
 *  set all Alignments on the Left of each
 *  branch of the tree. If there already exists an
 *  alignment on the left it moves to the right. This
 *  allows the tree to traverse in-order (left, right, middle).
 */
void Tree::Add(Tub *t)
{
    // ID for the new node being created
    int newnode = t->GetID();
    // ID for the node that needs to be aligned with
    int rootnumber = t->GetCompare();
    Sequence *left = t->GetLeftSeq();
    Sequence *right = t->GetRightSeq();

    /*
     *  IF the rootnumber is not assigned, it means that it is a new
     *  alignment between to sequences and has no other alignment.
     *  e.g. Seq A & Seq B become  Alignment AB
     */
    if(rootnumber < 0 ) {
        roots.push_back(new Node(left, right, newnode));
    }
    /*
     *  IF Both Seq's are empty, that means two seperate alignments
     *  are being aligned.
     *  e.g. Align AB & Align CD become ABCD
     */
    else if(left == NULL && right == NULL) {
        Node *destination, *mover;

        for(int i = 0; i < roots.size(); i++) {
            if(newnode == roots[i]->GetID()) {
                mover = roots[i];
                roots.erase(roots.begin()+i);
            }
            if(rootnumber == roots[i]->GetID()) {
                destination = roots[i];
            }
        }
        if(destination->isAlignment())
            destination = new Node(destination, mover);
        else
            destination->SetRight(mover);
    }
    /*
     *  IF the left is empty and the right is not, this means that
     *  an single sequence is being aligned with another Alignment.
     *  e.g. Seq C & Align AB become ABC
     */
    else if(left == NULL && right != NULL) {
        Node *destination;
        Node *newseq = new Node(right, newnode);
        for(int i = 0; i < roots.size(); i++) {
            if(rootnumber == roots[i]->GetID()) {
                destination = roots[i];
            }
        }
        if(destination->isAlignment())
            destination = new Node(destination, newseq);
        else
            destination->SetRight(newseq);
    }
}

//Recursive traversal through the tree to create the phylogeny tree helper call
string Tree::ToNewick()
{
    return ToNewick(roots[0]) + ";";
}
//Second helper call.
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
    else if(n->GetLeftSequence() == NULL) {
        s += "," + ToNewick(n->GetRightNode());
    }
    else {
        if(n->GetLeftSequence() != NULL) {
            s +=  n->GetLeftSequence()->GetName();
        }
        if(n->GetRightSequence() != NULL) {
            s += "," + n->GetRightSequence()->GetName();
        }
    }
    return s;
}
