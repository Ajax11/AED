#ifndef CLESS_H_INCLUDED
#define CLESS_H_INCLUDED

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

#endif // CLESS_H_INCLUDED
