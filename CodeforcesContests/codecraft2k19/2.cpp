#include<bits/stdc++.h>
/*#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
*/using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double p,s,a,n,k,m,sum=0,avg,count=0,av1,s1,av2,s2;
	cin>>n>>k>>m;
	vector<double> v;
	for(int i=0;i<n;i++){
		cin>>a;
		sum += a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());
	avg = sum/n;
	p=n;

	for(int i=0;i<n;i++){
		if(count >= m){
			break;
		}
		s1 = sum - v[i];
	       	av1 = s1/(p-1);
		s2 = sum + 1;
		av2 = s2/p; 
		if(av1 >= av2){
			if(av1 >= avg){
				cout<<"k"<<endl;
				avg = av1;
				--p;
				sum = s1;
				++count;
			}
		}
		else{
			if(av2 > avg){
				cout<<"d"<<endl;
				avg=av2;
				sum=s2;
				++count;
			//	flag=1;
			//	break;
			}
		}
	}

//	cout<<fixed<<setprecision(8)<<avg<<endl;
	double g = m - count;
	if(g > 0){
		if((k-1)*p >= g){
			sum += g;
			avg = sum/p;
		}
		else{
			sum += (k-1)*p;
			avg = sum/p;
		}
	}

	cout<<fixed<<setprecision(8)<<avg<<endl;
return 0;
}

	
	



