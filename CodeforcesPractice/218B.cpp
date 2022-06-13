#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxsum=0,n,m,a,sum=0;
	cin>>n>>m;
	vector<int> v,s;
	for(int i=0;i<m;i++){
		cin>>a;
		sum += a;
		v.push_back(a);
		s.push_back(a);
	}

	int count=0;
	int minsum = 0;
	sort(v.begin(),v.end());        //see this step
	
	for(int i=0;i<m;){
		if(count == n){
			break;
		}
		if(v[i] != 0){
			++count;
			minsum += v[i];
			--v[i];
		}
		else{
			i++;
			continue;
		}
	}
	
	if(sum == n){
		cout<<minsum<<" "<<minsum<<"\n";
		return 0;
	}

	else{
		sort(s.begin(),s.end());
		count=0;
		while(count != n){
				++count;
				maxsum += s[m-1];
				--s[m-1];
				sort(s.begin(),s.end());
		}
	}
	cout<<maxsum<<" "<<minsum<<"\n";
return 0;
}



