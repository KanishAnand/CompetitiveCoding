#include<iostream>
#include<algorithm>
#include<vector>
typedef long long int lli;
lli arx[8000000],ary[8000000];
using namespace std;
int main(void){
	lli n,x,y,a,b;

	for(int i=0;i<n;i++){
		cin>>x>>y;
		arrx[i] = x;
		arry[i] = y;
	}

	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr1x[i] = a;
		arr1y[i] = b;
		arx[a] = 1;
		ary[b] = 1;
	}
	illi px,py;
	for(int i=0;i<n;i++){
		px = arrx[0] + arr1x[i];
		py = arry[0] + arr1y[i];
		for(int j = 1;j<n;j++){
			lli q,w;
			q = px - arrx[j];
			w = py - arry[j];
			if(arx[q] == 1 && ary[w] == 1 && j == n-1){
				cout<<px<<" "<<py<<endl;
				return 0;
			}
			else if(arx[q] == 1 && ary[w] == 1){
				continue;
			}
			else{
				break;
			}
		}
	}
				

return 0;
}

