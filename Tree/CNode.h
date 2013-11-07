#ifndef CNODE_H_INCLUDED
#define CNODE_H_INCLUDED

template < class Type >
class CNode
{
    public:

        CNode( Type data_ );
        CNode( const CNode & a );
        ~CNode();

        Type getData();
        void setData( Type data_ );
        CNode <Type> * getLeaf();
        void setLeaf( CNode <Type> *l , int dir ); //revizar
        void setLeaf();
        CNode<Type>* & getLeaf(int dir);

    protected:

    private:

        CNode<Type>* m_leaf[2];
        Type m_data;

};

#endif // CNODE_H_INCLUDED


template   < class Type >
CNode <Type> :: CNode( Type data_ )
{
    setData( data_);
    setLeaf();
}

template   < class Type >
CNode <Type> :: CNode(const CNode & a )
{
    setData( a.getData() );
    setLeaf( a.getLeaf() );
}

template < class Type >
CNode<Type>:: ~CNode(){}

template < class Type >
void CNode <Type> :: setData( Type data_)
{
    m_data = data_;
}

template < class Type >
Type CNode <Type> :: getData()
{
    return m_data;
}

template < class Type >
void CNode<Type>:: setLeaf(CNode <Type> *l , int dir)
{
    m_leaf[dir]=l[dir];
}

template < class Type >
void CNode < Type > :: setLeaf()
{
    m_leaf[0]=0;
    m_leaf[1]=0;
}

template < class Type >
CNode<Type>* & CNode<Type> :: getLeaf(int dir)
{
    return *(m_leaf+dir);
}


