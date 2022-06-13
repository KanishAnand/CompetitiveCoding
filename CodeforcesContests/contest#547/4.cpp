#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
lli count1[30],count2[30],arr1[200000],arr2[200000];
lli str1[30][200000],str2[30][200000];

int min(int a,int b){
	return a < b ? a : b;
}

int max(int a,int b){
	return a > b ? a : b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n,sum=0;
	char a[200000],b[200000];
	cin>>n;
	cin>>a>>b;
	for(int i=0;i<n;i++){
		if(a[i] != '?'){
			str1[a[i] - 97][count1[a[i] - 97]] = i;
			++count1[a[i] - 97];
		}
		else{
			str1[26][count1[26]] = i;
			++count1[26];
		}
	}

	for(int i=0;i<n;i++){
		if(b[i] != '?'){
			str2[b[i] - 97][count2[b[i] - 97]] = i;
			++count2[b[i] - 97];
		}
		else{
			str2[26][count2[26]] = i;
			++count2[26];
		}
	}

	lli k=0;
	for(int i=0;i<26;i++){
		lli q = min(count1[i],count2[i]);
		for(int j=0;j<q;j++){
			arr1[k] = str1[i][count1[i] - 1];
			arr2[k] = str2[i][count2[i] - 1];
			--count1[i];
			--count2[i];
			++k;
		}
	}

	lli i = 0;

	if(count1[26] != 0){
//		cout<<"k"<<endl;
		while(count1[26] && i < 27){
			while(count1[26] && count2[i] && i <= 26){
				arr1[k] = str1[26][count1[26] - 1];
				arr2[k] = str2[i][count2[i] - 1];
				--count2[i];
				--count1[26];
				++k;
			}
			++i;
		}
	}
//cout<<"k"<<endl;
	i = 0;
	if(count2[26] != 0){
		//cout<<"k"<<endl;
		while(count2[26] && i < 27){
			while(count2[26] && count1[i] && i <= 26){
				arr2[k] = str2[26][count2[26] - 1];
				arr1[k] = str1[i][count1[i] - 1];
				--count1[i];
				--count2[26];
				++k;
			}
			++i;
		}
	}


	cout<<k<<endl;
	for(int i=0;i<k;i++){
		cout<<arr1[i] + 1<<" "<<arr2[i]+1<<endl;
	}
	// for(int i=0;i<27;i++){
	// 	cout<<i<<" "<<count1[i]<<" "<<count2[i]<<endl;
	// }

	// for(int i=0;i<26;i++){
	// 	sum += min(count1[i],count2[i]);
	// }
	// sum += max(count1[26],count2[26]);
	// cout<<sum<<endl;

return 0;
}
