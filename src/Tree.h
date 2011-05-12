#ifndef _TREE_H
#define _TREE_H

#include "Node.h"
#include "Alignment.h"
#include "Tub.h"

class Tree
{
    private:
        vector<Node *> *roots;
        string ToNewick(Node *n);
        string ToNewick(Node *n, string s);
    public:
        Tree();
        void Add(Tub *t);
        string ToNewick();
};

#endif // _TREE_H
