#include<iostream>
#include<algorithm>
using namespace std;
int check();
int check2();
int n,counter=0,a,b,c,p;
int main(void){
	cin>>n>>a>>b>>c;
	if(c > b){
		if(a > b){
			if( a < c){
				swap(a,b);
			}
			else{
				swap(a,c);
				swap(a,b);
			}
		}
	}
	else{
		if(a < b){
			swap(c,b);
			if(a > b){
				swap(a,b);
			}

		}
		else{
			swap(a,c);
		}
	}
		
	p = n/a;
//	cout<<a<<" "<<b<<" "<<c<<"\n";
	check();
//	cout<<n<<" "<<p<<"\n";
	p = n/b;
	check2();
//	cout<<n<<" "<<p<<"\n";
	counter += n/c;
	cout<<counter<<"\n";
return 0;
}

int check(){
	int q = n - p*a;
	if(p <= 0){
		return 0;
	}
	if(q%b == 0 || q%c == 0 || q%(b+c) == 0){
		counter += p;
		n = n - p*a;
		return 0;
	}
	else{
		p = p - 1;
		check();
	}
return 0;
}

int check2(){
	int q = n - p*b;
//	cout<<"kan"<<q<<"\n";
	if(p <= 0){
		return 0;
	}
	if(q % c == 0){
		counter += p;
		n = n - p*b;
		return 0;
	}
	else{
		--p;
		check2();
	}
return 0;
}

