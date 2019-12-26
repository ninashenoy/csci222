///////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#ifndef _COMPETITOR_H_
#define _COMPETITOR_H_

class Competitor
{
    private:
        char* _name;
        int _lane;
        float _time;

    public:
        Competitor( const char* name, int lane );
        ~Competitor();

        void setTime( float time );
        float getTime();

        const char* getName();
        int getLane();

        void print();
};

#endif