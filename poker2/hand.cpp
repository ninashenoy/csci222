///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <time.h>
#include "hand.h"
#include "deck.h"

///////////////////////////////////////////////////////////////////////////////
Hand::Hand()
{
    hand[HANDSIZE];
}

///////////////////////////////////////////////////////////////////////////////
Hand::~Hand()
{
    //nothing to destroy
}

///////////////////////////////////////////////////////////////////////////////
void Hand::dealHand( Deck& d )
{
    for( int card = 0; card < HANDSIZE; card++ )
    {
        hand[card] = d.getCard();
    }

}

void Hand::returnCards( Deck& d )
{
    for( Card c : hand )
    {
        d.addCard(c);
    }
}
bool Hand::isFlush()
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
    return ( count == HANDSIZE ) ? true: false;
}

///////////////////////////////////////////////////////////////////////////////
bool Hand::isPair()
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

