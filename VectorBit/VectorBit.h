#include <iostream>
using namespace std;

class VectorBit
{
	public:

		VectorBit(int Lengh);
		~VectorBit();
		void SetBit(int Pos, bool Value);	
		bool GetBit(int Pos);

	protected:


	private:

		unsigned char* Vector; 
};


VectorBit:: VectorBit(int Lenght)
{
	int temp=Lenght/sizeof(unsigned char);
	if(Lenght%sizeof(unsigned char))
		temp+=1;

	Vector= new unsigned char[temp];

	for(int i=0; i<temp; ++i)
	{
		*(Vector + i) = 0;
	}
}

VectorBit:: ~VectorBit()
{
	delete Vector;
}

void VectorBit:: SetBit(int Pos, bool Value)
{
	if(Value)
	{
		unsigned char temp=1;
		temp<<=(Pos % sizeof(unsigned char));		
		*(Vector + (Pos / sizeof(unsigned char) ) )|=temp;
	}

	unsigned char temp=1;
	temp<<=(Pos % sizeof(unsigned char));
	*(Vector + (Pos / sizeof(unsigned char) ) ) &= (temp);
}

bool VectorBit:: GetBit(int Pos)
{
	unsigned char temp=1;
	temp<<=(Pos % sizeof(unsigned char));	
	return (*(Vector + (Pos / sizeof(unsigned char) ) ) & temp);
}




