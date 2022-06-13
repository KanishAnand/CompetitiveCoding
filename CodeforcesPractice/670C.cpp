#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int n,m,a,v[200004];
	vector<int> arr,arr2,arr3;
	vector<int>::iterator low,upp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	cin>>m;
	int j,b,c,max=-1,count;
	for(int i=0;i<m;i++){
		cin>>b;
		arr3.push_back(b);
		low = lower_bound(arr.begin(),arr.end(),b);
		upp = upper_bound(arr.begin(),arr.end(),b);        //make case if it is last element;
		count = upp - low;
		if(b == arr[n-1]){
			count = arr.end() - low;
		}
		if(count > max){
			max = count;       
			v[1] = i;
	   		j=2;		//storing index of max occuring index;
		}
		else if(count == max){
			v[j] = i;
			j++;
		}
	}
	//size of v array = j-1;
	for(int i=0;i<m;i++){
		cin>>c;
		arr2.push_back(c);
	}
	max = -1;
	int key;
//	cout<<"j="<<j<<" ";
//	cout<<v[1]<<endl;
	for(int i=1;i<=j-1;i++){
		low = lower_bound(arr.begin(),arr.end(),arr2[v[i]]);
		upp = upper_bound(arr.begin(),arr.end(),arr2[v[i]]);
		count = upp - low;
//		cout<<"K"<<arr2[v[i]]<<" ";
	//	cout<<"D"<<count<<" ";
		if(arr2[v[i]] == arr[n-1]){
			count = arr.end() - low;
		}
		if(count > max){
			max = count;
			key = v[i];
		}
	}
	cout<<key + 1<<endl;
return 0;
}








