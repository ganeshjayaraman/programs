#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int get;
	vector<int> v;
	vector <int> :: reverse_iterator ir;
	for(int i=0;i<10;i++) {
		cin>>get; 
		v.push_back(get);
	}

	vector<int>:: iterator it;
	for(it = v.begin(); it!= v.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	for(ir = v.rbegin(); ir!=v.rend(); ir++)
		cout<<*ir<<" ";

	sort(v.begin(), v.end(),greater<int>());
	cout<<endl;
	for(it = v.begin(); it!= v.end(); it++)
		cout<<*it<<" ";
	
	


	return 0;
}