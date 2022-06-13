#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int n,l,r;
	vector<int> p(300,0),q(300,0);
	char s[100005];
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		++p[s[i]];
		++q[s[i]];
	}
	
	for(int i=0;i<n;i++){
		if(p[s[i]] == 1){
			l = i;
			break;
		}
		else{
			--p[s[i]];
		}
	}

	for(int i=n-1;i>=0;i--){
		if(p[s[i]] == 1){
			r = i;
			break;
		}
		else{
			--p[s[i]];
		}
	}
	
	int  m = r-l+1;
	for(int i=n-1;i>=0;i--){
		if(q[s[i]] == 1){
			r = i;
			break;
		}
		else{
			--q[s[i]];
		}
	}

	for(int i=0;i<n;i++){
		if(q[s[i]] == 1){
			l = i;
			break;
		}
		else{
			--q[s[i]];
		}
	}
	int n1=r-l+1;
	int min = m < n1 ? m : n1;
	cout<<min<<endl;
return 0;
}

