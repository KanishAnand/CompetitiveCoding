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
    lli n, a,b;
    cin>>n;
    vector<lli> len,cost;
    for (lli i = 0; i < n; i++) {
        cin>>a>>b;
        len.pb(a);
        cost.pb(b);
    }
    vector<vector<lli>> dp(n+2,vector<lli> (3,1e18+5));
    dp[0][0] = 0;   
    dp[0][1] = cost[0];
    dp[0][2] = 2*cost[0];

    for (lli i = 1; i < n; i++) {
        for(lli j=0;j<3;j++){
            if(len[i] +j != len[i-1]){
                dp[i][j] = min(dp[i][j],dp[i-1][0]+cost[i]*j);
            }
            if(len[i] +j != len[i-1]+1){
                dp[i][j] = min(dp[i][j],dp[i-1][1]+cost[i]*j);
            }
            if(len[i] +j != len[i-1]+2){
                dp[i][j] = min(dp[i][j],dp[i-1][2]+cost[i]*j);
            }
        }
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t; cin >> t; while(t--)
    solve();
    rt;
}