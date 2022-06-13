#include<iostream>
using namespace std;
int arrx[1100],arry[1100],p[1100]={0},q[1100]={0};
int fun(int x,int y);
int xa,xb,xc,ya,yb,yc;
int main(void){
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	//cout<<endl<<"kan"<<fun(xa,ya)<<endl;
	cout<<fun(xa,ya)+1<<endl;
return 0;
}

int fun(int x,int y){
	static int n1=0,n2=0,n3=0,n4=0;
	static int k=0;
	static int f=0;
	++k;
	cout<<k<<" ";
	if(x == xb && y == yb && f == 0){
		f = 1;
		return 1 + fun(xb,yb);
	}
	if(x == xc && y == yc && f==0){
		f=2;
		return 1 + fun(xc,yc);
	}
	if(f == 1 && x == xc && y == yc){
		return 1;
	}
	if(f == 2 && x == xb && y == yb){
		return 1;
	}

	if(x>0){
		if(p[x] == 0 || q[y] == 0){
			p[x] = 1;
			q[y] = 1;
			n1 = 1 + fun(x-1,y);
		}
		else{
			n1 = fun(x-1,y);
		}
	}
	if(y>0){
		if(p[x] == 0 || q[y] == 0){
			p[x]=1;
			q[y]=1;
			n2 = 1 + fun(x,y-1);
		}
		else{
			n2 = fun(x,y-1);
		}
	}
	if(x < 1000){
		if(p[x] == 0 || q[y] == 0){
			p[x]=1;
			q[y]=1;
			n3 = 1 + fun(x+1,y);
		}
		else{
			n3 = fun(x+1,y);
		}
	}
	if(y < 1000){
		if(p[x] == 0 || q[y] == 0){
			p[x]=1;
			q[y]=1;
			n4 = 1 + fun(x,y+1);
		}
		else{
			n4 = fun(x,y+1);
		}
	}

	int min1,min2,min;
	min1 = n1 < n2 ? n1 : n2;
	min2 = n3 < n4 ? n3 : n4;
	min = min1 < min2 ? min1 : min2;
	if(min == n1){
		arrx[k] = x-1;
		arry[k] = y;
	}
	else if(min == n2){
		arrx[k] = x;
		arry[k] = y-1;
	}
	else if(min == n3){
		arrx[k] = x+1;
		arry[k] = y;
	}
	else{
		arrx[k] = x;
		arry[k] = y+1;
	}   	
	//cout<<min<<" ";	
return min;
}



