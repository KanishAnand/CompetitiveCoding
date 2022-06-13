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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,a,x,ans=0;
	vector<lli> b,pending;
	multiset<lli> p,pe;
	cin>>n>>m>>a;	
	lli o=a;
	fr(i,0,n){
		cin>>x;
		b.pb(x);
	}
	fr(i,0,m){
		cin>>x;
		p.insert(x);
		pe.insert(x);
	}
	sort(b.begin(),b.end());

	fr(i,0,n){
		if(p.empty()){
			break;
		}
		//auto it=lower_bound(p.begin(),p.end(),b[i]);
		auto it = p.lower_bound(b[i]);
		//cout<<*it<<endl;
		//cout<<"F";
		if(it != p.end()){
			if(b[i] == *it){
				p.erase(it);
				//qe.insert(*it);
				//sum += *it;
				++ans;
			}
			else{
				if(it != p.begin()){
					--it;
					++ans;
					p.erase(it);
					//qe.insert(*it);
					//sum += *it;
				}
				else{
					pending.pb(b[i]);
				}
			}
		}
		else{
			++ans;
			auto q = --it;
			//qe.insert(*q);
			//sum += *q;
			p.erase(q);
		}
	}	

	lli sum2=0,in = pending.size(),sum3=0;
	in--;
	cout<<ans<<endl;
	//cout<<pending.size()<<endl;
//cout<<sum<<endl;
	while(!p.empty() && in >= 0){
		if(a + pending[in] >= *p.begin()){
			//qe.insert(*p.begin());
			//sum2 += *p.begin();
			//sum3 += pending[in];
			a -= (*p.begin() - pending[in]);
			++ans;
			p.erase(p.begin());
			pending.pop_back();
			--in;
		}
		else{
			break;
		}
	}
	cout<<ans<<endl;
	auto itr = pe.begin();
	lli t = ans,su=0;

	while(t > 0){
		su += *itr;
		--t;
		itr++;
	}

	su -= o;
	if(su < 0){
		su = 0;
	}
	cout<<ans<<" "<<su<<endl;
rt;
}


