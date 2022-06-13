#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
 
// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % MOD;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }
 
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}
 
void solve() {
    lli xr,sum, a,v,u;
    cin>>xr>>sum;
    u = xr;
    v = sum;
    if(xr == sum){
        if(xr == 0){
            cout<<"0"<<endl;
        }
        else{
            cout<<"1"<<endl;
            cout<<xr<<endl;
        }
        return ;
    }

    lli val = sum - xr;
    if(val < 0 || val % 2 != 0){
        cout<<"-1"<<endl;
        return ;
    }
    else{
        val /= 2;
        vector<lli> andd,xrr;
        lli cnt1 =0,cnt2=0;
        
        while(val > 0){
            andd.pb(val%2);
            // cout<<val%2<<endl;
            val /= 2;
            cnt1++;
        }

        // cout<<"DF"<<endl;
        while(xr > 0){
            xrr.pb(xr%2);
            // cout<<xr%2<<endl;
            xr /= 2;
            cnt2++;
        }

        while(cnt1 < cnt2){
            andd.pb(0);
            cnt1++;
        }
        while(cnt2 < cnt1){
            xrr.pb(0);
            cnt2++;
        }

        // cout<<cnt1<<endl;

        lli no=-1;
        lli no1=0,no2=0,p=1;

        fr(i,0,cnt1){
            if(andd[i] == 1){
                // ind.pb(i);
                no1 += p;
                no2 += p;
                if(xrr[i] == 0){
                    if(no == -1){
                        no = 2;
                    }
                    else if(no != 2){
                        no = 0;
                        break;
                    }
                }
                else{
                    if(no == -1){
                        no = 3;
                    }
                    else if(no != 3){
                        no = 0;
                        break;
                    }
                }
            }
            else{
                if(xrr[i] == 1){
                    no1 += p;
                    // ind1.pb(i);
                }
            }
            p *= 2;
        }

        if(no == 2){
            cout<<"2"<<endl;
            cout<<no1<<" "<<no2<<endl;
        }
        else{
            cout<<"3"<<endl;
            cout<<(v-u)/2<<" "<<(v-u)/2<<" "<<u<<endl;    
        }
    }
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}