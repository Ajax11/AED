#ifndef C_NODE_H
#define C_NODE_H

template <class Type>
class C_Node
{
    public:

        C_Node(Type x);
        virtual ~C_Node();
        Type get_data();
        void set_data(Type x);

        C_Node <Type>* getNext();
        void setNext(C_Node <Type> *p);
        C_Node <Type> * m_next;

    protected:
    private:


        Type m_data;
};

#endif // C_NODE_H


template <class Type>
C_Node <Type> ::C_Node(Type x)
{
    set_data(x);
    m_next=0;
}

template <class Type>
C_Node <Type> ::~C_Node()
{
    //dtor
}

template <class Type>
C_Node <Type>* C_Node<Type>:: getNext()
{
    return m_next;
}

template <class Type>
void C_Node<Type>:: setNext(C_Node<Type>* p)
{
    m_next=p;
}

template <class Type>
Type C_Node <Type> :: get_data()
{
    return m_data;
}


template <class Type>
void C_Node <Type> :: set_data(Type x)
{
    m_data=x;
}
