#ifndef CTREE_H_INCLUDED
#define CTREE_H_INCLUDED

#include "CTraits.h"
#include <stdlib.h>
#include <time.h>
#include "CTreeIterator.h"

template <class Tr>
class CTree
{

        typedef typename Tr::Type Type;
        typedef typename Tr::Node Node;
        typedef typename Tr::OTree OTree;
        typedef typename Tr::InOrder InOrder;

    public:

        CTree();
        virtual ~CTree();
        Node* getRoot();
        void setRoot(Node* p = 0);

        bool searchData(Type n);
        bool insertData(Type n);
        bool removeData(Type n);
        void print();
        CTreeIterator < Type , InOrder > IFBegin()
        {
            InOrder a;
            CTreeIterator < Type , InOrder > it;
            CNode < Type > ** p;
            p = &m_root;
            while( *p )
            {
				pair < int , Type > b ( a.StartState , (*p) );
                it.m_stack.push( b );

                Node* t;
                t=(*p)->getLeaf( (a.StartState) % 2 );
                p = &t;
            }
        }

    protected:

    private:

        void inorder(Node ** t);
        OTree m_c;
        Node* m_root;
        bool findData(Type n, Node** & p);
        void deleteTree(Node** p);
        Node** replaceData(Node** p);

};

#endif // CTREE_H_INCLUDED

template <class Tr>
CTree <Tr>:: CTree()
{
    setRoot(0);
}

template <class Tr>
CTree <Tr>:: ~CTree()
{

    Node ** t;
    t = &m_root;
    deleteTree(t);

}

template <class Tr>
void CTree <Tr>:: deleteTree(Node** t)
{
    if( ! (*t) )
        return;
    deleteTree(  &( (*t) ->getLeaf(0) )  );
    deleteTree(  &( (*t) ->getLeaf(1) )  );
    delete *t;
}

template <class Tr>
void CTree<Tr>:: setRoot(Node* p)
{
    m_root = p;
}

template <class Tr>
typename CTree<Tr>::Node* CTree<Tr>::getRoot()
{
    return m_root;
}

template <class Tr>
bool CTree<Tr>::findData(Type n, Node ** &p)
{
    for( p = &m_root ; (*p) ; p = &( (*p)-> getLeaf ( m_c( ( (*p)-> getData()) , n) ) ) )
    {
        if( (*p)->getData() == n )
            return 1;
    }
    return 0;
}

template <class Tr>
bool CTree<Tr>:: insertData(Type n)
{
    Node**p;
    if(findData(n,p))
        return 0;
    *p = new Node(n);
    return 1;
}

template <class Tr>
typename CTree<Tr>::Node** CTree<Tr>::replaceData(Node** p)
{
    srand(time(NULL));
    bool var = !!(rand());
    p = &(*p)->getLeaf(var);
    for( ; !! ((*p) -> getLeaf(!var)) ; p = &(*p)->getLeaf(!var) ){}
    return p;
}

template <class Tr>
bool CTree<Tr>::searchData(Type n)
{
    Node**p;
    return findData(n,p);
}

template <class Tr>
bool CTree<Tr>:: removeData(Type n)
{
    Node**p;
    if(! findData(n , p))
        return 0;
    bool l = !! (*p)->getLeaf(0),r = !! (*p)->getLeaf(1);

    if (l & r) //2 hijos
    {
        Node**q;
        q=replaceData(p);
        (*p) -> setData( ( (*q) -> getData() ) );
        p=q;
        l = !! (*p)->getLeaf(0),r = !! (*p)->getLeaf(1);
    }

    if(!l & !r) // 0 hijos
    {
        delete *p;
        *p=0;
        return 1;
    }
    //1 hijo

    Node * t = *p;
    *p=(*p)->getLeaf(r);
    delete t;
    return 1;
}

template <class Tr>
void CTree<Tr>:: print()
{
    Node**p;
    p = &m_root;
    inorder(p);
}

template <class Tr>
void CTree<Tr>:: inorder(Node ** t)
{
    if( ! (*t) )
        return;
    inorder( &( (*t) ->getLeaf(0) ) );
    std::cout<< (*t) -> getData() <<std::endl;
    inorder(  & ( (*t) ->getLeaf(1) ) );
}



