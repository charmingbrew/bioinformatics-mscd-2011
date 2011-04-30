#include "Node.h"

Node::Node()
{
    left = right = NULL;
    nodeleft = noderight = NULL;
}

Node::Node(Alignment &one, Alignment &two)
{
    left = &one;
    right = &two;
}

Alignment *Node::GetLeftAlign()
{
    return left;
}

Alignment *Node::GetRightAlign()
{
    return right;
}

void Node::SetLeftAlign(Alignment &align_in)
{
    left = &align_in;
}

void Node::SetRightAlign(Alignment &align_in)
{
    right = &align_in;
}

Node *Node::GetLeftNode()
{
    return nodeleft;
}

Node *Node::GetRightNode()
{
    return noderight;
}

void Node::SetRightNode(Node &node_in)
{
    noderight = &node_in;
}

void Node::SetLeftNode(Node &node_in)
{
    nodeleft = &node_in;
}
