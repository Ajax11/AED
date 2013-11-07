#ifndef C_LIST_H_INCLUDED
#define C_LIST_H_INCLUDED
#include <iostream>

#include "CListIterator.h"

using namespace std;

template <class Tr>//class Type, class TOperator
class C_List
{
    public:

        typedef typename Tr::Type Type;
        typedef typename Tr::TOperator TOperator;
        typedef CListIterator<Type> myIterator;


        C_List();
        virtual ~C_List();
        friend class C_Node<Type> ;

        bool insert_data(Type x);
        bool search_data(Type x);
        bool delete_data(Type x);
        bool print_list();

        myIterator iBegin()
        {
            //myIterator it (m_head);
            CListIterator<Type> it(m_head);
            return it
            ;
        }
        myIterator iEnd()
        {
            myIterator it;
            return it;
        }

        C_Node<Type> * & getHead()
        {
            return m_head;
        }



    protected:
    private:

        TOperator TO;
        C_Node<Type> * m_head;
        bool find_data(Type x, C_Node<Type> ** & ptr);

};


#endif // C_LIST_H_INCLUDED



template <class Tr>                                                                             //<class Type, class TOperator>
C_List<Tr> :: C_List()                                                                    //<Type,TOperator>
{
    m_head = 0;
}

template <class Tr>                                                                             //<class Type, class TOperator>
C_List<Tr> :: ~C_List()                                                                   //<Type,TOperator>
{
    C_Node<Type> * temp;
    while(m_head)
    {
        temp= getHead() -> getNext();
        delete m_head;
        m_head = temp;
    }
}

template <class Tr>                                                                             //<class Type, class TOperator>
bool C_List<Tr>  :: find_data(Type x, C_Node <Type> ** & p)                               //<Type,TOperator>
{
    for(p=&m_head;
        *p && TO((*p)-> get_data() , x);
        p=&(*p)-> m_next){}

    return ((*p) && (TO(((*p)-> get_data()) , x) or ((*p)-> get_data()) == x));
}

template <class Tr>                                                                             //<class Type, class TOperator>
bool C_List <Tr> :: search_data(Type x)                                                   //<Type,TOperator>
{
    C_Node <Type> ** p;
    return find_data(x,p);
}

template <class Tr>                                                                             //<class Type, class TOperator>
bool C_List<Tr> :: insert_data(Type x)                                                    //<Type,TOperator>
{
    C_Node <Type> ** p;
    if( (find_data(x, p)) )
        return 0;
    C_Node<Type> *q = new C_Node <Type> (x);
    q -> m_next = *p;
    *p=q;
    return 1;
}



template <class Tr>                                                                              //<class Type, class TOperator>
bool C_List<Tr> :: delete_data(Type x)                                                     //<Type,TOperator>
{
    C_Node <Type> ** p;
    if(!find_data(x,p))
        return 0;
    C_Node <Type> * q = *p;
    (*p) = ( (*p)->getNext() );
    delete q;
    return 1;
}

template <class Tr>                                                                                //<class Type, class TOperator>
bool C_List <Tr> :: print_list()                                                             //<Type,TOperator>
{
    C_Node<Type> **p;
    for(p=&m_head;
        *p && (*p)-> m_next;
        p=&(*p)-> m_next)
        {
            cout<<(*p)->get_data()<<"   ->  ";
        }
    if(*p && (*p)-> m_next)
        cout<<(*p)->get_data()<<endl;
    return 1;

}

