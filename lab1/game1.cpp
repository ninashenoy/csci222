///////////////////////////////////////////////////////////////////////////////
// Nina Shenoy
// 012053716
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "game1.h"
#include "deck.h"

using namespace std;
ofstream csis;

const int NUMTRIALS = 10;
const int NUMHANDS = 10000;
const int NUMSWAPS = 100;

///////////////////////////////////////////////////////////////////////////////
Game1::Game1()
{
   reset();
}
///////////////////////////////////////////////////////////////////////////////
Game1::~Game1()
{
    //nothing to release or destroy
}
///////////////////////////////////////////////////////////////////////////////
void Game1::reset()
{
    flushCount = 0;
    pairCount = 0;
}
///////////////////////////////////////////////////////////////////////////////
void Game1::dealHand( Deck& d )
{
    for( int i = 0; i < HANDSIZE; i++ )
    {
        hand[i] = d.getCard();
    }
}
///////////////////////////////////////////////////////////////////////////////
void Game1::returnCards( Deck& d )
{
    for( int i = 0; i < HANDSIZE; i++ )
    {
        d.addCard( hand[i] );
    }
}
///////////////////////////////////////////////////////////////////////////////
bool Game1::isFlush()
{
    int suit =  hand[0].getSuit();
    int count = 1;
    for( int i = 1; i < HANDSIZE; i++ )
    {
        int nextSuit = hand[i].getSuit();
        if( suit == nextSuit )
        {
            count++;
        }
        else
        {
            break;
        }
    }
    if( count == HANDSIZE )
    {
        flushCount++;
    }
    return ( count == HANDSIZE ) ? true: false;
}
///////////////////////////////////////////////////////////////////////////////
bool Game1::isPair()
{
    int count = 0;
    for( int i = 0; i < HANDSIZE; i++ )
    {
        int currentCard = hand[i].getValue();
        for( int j = i+1; j < HANDSIZE; j++ )
        {
            int nextCard = hand[j].getValue();
            if( currentCard == nextCard )
            {
                pairCount++;
                count++;
                break;
            }
        }
        if( count >= 1 )
        {
            break;
        }
    }
    return (count >=1)? true: false;
}
///////////////////////////////////////////////////////////////////////////////
int Game1::getFlushCount()
{
    return flushCount;
}
///////////////////////////////////////////////////////////////////////////////
int Game1::getPairCount()
{
    return pairCount;
}
///////////////////////////////////////////////////////////////////////////////
double Game1::flushPercent()
{
    double flushPercent = (double) 100*( (double)flushCount/(double)NUMHANDS );
    return flushPercent;

}
///////////////////////////////////////////////////////////////////////////////
double Game1::pairPercent()
{
    double pairPercent = (double) 100*( (double)pairCount/(double)NUMHANDS );
    return pairPercent;
}
///////////////////////////////////////////////////////////////////////////////
double Game1::avgFlushPercent( double flushPercentTotal )
{
    double avgFlushPercent = (double)flushPercentTotal/(double)NUMTRIALS;
    return avgFlushPercent;

}
///////////////////////////////////////////////////////////////////////////////
double Game1::avgPairPercent( double pairPercentTotal )
{
    double avgPairPercent = (double)pairPercentTotal/(double)NUMTRIALS;
    return avgPairPercent;
}
///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    srand((unsigned)time(NULL));
    Game1 game;
    Deck deck;

    double flushPercentTotal = 0.0;
    double pairPercentTotal = 0.0;

    csis.open( "csis1.txt" );
    for( int t = 0; t < NUMTRIALS; t++ )
    {
        cout << "-------------------------------------\n";
        csis << "-------------------------------------\n";

        cout << "Trial #: " << t+1 << endl;
        csis << "Trial #: " << t+1 << endl;
        for( int h = 0; h < NUMHANDS; h++ )
        {
            deck.shuffle( NUMSWAPS );
            game.dealHand( deck );
            game.isFlush();
            game.isPair();
            game.returnCards( deck );
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
