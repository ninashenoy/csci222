#ifndef _HAND_H_
#define _HAND_H_

#include "card.h"
#include "deck.h"

const int HANDSIZE = 5;

class Hand
{
    private:
        Card hand[HANDSIZE];
        //int flushCount;
        //int pairCount;
    public:
        Hand();
        ~Hand();
        void dealHand( Deck& d );
        bool isFlush();
        bool isPair();
        void returnCards( Deck& d );
};
#endif