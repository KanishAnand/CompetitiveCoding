#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int n,a,max=0,min=100003;
	vector<int> v(100004),p(100004);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a > max){
			max = a;
		}
		if(a < min){
			min = a;
		}
		++v[a]; 
	}
	int sum=0;
	for(int i=min;i<=max;i++){
		if(v[i] != 0){
			p[i] = v[i]*i - v[i+1]*(i+1);
			p[i+1] = v[i+1]*(i+1) - v[i]*i - v[i+2]*(i+2);
			if(p[i] >= p[i+1]){
				v[i+1] = 0;
				sum += v[i]*i;
				++i;
			}
			else{
				sum += v[i+1]*(i+1);
				v[i] = 0;
				v[i+2] = 0;
				i = i+2;
			}

		}
	}
	
	cout<<sum<<endl;
return 0;
}


