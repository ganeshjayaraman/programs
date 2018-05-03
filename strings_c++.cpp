#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1;
	char str2[100];
	getline(cin,str1);

	str1.copy(str2,str1.length(),0);
	cout<<str2<<" "<<str1.length()<<" "<<endl;
	str1.append(str2,str1.length()+1,str1.length());

	//str1.swap(str2);

	cout<<"String is : "<<str1<<" "<<str2;
}