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

void solve() {
    lli n, a, m, b;
    cin >> n >> m;
    vector<vector<lli>> adj;
    adj.resize(n + 2);
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<lli> vis(n + 2, -1);
    vector<pair<lli, lli>> odd;
    vector<lli> col(n + 2, -1);
    queue<lli> qu;

    for (lli j = 1; j <= n; j++) {
        if (vis[j] != -1) {
            continue;
        }

        col[j] = 1;
        vis[j] = 1;
        qu.push(j);
        lli flag = 0, o = 0, cnt = 0;

        while (!qu.empty()) {
            a = qu.front();
            if (col[a] == 0) {
                o++;
            }
            cnt++;
            qu.pop();

            for (lli i = 0; i < adj[a].size(); i++) {
                lli val = adj[a][i];
                if (col[val] == col[a]) {
                    flag = 1;
                    break;
                } else if (col[val] == -1) {
                    col[val] = 1 - col[a];
                    vis[val] = 1;
                    qu.push(val);
                }
            }
            if (flag == 1) {
                break;
            }
        }

        if (flag == 1) {
            cout << "0" << endl;
            return;
        }

        odd.pb({o, cnt});
    }

    lli ans = 1;
    for (lli i = 0; i < odd.size(); i++) {
        lli an =
            (power(2, odd[i].first) + power(2, odd[i].second - odd[i].first)) %
            MOD;
        ans *= an;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}