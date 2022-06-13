#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long int llu;
int main(void){
	llu n;
	cin>>n;
	llu p = sqrt(n);
	for(llu i=p;i>=2;i--){
		if((n % (i*i)) == 0){
			n /= i;
			i++;
		}
	}

	cout<<n<<endl;
return 0;
}


