/**
 *  @file   Tree.h
 *  @class  Tree
 *  @brief  Pylogenetic Tree used by Multiple Sequence
 *          Alignment.
 *          The data structure for this phylogenetic tree is a
 *          sudo-binary tree that grows from the root up. The sudo
 *          in front of binary means that the tree initially starts as
 *          a vector of roots, containing unaligned sequences, then all
 *          roots combine into one binary tree.
 *  @see    Node
 *  @see    Tub
 *          A phylogenetic tree follows these rules:
 *              -# Nodes added to the tree are inserted in order based
 *                  on the MSA algorithms
 *              -# A tree grows from left to right.
 */

#ifndef _TREE_H
#define _TREE_H

#include "Node.h"
#include "Alignment.h"
#include "Tub.h"

class Tree
{
    private:
        vector<Node *> roots;
        string ToNewick(Node *n);
        string ToNewick(Node *n, string &s);
    public:
        /// Only Constructor, for control of inputs.
        Tree();
        /**
         * Handles the growth of the tree.
         * @param t Container adds new Nodes to the tree
         */
        void Add(Tub *t);
        /**
         *  Allows the tree to be seen visually
         *  @return Tree structure in Newick format.
         */
        string ToNewick();
};

#endif // _TREE_H
