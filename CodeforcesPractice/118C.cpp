#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
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

vector<lli> arr(10,0);
//set<lli> s;
lli last(auto endd,auto a,auto cost,auto i);
lli first(auto beg,auto a,auto cost,auto i);

lli last(auto endd,auto a,auto cost,auto i){
	if(arr[*endd] >= *a){
		*cost = *cost + (*endd - *i)*(*a);
		*a = 0;
		(*endd)++;
		return 0;
	}
	else{
		*cost = *cost + (*endd - *i)*arr[*endd];
		//cout<<*cost<<endl;
		*a = *a - arr[*endd];
		(*endd)++;
	}
return 0;
}

lli first(auto beg,auto a,auto cost,auto i){
	if(arr[*beg] >= *a){
		*cost = *cost + (*i - *beg)*(*a);
		*a = 0;
		(*beg)--;
		return 0;
	}
	else{
		*cost = *cost + (*i - *beg)*arr[*beg];
		*a = *a - arr[*beg];
		(*beg)--;
	}
rt;
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,k;
	cin>>n>>k;	
	string st;
	cin>>st;
	fr(i,0,st.length()){
		arr[st[i] - '0']++;
		if(arr[st[i] - '0'] >= k){
			cout<<"0"<<endl<<st<<endl;
			rt;
		}
	}
	

	lli minn=10000000000;
	vector<lli> v;
	for(lli i=0; i<=9; i++){
		lli a = k - arr[i],cost=0;
		lli endd=i+1,beg=i-1;
		while(1){
			if(a == 0){
				break;
			}
			if(beg < 0){
				last(&endd,&a,&cost,&i);
			}
			else if(endd > 9){
				first(&beg,&a,&cost,&i);
			}
			else if(endd - i <= i - beg){
				last(&endd,&a,&cost,&i);
			}
			else{
				first(&beg,&a,&cost,&i);
			}
		}
		if(cost < minn){
			v.resize(0);
			minn = cost;
			v.pb(i);
			}
		else if(cost == minn){
			v.pb(i);
		}
	}

	cout<<minn<<endl;
	set<string> s;
	lli m=1000000000;
	fr(y,0,v.size()){
		lli i=v[y];
		string stc=st;
		lli a = k - arr[i],cost=0;
		lli endd=i+1,beg=i-1;
		while(1){
			lli org = a,obeg = beg,oend = endd;
			if(a == 0){
				break;
			}
			if(beg < 0){
				last(&endd,&a,&cost,&i);
			}
			else if(endd > 9){
				first(&beg,&a,&cost,&i);
			}
			else if(endd - i <= i - beg){
				last(&endd,&a,&cost,&i);
			}
			else{
				first(&beg,&a,&cost,&i);
			}
			//cout<<org - a<<endl;
			//cout<<obeg<<" "<<beg<<" "<<oend<<" "<<endd<<endl;
			if(org != a){
				lli d = org - a;
				if(oend != endd){
					//cerr<<"q"<<endl;
					for(lli p=0;p<stc.length();p++){
						if(d == 0){
							break;
						}
						if(stc[p] - '0' == oend){
							stc[p] = i + '0';
							--d;
						}
					}
				}
				else{
					//cout<<"o"<<endl;
				//	cout<<"DF"<<i<<endl;
					for(lli p=stc.length()-1;p>=0;p--){
						if(d == 0){
							break;
						}
						if(stc[p] - '0' == obeg){
						//	cout<<stc<<endl;
							stc[p] = i + '0';
						//	cout<<stc<<endl;
							--d;
						}
					}

				}
				//cout<<stc<<endl;
			}
		}
		s.insert(stc);
		//cout<<stc<<endl;
	}
	cout<<*s.begin()<<endl;
rt;
}

	
