#ifndef _NODE_H
#define _NODE_H

#include "Sequence.h"
#include "Direction.h"

class Node
{
    private:
        Direction *left, *right;
        int ID;
        void SetSequence(Direction *d, Sequence *seq);
        Sequence * GetSequence(Direction *d, Sequence *seq);
        void SetNode(Direction *d, Node *n);
        Node *GetNode(Direction *d);
    public:
        Node(Sequence *s, int ID);
        Node(Sequence *a, Sequence *b, int ID);
        Node(int ID);
        Node();
        Node(Node *older, Node *newer);
        bool isAlignment();
        int GetID();
        Sequence *GetLeftSequence();
        Sequence *GetRightSequence();
        void SetLeftSequence(Sequence *seq);
        void SetRightSequence(Sequence *seq);
        Node *GetLeftNode();
        Node *GetRightNode();
        void SetRight(Node *n);
        void SetLeft(Node *n);
};

#endif // _NODE_H
