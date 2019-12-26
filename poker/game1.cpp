///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "game1.h"

using namespace std;

const int NUMTRIALS = 10;
const int NUMHANDS = 10000;
const int NUMSWAPS = 100;

///////////////////////////////////////////////////////////////////////////////
Game1::Game1()
{
    //Constructor Declaration
    //Creates new, empty Game1 object
    //resetTrialStats() flushCount and pairCount to 0
    resetTrialStats();
}

///////////////////////////////////////////////////////////////////////////////
Game1::~Game1()
{
    // nothing to release or destroy
}

///////////////////////////////////////////////////////////////////////////////
void Game1::resetTrialStats()
{
    //reset flushcount and paircount to 0
    _flushCount = 0;
    _pairCount = 0;
    _avgFlush = 0;
    _avgPair = 0;
}


///////////////////////////////////////////////////////////////////////////////
void Game1::dealHand( Deck& d )
{
    //pass reference because we dont want a copy of the object to be created
    //...since pass by value will create a copy of the object and destroy
    //the object when exiting the function

    // deals 5 cards from Deck into hand[] array
    for( int card = 0; card < HANDSIZE; card++ )
    {
        _hand[card] = d.getCard();
    }
}

///////////////////////////////////////////////////////////////////////////////
bool Game1::isFlush()
{
    //checks hand[] for flush...all cards have same suit
    //ex. all cards are hearts
    int suit = _hand[0].getSuit();
    int suit_count = 1;
    for( int card = 1; card < HANDSIZE; card++ )
    {
        int nextSuit = _hand[card].getSuit();
        if( suit == nextSuit )
        {
            suit_count++;
        }
        else 
        {
            break;
        }
    }
    return (suit_count == HANDSIZE ) ? true: false;
}

///////////////////////////////////////////////////////////////////////////////
void Game1::incFlushCount()
{
    //increments flush count
    _flushCount++;
}

///////////////////////////////////////////////////////////////////////////////
void Game1::incPairCount()
{
    //increments pair count
    _pairCount++;
}

///////////////////////////////////////////////////////////////////////////////
int Game1::getFlushCount()
{
    //returns flushcount
    return _flushCount;
}

///////////////////////////////////////////////////////////////////////////////
int Game1::getPairCount()
{
    //returns paircount
    return _pairCount;
}

///////////////////////////////////////////////////////////////////////////////
bool Game1::isPair()
{
    //determines if the hand contains a pair
    int count = 0;
    for( int card_idx = 0; card_idx < HANDSIZE; card_idx++ )
    {
        int curr_card = _hand[card_idx].getValue();
        for( int j = card_idx + 1; j < HANDSIZE; j++ )
        {
           int next_card = _hand[j].getValue();
           if( curr_card == next_card )
           {
               //if a card has the same value as the card next to it, increment
               //...count and break out of loop
                count++;
                break;
           }
       }
       if( count >= 1 )
       {
           //break out of loop
           break;
       }
   }
   //if count is >= 1, return true. else, return false
   return (count >=1)? true: false;
}

///////////////////////////////////////////////////////////////////////////////
double Game1::percentFlush()
{
    //calculates the percentage flushes out of 10,000 hands
    double percentFlush = (double) 100*( (double)_flushCount / (double)NUMHANDS );
    _avgFlush += percentFlush;
    return percentFlush;
}

///////////////////////////////////////////////////////////////////////////////
double Game1::percentPair()
{
    //calculates the percentage pairs out of 10,000 hands
    double percentPair = (double) 100*( (double)_pairCount / (double)NUMHANDS );
    _avgPair += percentPair;
    return percentPair;
}


///////////////////////////////////////////////////////////////////////////////
void Game1::printTrialStats(int trial)
{
    cout << "\n------------------------------------------------\n";
    //print trial number
    cout << "Trial no: " << trial + 1 << endl;
    //print number of hands dealt
    cout << "Number of hands dealt(total): " << NUMHANDS << endl;
    //print number of hands with at least a pair
    cout << "Number of hands with at least a pair: " << getPairCount() << endl;
    //print number of hands with a flush
    cout << "Number of hands with a flush: " << getFlushCount() << endl;
    cout.precision(2);
    //print percentage of hands with at least a pair
    cout << "Percentage of hands with at least a pair: " << fixed << percentPair() << endl;
    //print percentage of hands with at least a flush
    cout << "Percentage of hands with a flush: " << fixed << percentFlush() << endl;
}

///////////////////////////////////////////////////////////////////////////////
void Game1::startGame()
{ 
    //set total_pairs and total_flush to 0
    int total_pairs = 0;
    int total_flush = 0;
    //for each trial
    for( int trial = 0; trial < NUMTRIALS; trial++ )
    {
        resetTrialStats();   
        //for each hand of 10,000 cards 
        for( int hand = 0; hand < NUMHANDS; hand++ )
        {
            //create new deck and shuffle
            Deck deck;
            deck.shuffle(NUMSWAPS);

            //deal hand of 5 cards from deck
            dealHand( deck );
            if( isFlush() == true )
            {
                //if hand has a flush, increment flush count
                incFlushCount();
            }
            if( isPair() == true )
            {
                //if hand has a pair, increment pair count
                incPairCount();
            }
        }
        //caluclate total number of pairs and flushes
        total_pairs += getPairCount();
        total_flush += getFlushCount();
        //print trial statistics
        printTrialStats( trial );
    }

    // game stats
    //average percentage of pairs
    double pair_percent = 100 * ((double)total_pairs/(NUMTRIALS * NUMHANDS));

    //average percentage of flushes
    double flush_percent = 100 * ((double)total_flush/(NUMTRIALS * NUMHANDS));
    cout << "\n----------Game over----------------------------------\n";
    cout << "Percentage pairs: " << pair_percent << "%" << endl;
    cout << "Percentage flush: " << flush_percent << "%" << endl;
}

///////////////////////////////////////////////////////////////////////////////
int main( int argc, char* argv[] )
{
    srand((unsigned)time(NULL));

    //create new game
    Game1 game;
    //start game
    game.startGame();
    return 0;
}