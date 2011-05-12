class Node;

#ifndef _DIRECTION_H
#define _DIRECTION_H

#include "Sequence.h"

class Direction
{
	private:
		Node * next;
		Sequence * seq;
	public:
        Direction();
        Direction(Sequence *seq);
        Direction(Node *n);
		Sequence *GetSequence();
		void SetSequence(Sequence *s);
		Node *GetNode();
		void SetNext(Node *next);
		void SetScore();
		bool isOpen();
};

#endif // _DIRECTION_H
