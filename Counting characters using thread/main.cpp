#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
#include <vector>
#include <thread>
#include <mutex>

using namespace std;


void PlusVector( vector<int> & a, const vector<int> & b )
{
    for(int i=0; i<10; ++i)
    {
        a[i] = a[i] + b[i];
    }
}


void PrintNumberOfCaracter (vector<int> PrintVec, char ElementInit)
{
    for (int i = 0; i < 10; ++i)
    {
        cout<< char(ElementInit + i) << " :  " << PrintVec[i] << endl;
    }
}


template<class T>
void CountCharacters ( Matrix<T>* PtrMatrix, int Init, int Long, vector<int>* VecResult)
{
    for (int i = Init; i < (Init + Long) ; ++i)
    {
        T Element = PtrMatrix->GetElement(i);
        for (int j = 0; j < 10; ++j)
        {
	    	if ( (char('a' + j)) ==  Element)
            {
                (*VecResult)[j] = ((*VecResult)[j]+1);
            }
        }
    }
}

int main()
{
    int i, NThreads = thread::hardware_concurrency();
    thread* ths = new thread[NThreads];
    Matrix<char>* MatrixChar;
    size_t M=1000,N=1000;

    vector<char> VCad;
    for(char j = 'a'; j <= 'j'; j++)
    {
        VCad.push_back(j);
    }

    vector< vector<int> > VectorResult(NThreads, vector<int> (10,0));

    MatrixChar = new Matrix<char> (M,N);

    for(size_t i=0; i < M*N; ++i)
    {
        MatrixChar->SetElement(VCad[rand()%10], i);
    }

cout<<endl<<"last"<<endl;

    int temp;

    temp = ( (N * M) / NThreads );

cout<<"Temp equivale a:"<<temp<<endl;

    for ( i = 0; (i < NThreads); i++ )
    {
			cout<<endl<<i<<endl;
        ths[i] = thread(CountCharacters<char>,MatrixChar, ( i*temp ) , ( (i+1) *temp ), &VectorResult[i] );
    }


cout<<endl<<"last"<<endl;



    for ( i = 0; i < NThreads; i++ )
       	ths[i].join();



cout<<endl<<"last"<<endl;



    for(size_t i=0; i < VectorResult.size(); ++i)
    {
        PlusVector(VectorResult[0], VectorResult[i]);
    }


cout<<endl<<"last"<<endl;



    PrintNumberOfCaracter(VectorResult[0], 'a');

	size_t temp1=0;
	for(int i = 0; i<10;++i)
	{
		temp1+=VectorResult[0][i];
	}
	
	cout<<endl<<temp1<<endl;


cout<<endl<<"last"<<endl;



    delete[] ths;

    return 0;
}


//				g++ -std    =c++11 main.cpp -pthread
