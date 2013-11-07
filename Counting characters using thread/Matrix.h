#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

template <class Type>
class Matrix
{
    public:

        Matrix <Type> (int Num1 = 1, int Num2 = 1)
        {
            Row = Num1;
            Colm = Num2;
	    PunteroMatrix.resize(Row);
	    for(int i=0; i<Row; ++i)
	    {
		PunteroMatrix[i].resize(Colm);
	    }
	    
        }

        Matrix <Type> (const Matrix<Type> & MatrixA)
        {
            Row = MatrixA.GetNumberOfRow();
            Colm = MatrixA.GetNumberOfColm();
	    PunteroMatrix(Row, vector<Type> (Colm) );
	
	    for(int i = 0; i < Row; ++i)
	    {
		for(int j = 0; j < Colm; ++j)
			PunteroMatrix[i][j] = MatrixA.GetElement(i + j*i);
	    }

        }
	
	~Matrix <Type>(){}

        Type GetElement(int Pos) const
        {
            int x = (Pos % Row);
			int y = (Pos / Row);
			return PunteroMatrix[x][y];
        }


        int GetNumberOfColm()
        {
            return Colm;
        }

        int GetNumberOfRow()
        {
            return Row;
        }

        void SetElement(Type Elemt, int Pos)
        {
            if ( Pos < Row*Colm )
            {
                PunteroMatrix[0][Pos] = Elemt;
            }
        }

        int* operator [] (int idx)
        {
            return PunteroMatrix[idx];
        }

        friend ostream & operator << (ostream &out, Matrix <Type> & m)
        {
               for(int i=0;i<m.Row;++i)
            {
               for(int j=0;j<m.Colm;++j)
               {
                   out << m.PunteroMatrix[i][j] << "\t";
                   if(j==m.Colm-1)
                   {
                     cout << endl;
                   }
                }
            }
            return out;
        }

        //template <class tipo>
        friend istream & operator >> (istream &input, Matrix <Type> & m)
        {
            for(int i=0;i<m.Row;++i)
              {
                 for(int j=0;j<m.Colm;++j)
                 {
                     input >> m.PunteroMatrix[i][j];
                 }
              }
            return input;
        }

    protected:

    private:

        int Row;
        int Colm;
        vector< vector<Type> > PunteroMatrix;

};

#endif // MATRIX_H
