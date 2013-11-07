#ifndef CTRAIT_H_INCLUDED
#define CTRAIT_H_INCLUDED

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

template < class Tr >
class CTrait
{
    public:

        typedef Tr Type;
        typedef CNode<Type> Node;
        typedef CLess<Tr> OTree;

};


#endif // CTRAIT_H_INCLUDED
