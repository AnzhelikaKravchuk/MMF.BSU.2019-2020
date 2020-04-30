#include "IntegerWrapper.h"

void F(IntegerWrapper& wrapper);

int main()
{
	//IntegerWrapper iw, iw1(90), iw2(iw);

	////cout << " object = " << iw << endl;
	////cout << " object = " << iw1 << endl;	
	//iw = 132.345;
	////vs
	//// IntegerWrapper anonim(132.345);
	//// iw = anonim;
	//cout << " object = " << iw << endl;
	//IntegerWrapper wrapper = iw;
	//F(iw);
	////iw1 = iw;

	IntegerWrapper*arr = new IntegerWrapper[5];
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;
	delete[] arr;
}

void F(IntegerWrapper& wrapper)
{
	cout << "in function object = " << wrapper << endl;
} 