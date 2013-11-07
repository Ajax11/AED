/*
#define USEDEBUG
#ifdef USEDEBUG
#define Debug(x)  std::cout<<x
#else
#define Debug(x)
#endif // USEDEBUG
*/

#ifndef CTEST_H_INCLUDED
#define CTEST_H_INCLUDED


#include <assert.h>
#include "CTree.h"
#include "CTraits.h"


class Test
{
public:

    void TesterTree();

protected:

private:

    void TestRoot();
    void TestSearch();
    void TestInsert();
    void TestDelete();

};


#endif // CTEST_H_INCLUDED


void Test:: TesterTree()
{
    TestRoot();
    TestSearch();
    TestInsert();
    TestDelete();
}

void Test:: TestRoot()
{
    CTree < CTrait <int> > a;
    assert (a.getRoot() == 0);

}
void Test:: TestSearch()
{
    CTree < CTrait <int> > a;
    a.insertData(50);
    a.insertData(20);
    a.insertData(41);
    a.insertData(81);
    a.insertData(141);
    assert (a.searchData(20)==1);
    assert (a.searchData(1) != 1);
}
void Test:: TestInsert()
{
    CTree < CTrait <int> > a;
    a.insertData(10);

    assert ( a.getRoot() -> getData() == 10 );

    a.insertData(5);

    assert ( a.getRoot() -> getData() != 5 );
    assert ( a.getRoot() -> getLeaf(0) -> getData() == 5);

    a.insertData(20);

    assert ( a.getRoot() -> getData() != 20);
    assert ( a.getRoot() -> getLeaf(1) -> getData() == 20);
}
void Test:: TestDelete()
{
    CTree < CTrait <int> > a;
    a.insertData(50);
    a.insertData(20);
    a.insertData(41);
    a.insertData(81);
    a.insertData(141);

    assert ( a.removeData( 5 ) == 0);
    assert ( a.removeData( 50 ) == 1);
    assert ( a.getRoot() -> getData() != 50 );


}


