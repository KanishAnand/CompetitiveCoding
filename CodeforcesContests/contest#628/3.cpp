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
    vector<vector<lli>> adj;
    adj.resize(n+2);
    vector<pair<lli,lli>> v;
    fr(i,0,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        v.pb({a,b});
    }

    if(n == 2){
        cout<<"0"<<endl;
        return;
    }

    lli val = 0;
    vector<lli> col(n+2,-1);

    for (lli i = 1; i <= n; i++) {
        if(adj[i].size() == 1){
            col[i] = val;
            val++;
        }
    }

    for (lli i = 0; i < n-1; i++) {
        a = v[i].first;
        b = v[i].second;
        if(col[a] != -1){
            cout<<col[a]<<endl;
        }
        else if(col[b] != -1){
            cout<<col[b]<<endl;
        }
        else{
            cout<<val<<endl;
            val++;
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