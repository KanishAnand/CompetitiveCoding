/*#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
*///#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
double pi = 3.14159265;
//using namespace std;
int main(void){
        float n,r;
        scanf("%f%f",&n,&r);
        float m;
        m = 180.000/n;
        //cout<<m<<endl;
        m = m*pi/180.00;
        //cout<<m<<endl;
        float ans = sin(m);
        //cout<<ans<<endl;
        float ansp = (float)(ans*r)/(float)(1.00-ans);
        printf("%f\n",ansp);
return 0;
}

