#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int n,a,b;
	char c;
	vector<int> m(370,0),f(370,0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>a>>b;
		if(c == 'M'){
			for(int i=a;i<=b;i++){
				m[i]++;
			}
		}
		else{
			for(int i=a;i<=b;i++){
				f[i]++;
			}
		}
	}
	
	int sum,max=0;
	for(int i=1;i<=366;i++){
		sum = (m[i] < f[i] ? m[i] : f[i]);
		if(sum > max){
			max = sum;
		}
	}
	
	cout<<2*max<<endl;
return 0;
}

