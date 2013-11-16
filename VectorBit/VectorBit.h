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
		int SizeOfUnsignedChar;
};


VectorBit:: VectorBit(int Lenght)
{
	SizeOfUnsignedChar = (sizeof(unsigned char) * 8);

	int temp = Lenght / SizeOfUnsignedChar;
	if(Lenght % SizeOfUnsignedChar)
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
		temp<<=(Pos % SizeOfUnsignedChar);		
		*(Vector + (Pos / SizeOfUnsignedChar ) ) |= temp;
		return;
	}

	unsigned char temp=1;
	temp<<=(Pos % SizeOfUnsignedChar);
	*(Vector + (Pos / SizeOfUnsignedChar ) ) &= (~temp);
}

bool VectorBit:: GetBit(int Pos)
{
	unsigned char temp=1;
	temp<<=(Pos % SizeOfUnsignedChar);	
	(temp &= *(Vector + (Pos / SizeOfUnsignedChar ) ));
	return bool(temp);
}




