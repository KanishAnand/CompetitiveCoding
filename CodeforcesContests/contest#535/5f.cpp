#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int a,x,y,n,m;	
	vector<int> l,r,v;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a;
		if(a > max){
			max = a;
		}
		if(a < min){
			min = a;
		}
		v.push_back(a);
	}
	int p=max-min;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		l.push_back(x);
		r.push_back(y);
	}

	for(int i=0;i<m;i++){
		for(int j=l[i]-1;j<=r[i]-1;j++){
			v2[j]-=1;
		}
		for(int j=0;j<n;j++){
			if(v2[j] > max){
			       max = v2[j];
		      	}
	 		if(v2[j] < min){
				min = v2[j];
			}
		}
		int q = max - min;
		if(q > p){
			q = p;
			++count;
		}
		else{
			for(int k=0;k<n;k++){

	}		
