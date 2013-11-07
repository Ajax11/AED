#ifndef CLISTTRAITS_H_INCLUDED
#define CLISTTRAITS_H_INCLUDED
#include "CLess.h"
#include "CGreader.h"


template <class Tr>
struct CListTraits
{
    typedef Tr Type;
    typedef CLess<Tr> TOperator;
};

#endif // CLISTTRAITS_H_INCLUDED
