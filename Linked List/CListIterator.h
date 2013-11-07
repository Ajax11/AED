#ifndef CLISTITERATOR_H_INCLUDED
#define CLISTITERATOR_H_INCLUDED

#include "C_Node.h"

template <class Type>
class CListIterator
{
    public:

        CListIterator( C_Node<Type>* p=0);
        CListIterator( const CListIterator <Type> * & p);

        virtual ~CListIterator(){}
        C_Node <Type> * m_i;

        inline CListIterator <Type> & operator ++ (int);
        inline CListIterator <Type> & operator ++ ();
        inline CListIterator <Type> & operator = (const CListIterator <Type> & i);
        inline bool  operator != (CListIterator <Type>  i);
        inline Type  operator * ();

    protected:

    private:
};


#endif // CLISTITERATOR_H_INCLUDED


template<class Type>
CListIterator<Type>::CListIterator(C_Node <Type> * p)
{
    m_i=p;
}


template<class Type>
CListIterator<Type>::CListIterator (const CListIterator<Type>* & p)
{
    m_i=p.m_i;
}


template <class Type>
CListIterator <Type>& CListIterator<Type>:: operator ++()
{
    CListIterator <Type> it(m_i);
    m_i=m_i->m_next;
    return it;
}

template <class Type>
CListIterator <Type>& CListIterator<Type>:: operator ++(int)
{
    m_i=m_i->m_next;
    return *this;
}


template <class Type>
CListIterator <Type> &CListIterator<Type>:: operator = (const CListIterator <Type> &  i)
{
    m_i=i.m_i;
    return *this;
}


template <class Type>
bool  CListIterator<Type>:: operator != (CListIterator <Type>  i)
{
    return ((this->m_i) != (i.m_i));
}


template <class Type>
Type  CListIterator<Type>:: operator *()
{
    return m_i->get_data();
}
