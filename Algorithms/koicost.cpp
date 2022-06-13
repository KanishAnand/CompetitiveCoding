#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod=1000000000;
lli valu=0,size[100005],pairs=0;
struct edge{
	lli src;
	lli des;
	lli wt;
};

vector<struct edge> ed;
lli king[100005];

bool cmp(edge &a,edge &b){
	return (a.wt < b.wt );
}

lli find(lli val){
	if(king[val] == val){
		return val;
	}
	king[val] = find(king[val]);
return king[val];
}

lli merge(lli a,lli b){
	if(size[a] < size[b]){
		king[a] = king[b];
		size[b] += size[a];
		size[b] %= mod;
	}
	else if(size[a] == size[b]){
		king[a] = king[b];
		size[b] += size[a];
		size[b] %= mod;
		//++rankk[b];
	}
	else{
		king[b] = king[a];
		size[a] += size[b];
		size[a] %= mod;
	}
return 0;
}

int main(void){
	lli n,m,a,b,c;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		struct edge t;
		cin>>t.src>>t.des>>t.wt;
		ed.push_back(t);
	}

	sort(ed.begin(),ed.end(),cmp);

	vector<struct edge> :: iterator itr;
	//lli mst = 0;
	for(int i=1;i<=n;i++){
		king[i] = i;
		//rankk[i] = 0;
		size[i] = 1;
	}

	// for(itr = ed.begin();itr < ed.end();itr++){
	// 	king[itr->des] = itr->src;
	// }
	if(m == 0){
		cout<<"0"<<endl;
		return 0;
	}

	for(itr = ed.end() - 1; itr >= ed.begin(); itr--){
		int c = find(itr->src);
		int d = find(itr->des);
		if(c != d){
			//mst += itr->wt;
			size[c] %= mod;
			size[d] %= mod;
			pairs += size[c]*size[d];
			pairs %= mod;
			// itr->wt %= mod;
			// val += itr->wt * pairs;
			// val %= mod;
			merge(c,d);
		}

		valu += itr->wt * pairs;
		valu %= mod;
	}
	cout<<valu<<endl;
return 0;
}

