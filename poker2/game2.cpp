//////////////////////////////////////////////////////////////////////////////
// Nina Shenoy
// 012053716
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "game2.h"
#include "deck.h"

using namespace std;
ofstream csis;

const int NUMTRIALS = 10;
const int NUMHANDS= 10000;
const int NUMSWAPS = 100;

///////////////////////////////////////////////////////////////////////////////
Game2::Game2()
{
    reset();
}
Game2::~Game2()
{
    //nothing to release or destroy
}
void Game2::reset()
{
    flushCount = 0;
    pairCount = 0;
}
int Game2::getFlushCount()
{
    return flushCount;
}
int Game2::getPairCount()
{
    return pairCount;
}
void Game2::incFlushConunt()
{
    flushCount++;
}
void Game2::incPairCount()
{
    pairCount++;
}
double Game2::flushPercent()
{
    double flushPercent = (double) 100*( (double)flushCount/(double)NUMHANDS );
    return flushPercent;
}
double Game2::pairPercent()
{
    double pairPercent = (double) 100*( (double)pairCount/(double)NUMHANDS );
    return pairPercent;
}
double Game2::avgFlushPercent( double flushPercentTotal )
{
    double avgFlushPercent = (double)flushPercentTotal/(double)NUMTRIALS;
    return avgFlushPercent;
}
double Game2::avgPairPercent( double pairPercentTotal )
{
    double avgPairPercent = (double)pairPercentTotal/(double)NUMTRIALS;
    return avgPairPercent;
}
///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    srand((unsigned)time(NULL));
    Game2 game;
    Hand hand;
    Deck deck;

    double flushPercentTotal = 0.0;
    double pairPercentTotal = 0.0;

    csis.open( "csis2.txt" );
    for( int t = 0; t < NUMTRIALS; t++ )
    {
        cout << "-------------------------------------\n";
        csis << "-------------------------------------\n";

        cout << "Trial #: " << t+1 << endl;
        csis << "Trial #: " << t+1 << endl;
        for( int h = 0; h < NUMHANDS; h++ )
        {
            deck.shuffle( NUMSWAPS );
            hand.dealHand( deck );
            if( hand.isFlush() == true )
            {
                game.incFlushConunt();
            }
            if( hand.isPair() == true )
            {
                game.incPairCount();
            }
            hand.returnCards( deck );
        }
        cout.precision(2);
        csis.precision(2);
        cout << "Number of flushes: " << game.getFlushCount() << endl;
        csis << "Number of flushes: " << game.getFlushCount() << endl;

        cout << "Number of pairs: " << game.getPairCount() << endl;
        csis << "Number of pairs: " << game.getPairCount() << endl;

        cout << "Percentage of flushes: " << fixed << game.flushPercent() << "%" << endl;
        csis << "Percentage of flushes: " << fixed << game.flushPercent() << "%" << endl;

        cout << "Percentage of pairs: " << fixed <<  game.pairPercent() << "%" << endl;
        csis << "Percentage of pairs: " << fixed <<  game.pairPercent() << "%" << endl;

        flushPercentTotal += game.flushPercent();
        pairPercentTotal += game.pairPercent();
        game.reset();
    }
    cout << "\n",
    csis << "\n";

    cout << "Average percentage of flushes: " << game.avgFlushPercent( flushPercentTotal ) << "%" << endl;
    csis << "Average percentage of flushes: " << game.avgFlushPercent( flushPercentTotal ) << "%" << endl;

    cout << "Average percentage of pairs: " << game.avgPairPercent( pairPercentTotal ) << "%" << endl;
    csis << "Average percentage of pairs: " << game.avgPairPercent( pairPercentTotal ) << "%" << endl;

    csis.close();
    return 0;
}