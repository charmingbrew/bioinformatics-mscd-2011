#include "Alignment.h"

class Node
{
    private:
        Alignment *left, *right;
        Node *nodeleft, *noderight;
    public:
        Node(Alignment &one, Alignment &two);
        Node();
        Alignment *GetLeftAlign();
        Alignment *GetRightAlign();
        void SetLeftAlign(Alignment &align_in);
        void SetRightAlign(Alignment &align_in);
        Node *GetLeftNode();
        Node *GetRightNode();
        void SetRightNode(Node &node_in);
        void SetLeftNode(Node &node_in);
};
