#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n,vector<lli> &ve);
lli input(lli n,vector<lli> &ve){
	lli val;
	for(lli i=0;i<n;i++){
		cin>>val;
		ve.pb(val);
	}
return 0;
}
lli pp = 1000000000;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,pos=0,neg=0;
	cin>>n;	
	vector<lli> arr1(n+1),arr2(n+1);
	string s;
	fr(i,0,n){
		//cout<<pos<<" "<<i<<endl;
		cin>>s;
		lli l = s.length();
		if(s[l-1] == '0' && s[l-2] == '0' && s[l-3] == '0' && s[l-4] == '0' && s[l-5] == '0'){
			arr1[i] = stoi(s);
			arr2[i] = pp;
			if(arr1[i] > 0){
				pos += arr1[i];
			}
			else{
				neg += arr1[i];
			}
		}
		else{
			lli k = stoi(s);
			//cout<<k<<endl;
			if(k > 0){
				arr1[i] = k+1;
				arr2[i] = k;
				pos += arr1[i];
			}
			else if(k < 0){
				arr1[i] = k-1;
				arr2[i] = k;
				neg += arr1[i];
			}
			else{
				if(s[0] == '-'){
					arr1[i] = k-1;
					arr2[i] = 0;
					neg += arr1[i];
				}
				else{
					arr1[i] = k+1;
					arr2[i] = 0;
					pos += arr1[i];
				}
			}
		}
	}
//cout<<pos<<" "<<neg<<endl;
	lli p=0,ne=0;
//cout<<p<<" "<<ne<<endl;
	if(pos + neg > 0){
		p = pos + neg;
	}
	else if(pos + neg < 0){
		ne = pos + neg;
		ne = -ne;
	}

	if(p > 0){
		fr(i,0,n){
			if(arr2[i] == pp){
				cout<<arr1[i]<<endl;
			}
			else{
				if(arr1[i] > 0){
					if(p > 0){
						cout<<arr2[i]<<endl;
						--p;
					}
					else{
						cout<<arr1[i]<<endl;
					}
				}
				else{
					cout<<arr1[i]<<endl;
				}
			}
		}
	}

	else if(ne > 0){
		fr(i,0,n){
			if(arr2[i] == pp){
				cout<<arr1[i]<<endl;
			}
			else{
				if(arr1[i] < 0){
					if(ne > 0){
						cout<<arr2[i]<<endl;
						--ne;
					}
					else{
						cout<<arr1[i]<<endl;
					}
				}
				else{
					cout<<arr1[i]<<endl;
				}
			}
		}
	}
	else{
		fr(i,0,n){
			cout<<arr1[i]<<endl;
		}
	}
rt;
}
	
