#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(void){
	vector<int> v;
	vector<int>::iterator ptr;
	for(int i=1;i<=5;i++){
		v.push_back(i);
	}
//	int *p = v[0];
	for(ptr = v.begin();ptr<v.end();ptr++){
		cout<<&(*ptr)<<" ";
	}
	cout<<endl<<*ptr;
//	cout<<endl;
//	printf("%d\n",*p);
/*	for(p; p < v.end();p++){
		cout<<*p<<" ";
	}
*/	cout<<endl;
return 0;
}
	
