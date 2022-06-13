#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
// struct data{
// 	lli x;
// 	lli y;
// 	lli t;
// };

// lli input(lli n);
// lli max_of_all();
vector<lli> v,v2;
// lli input(lli n){
// 	lli val;
// 	for(lli i=0;i<n;i++){
// 		cin>>val;
// 		v.push_back(val);
// 	}
// return 0;
// }

// lli max_of_all(vector<lli> &vec){
// 	auto itr = max_element(vec.begin(),vec.end());
// return *itr;
// }

// bool cmpr(struct data n1,struct data n2){
// 		if(n1.y != n2.y){
// 			return n1.y < n2.y;
// 		}
// 		else{
// 			return n1.x > n2.x;
// 		}
// }

// bool cmpl(struct data n1,struct data n2){
// 		if(n1.x != n2.x){
// 			return n1.x > n2.x;
// 		}
// 		else{
// 			return n1.y < n2.y;
// 		}
// }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	cin>>n;	
	//input(n);
	lli a,b,sum=0;
	//struct data nod[n+5];
	//struct data nod1[n+5];

	for(int i=0;i<n;i++){
		cin>>a>>b;
		sum += b*n - a;
		if(a >= b){
			v.push_back(a-b);
		}
		else{
			v2.push_back(b-a);
		}
		// nod[i].x = a;
		// nod[i].y = b;
		// nod1[i].x = a;
		// nod1[i].y = b;
	}

	sort(v.rbegin(),v.rend());
	sort(v2.begin(),v2.end());

	for(int i=0;i<v.size();i++){
		sum += v[i]*(i+1);
	}
//cout<<sum<<endl;
	for(int i=0;i<v2.size();i++){
		sum -= v2[i]*(i+v.size()+1);
	}
	cout<<sum<<endl;

// for(int i=0;i<n;i++){
// 		cout<<nod[i].x<<endl;
// 	//	val1 += nod[i].x*i + nod[i].y*(n-1-i);
// 	}
	// sort(nod,nod+n,cmpr);
	// lli val1=0,val2=0;

	// for(int i=0;i<n;i++){
	// 	cout<<nod[i].x<<" "<<nod[i].y<<endl;
	// 	val1 += nod[i].x*i + nod[i].y*(n-1-i);
	// }

	// sort(nod1,nod1+n,cmpl);

	// for(int i=0;i<n;i++){
	// 	cout<<nod1[i].x<<" "<<nod1[i].y<<endl;
	// 	val2 += nod1[i].x*i + nod1[i].y*(n-1-i);
	// }
	// cout<<val1<<" "<<val2<<endl;
	// cout<<min(val1,val2)<<endl;
return 0;
}


