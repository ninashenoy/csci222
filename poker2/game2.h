//////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include "hand.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
class Game2
{
    private:
        int flushCount;
        int pairCount;
        int avgFlush;
        int avgPair;
    public:
        Game2();
        ~Game2();
        void reset();

        int getFlushCount();
        int getPairCount();
        void incFlushConunt();
        void incPairCount();
        double flushPercent();
        double pairPercent(); 
        double avgFlushPercent( double flushPercentTotal );
        double avgPairPercent( double pairPercentTotal );

};