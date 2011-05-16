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
        int self_id, compare_id;
        Sequence *left, *right;
        // old scores hold the previous dmatrix lists of the seqs/aligns current represented by the tub
        vector<double> old_scores_a;
        vector<double> old_scores_b;
        vector<double> align_scores;
        vector<double> q_scores;
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
         * Adds/Sets an alignment score in a tub
         * @param index Index in the alignment vector into which an alignment score is put
         * @param num_in The value to be put into the alignment score
         */
        void SetAlignScore(int index, double num_in);
        /**
         * Returns an alignment score at the specified index
         * @param index Index in the alignment scores vector
         */
        double GetAlignScore(int index);
        /**
         * Returns the length of the alignemtn scores vector in a tub
         */
        int GetAlignScoreLength();

        /**
         * Sets a Q score at the specified index in the q score vector
         * @param index Index in the q score vector that the score will be put
         * @param num_in Score to be put in the q score vector
         */
        void SetQScore(int index, double num_in);
        /**
         * Returns the q score at the specified index in the q score vector
         * @param index Index of score in q score vector
         */
        double GetQScore(int index);

        /**
         * Adds a number to the msa variable
         * @param add Number to add
         */
        void AddToMSA(int add);
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

        /**
         * Copies the input tub's alignment scores vector to the tub's old alignment scores a vector
         * @param tub_in Tub from which old alignment vector will be copied
         */
        void SetOldA(Tub *tub_in);
        /**
         * Copies the input tub's alignment scores vector to the tub's old alignment scores b vector
         * @param tub_in Tub from which old alignment vector will be copied
         */
        void SetOldB(Tub *tub_in);
        /**
         * Returns the alignment score in a specific position in the old scores a vector
         * @param index Index of the score to return
         */
        double GetOldA(int index);
        /**
         * Returns the alignment score in a specific position in the old scores b vector
         * @param index Index of the score to return
         */
        double GetOldB(int index);
        /**
         * Combines two tubs data, used when two tubs have the closest distsance from the q matrix
         * @param tub_in Tub that will be combined with the calling tub
         * @param pos Position of the tub being removed from the tubvector, used to remove score from alignment vector
         */
        void Combine(Tub *tub_in, int pos);
};

#endif
