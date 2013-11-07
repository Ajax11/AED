#ifndef CTRAITS_H_INCLUDED
#define CTRAITS_H_INCLUDED

#include "CNode.h"


template <class Type>
class CLess
{
    public:
        CLess(){}
        virtual ~CLess(){}
        inline bool operator()(Type a, Type b)
                {
                    return a<b;
                }
    protected:
    private:
};

template <class Type>
class CGreader
{
    public:
        CGreader(){}
        virtual ~CGreader(){}
        inline bool operator()(Type a, Type b)
                {
                    return a>b;
                }
    protected:
    private:
};

template < class Type>
class abc
{
    public:

        //para acceder al ijo izquierdo usar l
        //para acceder al ijo derecho usar r

        enum ValueState { s = 1 , l , r , u , StartState = l};

        int operator () (int state)
        {
            switch(state)
            {
                case l:
                    return s;
                case s:
                    return r;
                case r:
                    return u;
            }
        }

    protected:

    private:

};

template < class Type>
class acb
{
};

template < class Type>
class bac
{
};

template < class Type>
class bca
{
};

template < class Type>
class cba
{
};

template < class Type>
class cab
{
};

template < class Tr >
class CTrait
{
    public:

        typedef Tr Type;
        typedef CNode<Type> Node;
        typedef CLess<Tr> OTree;

		typedef abc <Type> InOrder;
		typedef cba <Type> Reverse;
		typedef bac <Type> PreOrder;
		typedef acb <Type> PostOrder;



};


#endif // CTRAITS_H_INCLUDED
