class Node;
/**
 *  @class  Direction
 *  @brief  Directions in a guide tree node.
 *          A direction contains a direction (as in left
 *          or right) OR a direction.
 *          A direction can only have three states:
 *              -# Empty: A node or a sequence can be placed.
 *              -# Sequence: Only A sequence can be contained.
 *              -# Node: Only a branch down the tree.
 *          Never can it have both a sequence and a branch.
 *          These should members should be called from the
 *          Node Object.
 */
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
		void SetNextNode(Node *next);
		void SetScore();
		/// Checks for an empty Direction Object
		bool isOpen();
};

#endif // _DIRECTION_H
