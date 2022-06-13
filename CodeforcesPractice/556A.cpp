#include<iostream>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int zero=0,one=0,n;
	char a;
	vector<int> vec;
	cin>>n;
	char c;
	for(int i=0;i<n;i++){
		a = getc(stdin);
		vec.push_back(a);
	}

	for(int i=0;i<n;i++){
		if(vec[i] == '0'){
			zero++;
		}
		else{
			one++;
		}
	}

	int min = zero < one ? zero : one;
	cout<<n - 2*min<<"\n";
return 0;
}
