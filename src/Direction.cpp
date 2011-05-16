#include "Direction.h"
#include "Sequence.h"

Direction::Direction()
{
    this->next = NULL;
    this->seq = NULL;
}

Direction::Direction(Sequence *seq)
{
    this->next = NULL;
    this->seq = seq;
}

Node *Direction::GetNode() {
    return this->next;
}

Direction::Direction(Node *next)
{
    this->next = next;
    this->seq = NULL;
}

void Direction::SetSequence(Sequence *seq)
{
    this->seq = seq;
    this->next = NULL;
}

void Direction::SetNextNode(Node *next)
{
    this->next = next;
    this->seq = NULL;
}

bool Direction::isOpen()
{
    return (this->next == NULL && this->seq == NULL);
}

Sequence *Direction::GetSequence()
{
    return this->seq;
}
