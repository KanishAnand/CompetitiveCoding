#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,endd) for(lli va=beg;va<endd;va++)
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

lli n,beg=0,endd=0;
vector<char> an;
vector<lli> v;
lli ch;

lli fun(){
	lli c1=1,c2=1;
	for(lli i=beg;i<endd;i++){
		if(v[i+1] <= v[i]){
			break;
		}
		else{
			++c1;
		}
	}
	
	for(lli i=endd;i>beg;i--){
		if(v[i-1] <= v[i]){
			break;
		}
		else{
			++c2;
		}
	}
	if(c1 > c2){
		for(int i=0;i<c1;i++){
			++beg;
			an.pb('L');
		}
	}
	else{
		for(int i=0;i<c2;i++){
			--endd;
			an.pb('R');
		}
	}
rt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	lli a;
	cin>>n;	
	endd=n-1;
	fr(i,0,n){
		cin>>a;
		v.pb(a);
	}

	if(v[beg] < v[endd]){
		ch=v[beg];
		beg++;
		an.pb('L');
	}
	else if(v[beg] > v[endd]){
		ch = v[endd];
		endd--;
		an.pb('R');
	}
	else{
		fun();
		cout<<an.size()<<endl;
		fr(i,0,an.size()){
			cout<<an[i];
		}
		cout<<endl;
		rt;
	}

	while(beg <= endd && an.size() < n){
		if(v[beg] < v[endd]){
			if(v[beg] > ch){
				ch = v[beg];
				++beg;
				an.pb('L');
			}
			else if(v[endd] > ch){
				ch = v[endd];
				--endd;
				an.pb('R');
			}
			else{
				break;
			}
		}
		else if(v[endd] < v[beg]){
			if(v[endd] > ch){
				ch = v[endd];
				--endd;
				an.pb('R');
			}
			else if(v[beg] > ch){
				ch = v[beg];
				++beg;
				an.pb('L');	
			}
			else{
				break;
			}
		}
		else if(v[beg] == v[endd] && v[beg] > ch){
			if(beg == endd){
				an.pb('L');
				++beg;
				break;
			}
			else{
				fun();
				cout<<an.size()<<endl;
				fr(i,0,an.size()){
					cout<<an[i];
				}
				cout<<endl;
				rt;
			}
		}
		else{
			break;
		}
	}	
	
	cout<<an.size()<<endl;
	fr(i,0,an.size()){
		cout<<an[i];
	}
	cout<<endl;
rt;
}
