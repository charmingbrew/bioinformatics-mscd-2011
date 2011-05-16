#include "Node.h"

Node::Node()
{
    this->left = new Direction();
    this->right = new Direction();
    this->ID = -1;
}

Node::Node(Sequence *s, int ID)
{
    this->left = new Direction();
    this->right = new Direction(s);
    this->ID = ID;
}

Node::Node(Node *l, Node *r)
{
    this->ID = l->GetID();
    this->left = new Direction(l);
    this->right = new Direction(r);
}

bool Node::isAlignment()
{
    return (!right->isOpen() && !left->isOpen());
}

Node::Node(Sequence *a, Sequence *b, int ID)
{
    this->ID = ID;
    this->left = new Direction(a);
    this->right = new Direction(b);
}


Node *Node::GetLeftNode()
{
    return this->GetNode(this->left);
}

Node *Node::GetRightNode()
{
    return this->GetNode(this->right);
}

Node *Node::GetNode(Direction *d)
{
    return d->GetNode();
}

void Node::SetLeftSequence(Sequence *seq)
{
    this->SetSequence(this->left, seq);
}

void Node::SetRightSequence(Sequence *seq)
{
    this->SetSequence(this->right, seq);
}

Sequence *Node::GetLeftSequence()
{
    return this->GetSequence(this->left);
}

Sequence *Node::GetRightSequence()
{
    return this->GetSequence(this->right);
}

Sequence *Node::GetSequence(Direction *d)
{
    return d->GetSequence();
}
void Node::SetSequence(Direction *d, Sequence *s)
{
    d->SetSequence(s);
}

void Node::SetLeft(Node *node)
{
    this->SetNode(this->left, node);
}

void Node::SetRight(Node *node)
{
    this->SetNode(this->right, node);
}

void Node::SetNode(Direction *d, Node *n)
{
    d->SetNextNode(n);
}

int Node::GetID()
{
    return this->ID;
}
