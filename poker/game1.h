///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _GAME1_H_
#define _GAME1_H_

///////////////////////////////////////////////////////////////////////////////
#include "card.h"
#include "deck.h"

const int HANDSIZE = 5;

///////////////////////////////////////////////////////////////////////////////
class Game1
{
    private:
        Card _hand[HANDSIZE];
        int _flushCount;
        int _pairCount;
        double _avgFlush;
        double _avgPair;

    public:
        Game1();
        ~Game1();
        
        void resetTrialStats();

        void dealHand( Deck& d );
        
        bool isFlush();
        int getFlushCount();
        void incFlushCount();
        double percentFlush();

        bool isPair();
        int getPairCount();
        void incPairCount();
        double percentPair();    

        void printTrialStats(int trail);
        void printGameStats(int total_trails);

        void startGame();     
};

#endif