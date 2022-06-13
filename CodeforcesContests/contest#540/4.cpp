#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,m,a,sumt=0;
	vector<lli> arr;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		sumt += a;
		arr.push_back(a);
	}

	if(m > sumt){
		cout<<"-1"<<endl;
		return 0;
	}
	if(m == sumt){
		cout<<n<<endl;
		return 0;
	}

	sort(arr.rbegin(),arr.rend());

	lli count=1,el;
	for(int i=0;i<n;){
		m -= arr[i];
		++i;
		lli k=i;
		lli sum=0,p=1;
		if(m <= 0){
			break;
		}
		else{
			if(i >= n){
				cout<<"-1"<<endl;
				return 0;
			}

			el = arr[i] - p;
				sum += el;

			while(el > 0 && i < n-1){
				//sum += el;
				++i;
				++p;
				el = arr[i] - p;
				if(el > 0){
					sum += el;
				}
			}

			if(sum >= m){
				break;
			}
			else{
				// ++count;
				i = k;
			}
			// ++count;
		}
		i = k;
		++count;
	}

	cout<<count<<endl;
return 0;
}
