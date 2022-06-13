#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(void){
	lli n,a;
	vector<lli> king,cnt;
	cin>>n;
	cnt.resize(n+2);
	king.resize(n+2);
	fill(cnt.begin(),cnt.end(),0);
	for(int i=1;i<=n;i++){
	//	cnt[i]=0;
		king[i] = i;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a != -1){
			king[i] = a;
		}
	}

	//set<lli> st;
	lli max=-1;
	for(int i=1;i<=n;i++){
		lli k=i,c=0;
		while(king[k] != k){
			k = king[k];
			++c;
		}
		if(c > max){
			max = c;
		}
		//st.insert(k);
		//cnt[k]++;
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<cnt[i]<<endl;
	// }

	
	// for(auto it=st.begin();it != st.end();it++){
	// 	if(cnt[*it] > max){
	// 		max = cnt[*it];
	// 	}
	// }
	cout<<max+1<<endl;
return 0;
}