#ifndef CNODE_H_INCLUDED
#define CNODE_H_INCLUDED

template < class Type >
class CNode
{
    public:

        CNode( Type data_ );
        CNode( const CNode & a );
        ~CNode();

        Type GetData();
        void SetData( Type data_ );
        CNode <Type> * GetLeaf();
        void SetLeaf( CNode <Type> *l , int dir ); //revizar
        void SetLeaf();
        CNode<Type>* & GetLeaf(int dir);


        void SetHeight( int );
        int GetHeight();

    protected:

    private:

        CNode<Type>* MLeaf[2];
        Type MData;
        int Height;
};

#endif // CNODE_H_INCLUDED


template   < class Type >
CNode <Type> :: CNode( Type data_ )
{
    SetData( data_);
    SetLeaf();
    SetHeight(0);
}

template < class Type >
void CNode< Type > :: SetHeight( int a )
{
    Height = a;
}

template < class Type >
int CNode < Type > :: GetHeight()
{
    return Height;
}


template   < class Type >
CNode <Type> :: CNode(const CNode & a )
{
    SetData( a.GetData() );
    SetLeaf( a.GetLeaf() );
}

template < class Type >
CNode<Type>:: ~CNode(){}

template < class Type >
void CNode <Type> :: SetData( Type data_)
{
    MData = data_;
}

template < class Type >
Type CNode <Type> :: GetData()
{
    return MData;
}

template < class Type >
void CNode<Type>:: SetLeaf(CNode <Type> *l , int dir)
{
    MLeaf[dir]=l[dir];
}

template < class Type >
void CNode < Type > :: SetLeaf()
{
    MLeaf[0]=0;
    MLeaf[1]=0;
}

template < class Type >
CNode<Type>* & CNode<Type> :: GetLeaf(int dir)
{
    return *(MLeaf+dir);
}
