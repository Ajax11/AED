#ifndef CTREEITERATOR_H_INCLUDED
#define CTREEITERATOR_H_INCLUDED


#include <stack>
#include <list>
#include <vector>
//#include "CNode.h"

using namespace std;

template <class Type , class OTree>
class CTreeIterator
{
    typedef CNode < Type > Node;
    typedef pair < int , Node* > INode;
    typedef vector < INode > Ctnr;
    typedef stack < INode , Ctnr  > TreeStack;

    public:

        enum States { l=1,s,r,u};

        CTreeIterator();
        CTreeIterator( const CTreeIterator & it );
        virtual ~CTreeIterator();

        TreeStack mStack;
        OTree mO;

        bool operator != ( CTreeIterator it );
        Type operator * ();
        TreeStack operator ++ ();
        TreeStack operator = ( const CTreeIterator & it );

    protected:

    private:
        void moveIt(int,Node*);

};

#endif // CTREEITERATOR_H_INCLUDED


template <class Type , class OTree>
CTreeIterator< Type , OTree>:: CTreeIterator()
{

}

template <class Type , class OTree>
CTreeIterator< Type , OTree>:: CTreeIterator( const CTreeIterator & it_ )
{
    mStack = it_.mStack;
}

template <class Type , class OTree>
CTreeIterator< Type , OTree >:: ~CTreeIterator()
{

}

// Revizar Los operators ++ y * y =

template < class Type , class OTree>
void CTreeIterator < Type , OTree >:: moveIt( int a , Node*p)
{
    switch (a)
    {
        case l:
                INode b( 1 , (p)->getLeaf(0) );
                mStack.push(b);
                break;
        case s:
                break;
        case r:
                INode c( 1 , (p)->getLeaf(1) );
                mStack.push(c);
                break;
        case u:
                mStack.pop();
                break;
    }
}

template <class Type , class OTree >
typename CTreeIterator<Type,OTree> :: TreeStack   CTreeIterator<Type,OTree> :: operator++()
{
    int valState;
    valState = mStack.top().first;

    while (valState != 0 && valState != 3)
    {
        valState = mO(valState);
        moveIt( valState ,  mStack.top().second );
    }



    mStack.top().first = valState;
}


template <class Type , class OTree >
Type  CTreeIterator<Type,OTree> :: operator*()
{
    return mStack.top().second->getData();
}


template <class Type , class OTree >
bool  CTreeIterator<Type,OTree> :: operator!=( CTreeIterator it)
{
    typename stack < INode , Ctnr  >:: iterator it2;
    it2= mStack.top();
    return it2!=it;
}
