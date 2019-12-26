///////////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <assert.h>

#include "ranker.h" 

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// constructor is initialized using the number of competitors in race
Ranker::Ranker( int maxCompetitors )
{
    //continues if number passed in is less than the max possible number of
    // competitors
    _maxCompetitors = maxCompetitors;
    _ranklist = new Competitor* [ maxCompetitors ];
    _numCompetitors = 0;
}

///////////////////////////////////////////////////////////////////////////////
Ranker::~Ranker()
{
    delete [] _ranklist;
}

///////////////////////////////////////////////////////////////////////////////
// adds pointer to a Competitor object to an array of pointers to Competitor
// object. Returns 0 if invalid pointer passed in or numCompetitors exceeds max
int Ranker::addList( Competitor* competitor )
{
    int return_value = 0;

    if( competitor != NULL )
    {
        if( _numCompetitors < _maxCompetitors )
        {
            _ranklist[_numCompetitors] = competitor;
            _numCompetitors++;
        }
    }
    return return_value;
}

///////////////////////////////////////////////////////////////////////////////
// returns pointer to a Competitor object of the lane number that is passed in
Competitor* Ranker::getLane( int lane )
{
    Competitor* cptr = NULL;
    for( int comp = 0; comp < _numCompetitors; comp++ )
    {
        if( _ranklist[comp]->getLane() == lane )
        {
            cptr = _ranklist[comp];
            break;
        }
    }
    return cptr;
}

///////////////////////////////////////////////////////////////////////////////
// returns pointer to a Competitor object of the specified position
// 1st place, 2nd place, etc.
Competitor* Ranker::getFinish( u_int16_t finish )
{
    Competitor* cptr = NULL;
    if( (finish - 1) < _numCompetitors )
    {
        sort();
        cptr = _ranklist[finish-1];
    }
    return cptr;   
}

///////////////////////////////////////////////////////////////////////////////
// sorts the competitors in _ranklist from first place to last place
void Ranker::sort()
{
    for( int i = 0; i < _numCompetitors; i++ )
    {
        for( int j = i + 1; j < _numCompetitors; j++ )
        {
            if( _ranklist[i]->getTime() > _ranklist[j]->getTime() )
            {
                Competitor* temp = _ranklist[i];
                _ranklist[i] = _ranklist[j];
                _ranklist[j] = temp;         
            }
        }
    }
}