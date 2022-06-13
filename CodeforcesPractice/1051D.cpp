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
const lli MOD = 998244353;
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
lli sum(lli a,lli b){
    return (a+b)%MOD;
}

void solve() {
    lli n, a,k;
    cin>>n>>k;
    // 00,01,10,11
    vector<vector<vector<lli>>> dp(n+2,vector<vector<lli>> (k+2,vector<lli> (4,0)));
    dp[0][1][0] += 1;
    dp[0][2][1] += 1;
    dp[0][2][2] += 1;
    dp[0][1][3] += 1;

    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j <= k; j++) {
            dp[i][j][0] = sum(dp[i][j][0],dp[i-1][j][0]);
            dp[i][j][0] = sum(dp[i][j][0],dp[i-1][j][1]);
            dp[i][j][0] = sum(dp[i][j][0],dp[i-1][j][2]);
            dp[i][j][0] = sum(dp[i][j][0],dp[i-1][j-1][3]);

            dp[i][j][1] = sum(dp[i][j][1],dp[i-1][j-1][0]);
            dp[i][j][1] = sum(dp[i][j][1],dp[i-1][j][1]);
            if(j >= 2){
                dp[i][j][1] = sum(dp[i][j][1],dp[i-1][j-2][2]);
            }
            dp[i][j][1] = sum(dp[i][j][1],dp[i-1][j-1][3]);

            dp[i][j][2] = sum(dp[i][j][2],dp[i-1][j-1][0]);
            if(j >= 2){
                dp[i][j][2] = sum(dp[i][j][2],dp[i-1][j-2][1]);
            }
            dp[i][j][2] = sum(dp[i][j][2],dp[i-1][j][2]);
            dp[i][j][2] = sum(dp[i][j][2],dp[i-1][j-1][3]);
            
            dp[i][j][3] = sum(dp[i][j][3],dp[i-1][j-1][0]);
            dp[i][j][3] = sum(dp[i][j][3],dp[i-1][j][1]);
            dp[i][j][3] = sum(dp[i][j][3],dp[i-1][j][2]);
            dp[i][j][3] = sum(dp[i][j][3],dp[i-1][j][3]);
        }
    }

    lli ans = 0;
    ans = sum(ans,dp[n-1][k][0]);
    ans = sum(ans,dp[n-1][k][1]);
    ans = sum(ans,dp[n-1][k][2]);
    ans = sum(ans,dp[n-1][k][3]);
    cout<<ans<<endl;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}