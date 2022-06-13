#include<iostream>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,n,m,max=0,key,arr[400],k=-1;
	cin>>n>>m;
	vector<int> v;
	
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
		if(a > max){
			max = a;
		}
	}

	for(int i=0;i<n;i++){
		if(v[i] == max){
			++k;
			arr[k] = i+1;
		}
	}
	int x,y;
	vector<int> l,r;

	for(int i=0;i<m;i++){
		cin>>x>>y;
		l.push_back(x);
		r.push_back(y);
	}
	
	int v2[400];
	int mc=-10000;
	int av[400];
	++k;
	for(int i=0;i<k;i++){
		int p=arr[i],s=-1;
		for(int g=0;g<n;g++){
			v2[g] = v[g];
		}
		for(int j=0;j<m;j++){
			if(p <= r[j] && p >= l[j]){
				continue;
			}
			else{
				for(int b=l[j];b<=r[j];b++){
					v2[b-1] -= 1;
				}
				++s;
				av[s] = j+1;
			}
		}
		int min=100000000;

		for(int j=0;j<n;j++){
			if(v2[j] < min){
				min = v2[j];
			}
		}

		int ans = max - min;
		cout<<ans<<endl;
		cout<<max<<" "<<min<<endl;
		if(ans > mc){
		       mc = ans;
	      	}	       
	}

	cout<<mc<<endl;
return 0;
}

