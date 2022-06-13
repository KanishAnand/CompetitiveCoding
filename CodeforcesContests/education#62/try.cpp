#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> &ve){
	vector<int>::iterator itr;
	for(itr = ve.begin();itr != ve.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
	ve.push_back(3);
	for(itr = ve.begin();itr != ve.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
	//cout<<ve<<endl;
return 0;
}

int main(void){
	vector<int> v{1,4,3,5};
	vector<int>::iterator itr;
	for(itr = v.begin();itr != v.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
	fun(v);
	for(itr = v.begin();itr != v.end();itr++){
		cout<<*itr<<" ";
	}
	//cout<<v.end();
}