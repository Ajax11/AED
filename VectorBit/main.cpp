#include <iostream>
#include "VectorBit.h"

using namespace std;

int main()
{

	VectorBit VBit(200);

	VBit.SetBit(75,true);
	VBit.SetBit(145,true);
	VBit.SetBit(65,true);
	VBit.SetBit(85,true);

	cout<<VBit.GetBit(75)<<endl;
	cout<<VBit.GetBit(145)<<endl;
	cout<<VBit.GetBit(65)<<endl;
	cout<<VBit.GetBit(125)<<endl;
	cout<<VBit.GetBit(85)<<endl;
	cout<<VBit.GetBit(5)<<endl;
	cout<<VBit.GetBit(135)<<endl;
	cout<<VBit.GetBit(11)<<endl;

	VBit.SetBit(75,false);

	cout<<VBit.GetBit(75)<<endl;

	cout<<endl;
	return 0;
}

