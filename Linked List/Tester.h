#ifndef TESTER_H
#define TESTER_H

#include "CListTraits.h"
#include "C_List.h"
#include <iostream>
#include <assert.h>


using namespace std;

class Tester
{
    public:
        Tester(){}
        virtual ~Tester(){}

        void testerList();

    protected:
    private:

            void testHead();
            void testSearch();
            void testDelete();
            void testInsert();

		void testIterator();
            void testIEnd();
            void testIBegin();
            void IOpPlusPlus();
            void IOpContent();
            void IOpNotEqual();
};

#endif // TESTER_H


void Tester::testerList()
{
    testHead();
    testDelete();
    testIBegin();
    testIEnd();
    testInsert();
    testIterator();
    testSearch();
}

void Tester:: testHead()
{
    C_List < CListTraits<int> > IntList;

    assert( ( IntList.getHead() )  == 0); //1

    IntList.insert_data(155);
    IntList.insert_data(25);
    IntList.insert_data(5);
    IntList.insert_data(1312);
    IntList.insert_data(185564);
    assert ( ( IntList.getHead()-> get_data() == 5) );
    IntList.delete_data(5);
    assert ( ( IntList.getHead()-> get_data() == 25) );


}

void Tester:: testSearch()
{
    C_List < CListTraits<int> > IntList;

    IntList.insert_data(1);
    IntList.insert_data(342);
    IntList.insert_data(12);
    IntList.insert_data(23);
    IntList.insert_data(43);

    assert( IntList.search_data(1) == 1 );
    IntList.delete_data(1);
    assert( IntList.search_data(1) == 0 );

    assert( IntList.search_data(342) == 1 );
    assert( IntList.search_data(2458) == 0 );
}

void Tester:: testDelete()
{
    C_List < CListTraits<int> > IntList;

    IntList.insert_data(1);
    IntList.insert_data(2);
    IntList.insert_data(3);
    IntList.insert_data(0);
    IntList.insert_data(-1);
    IntList.insert_data(-2);
    assert( IntList.search_data(1) == 1 );
    assert( IntList.delete_data(1) == 1 );
    assert( IntList.search_data(1) == 0 );
    assert( IntList.delete_data(10) == 0 );
}

void Tester:: testInsert()
{
    C_List < CListTraits<int> > IntList;

    IntList.insert_data(3);
    IntList.insert_data(9);
    IntList.insert_data(15);
    IntList.insert_data(12);
    IntList.insert_data(6);
    IntList.insert_data(21);
    IntList.insert_data(18);

    C_Node <int> **p;
    C_Node <int> *q;
    q=IntList.getHead();
    p=&q;

    for(int i=1; i<=7; ++i)
    {
        assert(IntList.search_data(3*i) == 1 );
        assert ( (*p)->get_data() == (3*i) );
        (*p) = (*p)->getNext();
    }

}

void Tester:: testIterator()
{
    testIEnd();
    testIBegin();
    IOpPlusPlus();
    IOpContent();
    IOpNotEqual();
}


void Tester:: testIBegin()
{
    C_List < CListTraits<int> > IntList;
    CListIterator <int> it;
    assert( ( it=IntList.iBegin() ).m_i   == IntList.getHead() );
}

void Tester:: testIEnd()
{
    C_List < CListTraits<int> > IntList;
    CListIterator <int> it;
    assert ( it.m_i == 0 );
    it=IntList.iEnd();
    assert ( it.m_i == 0 );
}

void Tester::IOpContent()
{
    C_List < CListTraits <int> > IntList;
    CListIterator <int> it;
    IntList.insert_data(15);
    IntList.insert_data(25);
    IntList.insert_data(35);
    IntList.insert_data(45);
    IntList.insert_data(5);
    IntList.insert_data(10);

    C_Node <int> **p;
    C_Node <int> *q;
    q=IntList.getHead();

    for( it = IntList.iBegin() , p=&q ;
     it != IntList.iEnd() ;
     ( (*p) = (*p)-> m_next ) , it++ )
     {
         assert( *it == (*p) -> get_data() );
     }
}

void Tester:: IOpPlusPlus()
{
    C_List < CListTraits <int> > IntList;
    CListIterator <int> it;

    IntList.insert_data(8);
    IntList.insert_data(12);
    IntList.insert_data(4);
    IntList.insert_data(20);
    IntList.insert_data(16);

    C_Node <int> **p;
    C_Node <int> *q;
    q=IntList.getHead();

    for( it=IntList.iBegin(), p=&q ;
         it != IntList.iEnd() ;
         it++ , (*p) = (*p)->m_next )
    {
        assert ( it.m_i == ( *p ) );
    }
}

void Tester::IOpNotEqual()
{
    C_List < CListTraits <int> > IntList;
    CListIterator <int> it;

    IntList.insert_data(1);
    IntList.insert_data(2);
    IntList.insert_data(3);
    IntList.insert_data(4);
    IntList.insert_data(5);
    IntList.insert_data(6);

    it=IntList.iBegin();

    while( it != IntList.iEnd() )
    {
        it++;
    }
}
