#include<iostream>
#include<algorithm>
using namespace std;
//int minm(int a,int b);
int main(void){
	int a,n,max=-1000000,max2=-1000000,min=200000,min2=200000;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a >= max){
			max2 = max;
			max = a;
		}
		else if(a > max2 && a < max){
			max2 = a;
		}
		if(a <= min){
			min2 = min;
			min = a;
		}
		else if(a < min2 && a > min){
			min2 =a;
		}
	}

	a = std::min(max2 - min,max - min2);
	cout<<a<<endl;
return 0;
}
	

	
