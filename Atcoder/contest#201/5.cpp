#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<lli> vis, dist;
vector<vector<pair<lli, lli>>> adj;

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

void dfs(lli a) {
    for (auto edg : adj[a]) {
        if (vis[edg.first] == 0) {
            vis[edg.first] = 1;
            dist[edg.first] = (dist[a] ^ edg.second);
            dfs(edg.first);
        }
    }
}

void solve() {
    lli n, a, b, c;
    cin >> n;

    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    dist.resize(n + 2, 0);
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    lli ans = 0;
    map<lli, lli> mp;
    for (lli i = 1; i <= n; i++) {
        lli tmp = dist[i], ind = 0;
        while (tmp > 0) {
            if (tmp % 2) {
                mp[ind]++;
            }
            ind++;
            tmp /= 2;
        }
    }

    for (lli i = 1; i <= n; i++) {
        lli tmp = dist[i], ind = 0, p = 62;
        while (p--) {
            if (tmp % 2) {
                ans += ((n - mp[ind]) * power(2, ind)) % MOD;
                ans %= MOD;
            } else {
                ans += (mp[ind] * power(2, ind)) % MOD;
                ans %= MOD;
            }
            ind++;
            tmp /= 2;
        }
    }

    ans *= power(2, MOD - 2);
    ans %= MOD;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}