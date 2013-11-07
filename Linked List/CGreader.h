#ifndef CGREADER_H_INCLUDED
#define CGREADER_H_INCLUDED

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

#endif // CGREADER_H_INCLUDED
