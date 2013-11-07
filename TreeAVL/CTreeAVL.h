#ifndef CTREEAVL_H_INCLUDED
#define CTREEAVL_H_INCLUDED



#include <stdlib.h>
#include <time.h>
#include "CTrait.h"
#include <vector>
#include <stack>
#include <stdlib.h>


using namespace std;

template <class Tr>
class CTreeAVL
{

        typedef typename Tr::Type Type;
        typedef typename Tr::Node Node;
        typedef typename Tr::OTree OTree;

    public:

        CTreeAVL();
        virtual ~CTreeAVL();
        Node* GetRoot();
        void SetRoot(Node* p = 0);

        bool searchData(Type n);
        bool insertData(Type n);
        bool removeData(Type n);
        void deleteTree(Node** p);
        void print();




    protected:

    private:

        void inorder(Node ** t);
        OTree MC;
        Node* MRoot;
        bool findData(Type n, Node** & p ,std::stack < Node* , vector < Node* > > &);
        Node** replaceData(Node** p);


        void RotateNode( CNode < Type > ** , bool );

        inline int Height(Node ptr);
        inline void UHeight( Node* & );
        void ChHeight( stack < Node* , vector < Node* > > & );
        inline bool GetDir( Node* & );

};

#endif // CTREEAVL_H_INCLUDED

template <class Tr>
CTreeAVL<Tr>:: CTreeAVL()
{
    SetRoot(0);
}

template <class Tr>
CTreeAVL <Tr>:: ~CTreeAVL()
{
    Node ** t;
    t = &MRoot;
    deleteTree(t);
}

template <class Tr>
void CTreeAVL <Tr>:: deleteTree(Node** t)
{
    if( ! (*t) )
        return;
    deleteTree(  &( (*t) ->GetLeaf(0) )  );
    deleteTree(  &( (*t) ->GetLeaf(1) )  );
    delete *t;
}


//REVIZAR
template < class Tr >
void CTreeAVL <Tr> :: RotateNode( CNode < Type > ** ptr, bool dir)
{
    CNode < Type > * tmp;
    tmp= *ptr;
    ( *ptr ) = ( *ptr ) -> getLeaf( dir );
    tmp->SetLeaf( dir  ) = ( *ptr ) -> getLeaf( !dir );
    ( *ptr )-> SetLeaf(!dir) = &tmp;
}


template <class Tr>
void CTreeAVL<Tr>:: SetRoot(Node* p)
{
    MRoot = p;
}

template <class Tr>
inline int CTreeAVL<Tr>:: Height( Node ptr )
{
    if (ptr)
        return -1;
    return (ptr) -> getHeight();
}

template <class Tr>
inline void CTreeAVL<Tr>:: UHeight( Node* & ptr )
{
    if ( *ptr )
    {
        int temp = max( Height( ( *ptr )->getLeaf(0) ) , Height( ( *ptr )->getLeaf(1) ) );
        ( *ptr ) -> setHeight( temp + 1 );
    }
}

template <class Tr>
inline bool CTreeAVL<Tr>:: GetDir( Node* & ptr )
{
    int temp;
    temp = Height( ( *ptr )->GetLeaf(1) ) - Height ( ( *ptr )->GetLeaf(0) );
    return ( ( temp + 2 ) > 0 );
}

template <class Tr>
void CTreeAVL<Tr>:: ChHeight( stack < Node* , vector < Node* > > & Way )
{
    while(!Way.empty())
    {
        UHeight( Way.top() );
        int temp;
        temp = Height( ( * (Way.top() ) )->GetLeaf(1) ) - Height ( ( * (Way.top() ) )->GetLeaf(0) );
        if( temp >=2 or temp <=-2 )
        {
            RotateNode( Way.top() , ( ( temp + 2 )  > 0 ) );
            UHeight( *(Way.top()) -> getLeaf( !( ( temp + 2 ) > 0 ) ) );
            UHeight( Way.top() );
        }
        Way.pop();
    }
}

template <class Tr>
typename CTreeAVL<Tr>::Node* CTreeAVL<Tr>::GetRoot()
{
    return MRoot;
}

template <class Tr>
bool CTreeAVL<Tr>::findData(Type n, Node ** &p , stack < Node* , vector < Node* > > & Way)
{
    for( p = &MRoot ; (*p) ; p = &( (*p)-> GetLeaf ( MC( ( (*p)-> GetData()) , n) ) ) )
    {
        Way.push(p);
        if( (*p)->GetData() == n )
            return 1;
    }
    return 0;
}

template <class Tr>
bool CTreeAVL<Tr>:: insertData(Type n)
{
    stack < Node* , vector < Node* > > Way;
    Node**p;
    if( findData(n,p,Way) )
        return 0;
    *p = new Node(n);

    ChHeight(Way);
    return 1;
}

template <class Tr>
bool CTreeAVL<Tr>::searchData(Type n)
{
    Node**p;
    stack < Node , vector < Node > >  Way;
    return findData(n,p,Way);
}

template <class Tr>
typename CTreeAVL<Tr>:: Node** CTreeAVL<Tr> :: replaceData(Node** p)
{
    srand(time(NULL));
    bool var = !!(rand());
    p = &(*p)->GetLeaf(var);
    for( ; !! ((*p) -> GetLeaf(!var)) ; p = &(*p)->GetLeaf(!var) ){}
    return p;
}

template <class Tr>
bool CTreeAVL<Tr>:: removeData(Type n)
{
    Node**p;
    if(! findData(n , p))
        return 0;
    bool l = !! (*p)->GetLeaf(0),r = !! (*p)->GetLeaf(1);

    if (l & r) //2 hijos
    {
        Node**q;
        q=replaceData(p);
        (*p) -> SetData( ( (*q) -> GetData() ) );
        p=q;
        l = !! (*p)->GetLeaf(0),r = !! (*p)->GetLeaf(1);
    }

    if(!l & !r) // 0 hijos
    {
        delete *p;
        *p=0;
        return 1;
    }
    //1 hijo

    Node * t = *p;
    *p=(*p)->GetLeaf(r);
    delete t;
    return 1;
}

template <class Tr>
void CTreeAVL<Tr>:: print()
{
    Node**p;
    p = &MRoot;
    inorder(p);
}

template <class Tr>
void CTreeAVL<Tr>:: inorder(Node ** t)
{
    if( ! (*t) )
        return;
    inorder( &( (*t) ->GetLeaf(0) ) );
    std::cout<< (*t) -> GetData() <<std::endl;
    inorder(  & ( (*t) ->GetLeaf(1) ) );
}

