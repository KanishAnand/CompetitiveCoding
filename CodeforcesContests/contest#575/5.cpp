#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0
lli input(lli n,vector<lli> &ve);
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
	lli q,n,k;
	vector<lli> v;
	cin>>q;
	while(q--){
		cin>>n>>k;
		string st;
		cin>>st;
		lli minn = 1000000000;
		string s1 = "RGB",s2 = "GBR",s3="BRG";
		
		for(lli i=0;i<n-k+1;i++){
			lli p=0,ch=0,on=0,tw=0;
			lli j;
			for(j=i;j<i+k;j++){
				if(st[j] != s1[p%3]){
					//cout<<st[j]<<" "<<s1[p%3]<<endl;
					++ch;
					if(st[j] == s1[(p+1)%3]){
						if(j != i){
							++on;
						}
					}
					else if(st[j] == s1[(p+2)%3]){
						if(j != i && j != i+1){
							++tw;
						}
					}
					++p;
				}
			}
			//cout<<ch<<endl;
			if(ch < minn){
				minn = ch;
			}

			if(j+1 < n && k != 1){
				if(st[i] != s1[0]){
					--ch;
				}
				lli x = ch + k - on;
				if(st[j+1] != s1[(k-1)%3]){
					if(st[j+1] == s1[k%3]){
						++tw;
					}
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}

			if(j + 2 < n && k != 2){
				if(st[i+1] != s1[1]){
					--ch;
				}
				lli x = ch + k - tw;
				if(st[j+2] != s1[(k-1)%3]){
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}

			i = i+k-1;

		}
//		cout<<minn<<endl;

		for(lli i=0;i<n-k+1;i++){
			lli p=0,ch=0,on=0,tw=0;
			lli j;
			for(j=i;j<i+k;j++){
				if(st[j] != s2[p%3]){
					++ch;
					if(st[j] == s2[(p+1)%3]){
						if(j != i){
							++on;
						}
					}
					else if(st[j] == s2[(p+2)%3]){
						if(j != i && j != i+1){
							++tw;
						}
					}
				++p;
				}
				//++p;
			}
			if(ch < minn){
				minn = ch;
			}
			//cout<<on<<" "<<tw<<endl;
			//cout<<minn<<"K"<<endl;
			if(j+1 < n && k != 1){
				if(st[i] != s2[0]){
					--ch;
				}
				lli x = ch + k - on;
				if(st[j+1] != s2[(k-1)%3]){
					if(st[j+1] == s2[k%3]){
						++tw;
					}
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}
			//cout<<minn<<"d"<<endl;
			if(j + 2 < n && k != 2){
				if(st[i+1] != s2[1]){
					--ch;
				}
				lli x = ch + k - tw;
				if(st[j+2] != s2[(k-1)%3]){
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}

			i = i+k-1;

		}
		//cout<<minn<<endl;
		for(lli i=0;i<n-k+1;i++){
			lli p=0,ch=0,on=0,tw=0;
			lli j;
			for(j=i;j<i+k;j++){
				if(st[j] != s3[p%3]){
					++ch;
					if(st[j] == s3[(p+1)%3]){
						if(j != i){
							++on;
						}
					}
					else if(st[j] == s3[(p+2)%3]){
						if(j != i && j != i+1){
							++tw;
						}
					}
				++p;
				}
				//++p;
			}
			if(ch < minn){
				minn = ch;
			}
			if(j+1 < n && k != 1){
				if(st[i] != s3[0]){
					--ch;
				}
				lli x = ch + k - on;
				if(st[j+1] != s3[(k-1)%3]){
					if(st[j+1] == s3[k%3]){
						++tw;
					}
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}

			if(j + 2 < n && k != 2){
				if(st[i+1] != s3[1]){
					--ch;
				}
				lli x = ch + k - tw;
				if(st[j+2] != s3[(k-1)%3]){
					++x;
				}
				if(x < minn){
					minn = x;
				}
			}

			i = i+k-1;

		}
		cout<<minn<<endl;
	}	
rt;
}
	
