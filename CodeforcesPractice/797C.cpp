#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	string s,ans;
	vector<lli> arr(26,0);
	stack<lli> st;
	cin>>s;
	vector<lli> v(s.length(),0);
	for(lli i=s.length() - 1;i>=0;i--){
		for(lli j=0;j<s[i] - 'a';j++){
			v[i] += arr[j];
		}
		++arr[s[i] - 'a'];
	}	

	lli c=0;
    
	for(lli i=0;i<s.length();i++){
		if(v[i] != 0){
			st.push(i);
		}
		else{
            lli c=0;
			ans.pb(s[i]);

			while(!st.empty()){
                lli x = s.length() - st.top() - 1;
                lli y = s.length() - i - 1;
                c = x - y;
                //cout<<c<<endl;
				if(v[st.top()] - c <= 0){
					ans.pb(s[st.top()]);
					st.pop();
				}
				else{
					break;
				}
			}
		}
	}

	while(!st.empty()){
		ans.pb(s[st.top()]);
		st.pop();
	}

	cout<<ans<<endl;

	
rt;
}
	
