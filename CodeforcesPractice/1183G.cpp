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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,q,a,b;
	
	cin>>q;
	while(q--){
		cin>>n;
		vector<pair<lli,lli>> v;
		vector<lli> arr(n+2,0),arr2(n+2,0);
		fr(i,0,n){
			cin>>a>>b;
			arr[a]++;
			if(b == 1){
				arr2[a]++;
			}
		}

		fr(i,1,n+2){
			if(arr[i] != 0){
				v.pb(make_pair(arr[i],arr2[i]));
			}
		}

		sort(v.begin(),v.end(),greater<>());
		lli sum=0,t = v[0].first,sum2=0;
		vector<lli> cnt(n+2,0);
		set<lli> st;
		lli i=0;
//cout<<v.size()<<endl;

		// fr(i,0,v.size()){
		while(1){
			cout<<t<<endl;
			if(t <= 0){
//				cout<<i<<endl;
				break;
			}
//			cout<<i<<"L"<<endl;
			fr(j,i,v.size()){
				i = j;
				//cout<<v[j].first<<" "<<i<<endl;
				if(v[j].first >= t){
					st.insert(v[j].second);
					cnt[v[j].second]++;
					if(j == v.size() - 1){
						i++;
					}
				}
				else{
					break;
				}
			}
//			cout<<i<<endl;
//cout<<st.size()<<"g"<<endl;
// if(t == 1){
// 	break;
// }
			// if(st.empty()){
			// 	//cout<<"KK"<<endl;
			// 	break;
			// }

			// if(v[i] >= t){
			if(st.empty() == 0){
				cout<<st.size()<<endl;
				cout<<t<<"K"<<i<<endl;
				auto it = st.end();
				--it;
				sum += t;

				sum2 += min(*it,t);
				if(cnt[*it] > 0){
					cnt[*it]--;
				}

				if(cnt[*it] == 0){
					st.erase(it);
				}
				cout<<st.size()<<endl;
			}
			--t;
			//cout<<st.size()<<endl;

			//if(i == v.size() - 1){
			// if(st.empty() == 1){
			// 	t = 0;
			// }
			// else{
			// 	--t;
			// }
			// --t;
			// }
			// else{
			// 	--t;
			// }
			// if(st.empty()){
			// 	if(i == v.size() - 1){
			// 		cout<<"KK"<<endl;
			// 		t = 0;
			// 	}
			// 	else{
			// 		t = v[i].first;
			// 	}
			// }
			// else{
			// 	--t;
			// }
// 			if(i < v.size()){
// 				t = max(t-1,v[i+1].first);
// //				cout<<i<<endl;	
// 			}
// 			else if(st.empty() == 0){
// 				--t;
// 			}
// 			else{
// 				t = 0;
// 				//cout<<"F"<<endl;
// 				break;
// 			}
//			cout<<i<<"DF"<<endl;
			
			//}

			// else if(v[i] > t){
			// 	sum += t;
			// 	--t;
			// }

			// else{
			// 	sum += v[i];
			// 	t = v[i] - 1;
			// }
		}
		cout<<sum<<" "<<sum2	<<"\n";

	}	
rt;
}

	
