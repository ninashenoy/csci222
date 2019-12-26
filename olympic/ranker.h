///////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _RANKER_H_
#define _RANKER_H_

#include "competitor.h"


///////////////////////////////////////////////////////////////////////////////
class Ranker
{
    private:
        int _maxCompetitors;
        int _numCompetitors;
        Competitor** _ranklist;

    public:
        Ranker( int maxCompetitors );
        ~Ranker();
 
        int addList( Competitor* competitor );

        Competitor* getLane( int lane );

        Competitor* getFinish( u_int16_t finish );

        void sort();
};

#endif