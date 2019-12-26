///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CARD_H
#define _CARD_H

///////////////////////////////////////////////////////////////////////////////
class Card
{
    public:
        //Define typed for the suit and value
        enum Suit{ Diamonds, Hearts, Clubs, Spades };
        enum Value{ NullCard, Ace, Two, Three, Four, Five, Six, Seven, Eight,
                    Nine, Ten, Jack, King, Queen };
    private:
        static const char *snames[4];
        static const char *vnames[14];
        Suit s;
        Value v;
    public:
        //Constructors initialize a card
        Card();
        Card( Suit newSuit, Value newValue );
        Suit getSuit();
        Value getValue();
        void printSuit();
        void printValue();
        void printCard();
};
//Return the next suit or card value in succession
Card::Suit nextSuit( Card::Suit );
Card::Value nextValue( Card::Value );

#endif
