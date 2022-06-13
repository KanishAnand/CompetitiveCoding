#include<iostream>
#include<algorithm>
#include<vector>
typedef long long int lli;
lli arx[6000000],ary[6000000],ax[6000000],ay[6000000];
//lli arrx[1004],arry[1004],arr1x[1004],arr1y[1004];
using namespace std;
int main(void){
        lli n,x,y,a,b;
        cin>>n;
	vector<lli> arrx,arry,arr1x,arr1y;
        for(int i=0;i<n;i++){
                cin>>x>>y;
              //  arrx[i] = x;
                //arry[i] = y;
		arrx.push_back(x);
		arry.push_back(y);
        }

        for(int i=0;i<n;i++){
                cin>>a>>b;
               // arr1x[i] = a;
                //arr1y[i] = b;
		arr1x.push_back(a);
		arr1y.push_back(b);
                arx[a] = 1;
                ary[b] = 1;
		ax[a] = i;
		ay[b] = i;
        }
        lli px,py;
        for(int i=0;i<n;i++){
                px = arrx[0] + arr1x[i];
                py = arry[0] + arr1y[i];
                for(int j = 0;j<n;j++){
                        lli q,w;
                        q = px - arrx[j];
                        w = py - arry[j];
                        if(arx[q] == 1 && ary[w] == 1 && ax[a] == ay[b]){
                              	if(j == n-1){
				      	cout<<px<<" "<<py<<endl;
                      	        	  return 0;
				}
				else{
					continue;
				}
                        }
                      
                        else{
                                break;
                        }
                }
        }


return 0;
}

