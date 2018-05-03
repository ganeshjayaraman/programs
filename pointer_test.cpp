#include<iostream>

using namespace std;

int *getPointer() {
	static int x = 100;
	int *ptr = new int;
	*ptr = 100;
	return ptr;
}

int main()  {
	int *x = getPointer();

	cout<<" x : "<<*x;
}