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

lli n;
vector<string> store;

void fun(lli a, lli b, vector<pair<lli, lli>> &v, vector<vector<lli>> &vis) {
    if (store[a][b] == '1') {
        return;
    }
    if (vis[a][b] == 1) {
        return;
    }

    v.pb({a, b});
    vis[a][b] = 1;

    if (a != 0) {
        fun(a - 1, b, v, vis);
    }
    if (a != n - 1) {
        fun(a + 1, b, v, vis);
    }
    if (b != 0) {
        fun(a, b - 1, v, vis);
    }
    if (b != n - 1) {
        fun(a, b + 1, v, vis);
    }
}

void solve() {
    lli a, b, c, d;
    cin >> n;
    lli r1, c1, r2, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;

    string st;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        store.pb(st);
    }

    vector<pair<lli, lli>> v1, v2;
    vector<vector<lli>> vis1(n + 2, vector<lli>(n + 2, 0));
    vector<vector<lli>> vis2(n + 2, vector<lli>(n + 2, 0));
    fun(r1, c1, v1, vis1);
    fun(r2, c2, v2, vis2);

    lli ans = -1;

    // cout << sz(v2) << endl;
    // cout << v2[0].first << " " << v2[0].second << endl;
    // cout << v2[1].first << " " << v2[1].second << endl;

    for (lli i = 0; i < sz(v1); i++) {
        a = v1[i].first;
        b = v1[i].second;
        for (lli j = 0; j < sz(v2); j++) {
            c = v2[j].first;
            d = v2[j].second;
            lli val = (a - c) * (a - c) + (b - d) * (b - d);
            // if (val == 9) {
            //     cout << a << " " << b << endl;
            //     cout << c << " " << d << endl;
            // }
            if (ans == -1) {
                ans = val;
            } else {
                ans = min(val, ans);
            }
        }
    }

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