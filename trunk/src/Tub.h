/**
 *	@file	Tub.h
 *  @class  Tub
 *	@brief	Tubs hold data for multiple sequence alignment
 *	@author	Tony Do,
 *			Dane Elshof,
 *			Jonathan Nicholson,
 *			Dan Thode
 *	@date	11. May 2011
 */

#ifndef _TUB_H
#define _TUB_H

#include <vector>
#include "Sequence.h"

class Tub
{
    private:
        int self_id, compare_id, old_pos_a, old_pos_b;
        Sequence *left, *right;
        double msa_score;
    public:
        /**
         * Constructor takes a sequence in and initializes the tub
         * @param seq_in Sequence to use in initializing a tub
         */
        Tub(Sequence *seq_in);
        /**
         * Destructor
         */
        ~Tub();

        /**
         * Returns a tub's id
         */
        int GetID();
        /**
         * Sets a tub's id
         * @param id_in The id which a tub will be set to
         */
        void SetID(int id_in);
        /**
         * Returns the id of a tub to which the current tub will be compared
         */
        int GetCompare();
        /**
         * Sets the id of the tub the current tub will be compared to
         * @param compare_in ID of the tub to which the current tub will be compared
         */
        void SetCompare(int compare_in);

        /**
         * Returns the left sequence
         */
        Sequence *GetLeftSeq();
        /**
         * Returns the right sequence
         */
        Sequence *GetRightSeq();
        /**
         * Sets the left sequence
         * @param seq_in The sequence which the left sequence will be set
         */
        void SetLeftSeq(Sequence *seq_in);
        /**
         * Sets the right sequence
         * @param seq_in The sequence which the right sequence will be set
         */
        void SetRightSeq(Sequence *seq_in);
        /**
         * Clears the two sequences in a tub
         */
        void ClearSeqs();
        /**
         * Flips the left and right sequences in a tub
         */
        void FlipSeqs();

        /**
         * Adds a number to the msa variable
         * @param add Number to add
         */
        void AddToMSA(int add);
        void SubtractFromMSA(double sub);
        /**
         * Calculates the msa score of a tub
         * @param divisor Number of tubs left in tubvector
         */
        void CalcMSA(int divisor);
        /**
         * Returns the msa score
         */
        double GetMSA();

        /**
         * Returns a boolean indicating whether a tub has a left sequence or not
         */
        bool HasLeft();
        /**
         * Returns a boolean indicating whether a tub has a right sequence or not
         */
        bool HasRight();
        /**
         * Returns a boolean indicating whether a tub has both sequence slots filled or not
         */
        bool HasBoth();

        int GetOldPosA();
        void SetOldPosA(int pos);
        int GetOldPosB();
        void SetOldPosB(int pos);
};

#endif
