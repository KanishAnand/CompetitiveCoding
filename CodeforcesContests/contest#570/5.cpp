#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
set<string> an;

lli SubSeqRec(string str, lli n, lli index = -1, string curr = "") { 
	if (index == n) 
		return 0; 

	//cout << curr << "\n"; 
	an.insert(curr);
	for (lli i = index + 1; i < n; i++) { 

		curr += str[i]; 
		SubSeqRec(str, n, i, curr); 
		curr = curr.erase(curr.size() - 1); 
	} 
	return 0; 
} 

lli SubSeq(string str) { 
	SubSeqRec(str, str.size()); 
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;
	string str; 
	cin>>str;
	SubSeq(str); 
	vector<lli> arr(102,0);
	//cout<<an.size()<<endl;
	if(k > an.size()){
		cout<<"-1"<<endl;
		rt;
	}
	for(auto it = an.begin();it!=an.end();it++){
		string y = *it;
		lli l = y.length();
		//cout<<l<<endl;
		arr[l]++;
	}

	lli cost=0;
	for(lli i=101;i>=0;i--){
		//cout<<"K"<<endl;
		if(k == 0){
			//cout<<i<<endl;
			break;
		}
		if(arr[i] != 0){
			if(k == 0){
			//	cout<<i<<endl;
				break;
			}
			if(arr[i] <= k){
				k -= arr[i];
				cost += arr[i]*(n-i);
			}
			else{
				cost += k*(n-i);
				k = 0;
				break;
			}
		}
	}
	cout<<cost<<endl;
rt;
}	
	
