#include<iostream>
using namespace std;
typedef unsigned long long int llu;
int main(void){
	llu n,c,beg,end,a[200005],b[100004];
	cin>>n;
	beg = n/2;
	end = beg+1;
	for(llu i=1;i<=n/2;i++){
		cin>>c;
		b[i] = c;
	}
	c = b[n/2];
	a[beg] = c/2;
	a[end] = c/2 + c % 2;
	beg--;
	end++;
	for(llu i=n/2-1;i>=1;i--){
		c = b[i];
		if(b[i] > b[i+1]){
			a[beg] = a[beg + 1];
			a[end] = c - a[beg];
		}
		else{
			a[end] = a[end - 1];
		       	a[beg] = c - a[end];
		}	
	      	beg--;
       		end++;	       
	}

	for(llu i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
return 0;
}
