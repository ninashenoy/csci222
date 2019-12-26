///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include "card.h"
#include "deck.h"

const int HANDSIZE = 5;

class Game1
{
    private:
        Card hand[HANDSIZE];
        int flushCount;
        int pairCount;
        //double flushPercentTotal;
        //double pairPercentTotal;
    public:
        Game1();
        ~Game1();

        void reset();
        void dealHand( Deck& d );
        void returnCards( Deck& d );
        bool isFlush();
        bool isPair();
        int getFlushCount();
        int getPairCount();
        double flushPercent();
        double pairPercent();
        double avgFlushPercent( double flushPercentTotal );
        double avgPairPercent( double pairPercentTotal );
};