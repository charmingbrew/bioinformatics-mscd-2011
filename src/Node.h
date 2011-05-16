/**
 *  @file   Node.h
 *  @class  Node
 *  @brief  Node of a Phylogenetic Tree.
 *          This class handles all Node creation, Getters and Setters
 *          and handles placing Sequences and other Nodes.
 *          The class contains two Direction objects and an ID for
 *          keeping track of Nodes in the tree.
 *  @see    Direction
 */

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
        Sequence * GetSequence(Direction *d);
        void SetNode(Direction *d, Node *n);
        Node *GetNode(Direction *d);
    public:
        /// Default Constructor
        Node();
        /**
         *  Creates a Node with only a single sequence
         *  and assigns to the right.
         */
        Node(Sequence *s, int ID);
        /**
         *  Creates a new Alignment between two sequences.
         *  This is a full Node and cannot be changed.
         */
        Node(Sequence *a, Sequence *b, int ID);
        /**
         *  Creates an Alignment between two existing Nodes.
         */
        Node(Node *older, Node *newer);
        /**
         *  Checks if the current is complete
         *  @return true if the Node is full
         */
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
