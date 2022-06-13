#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0;
lli input(lli n);
lli input(lli n,vector<lli> &ve){
    lli val;
    for(lli i=0;i<n;i++){
        cin>>val;
        ve.pb(val);
    }
return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n,m,ind=-1;
    vector<lli> v,ans,ve;
    vector<lli> arr(101,0);
    cin>>n>>m;
    lli a,sum=0;
    fr(i,0,n){
        cin>>a;
        v.pb(a);
    }   

    fr(i,0,n){
        sum += v[i];
        ++arr[v[i]];
        if(sum <= m){
            ve.pb(v[i]);
            ans.pb(0);
        }
        else{
            sum -= v[i];
            --arr[v[i]];
            ind = i;
            break;
        }
    }
    
    if(ind == -1){
        for(lli i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    rt;
    }
//cout<<arr[1]<<endl;
    for(lli i=ind;i<n;i++){
        lli val = sum + v[i] - m,c=0;
        for(lli j=100;j>=0;j--){
            //cout<<val<<endl;
            if(val <= 0){
                ans.pb(c);
                sum += v[i];
                ++arr[v[i]];
                break;
            }
            if(val - j*arr[j] >= 0){
                c += arr[j];
                val -= arr[j]*j;
            }
            else{
                if(val % j == 0){
                    c += val/j;
                    val -= j*(val/j);
                }
                else{
                    c += val/j + 1;
                    val -= j*(val/j + 1);
                }
            }
        }
    }


    for(lli i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
rt;
}


    
