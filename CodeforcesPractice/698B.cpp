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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<lli> king, rankk;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void solve() {
    lli n, a;
    cin >> n;

    vector<lli> v;
    king.resize(n + 2);
    rankk.resize(n + 2, 1);

    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        king[i + 1] = i + 1;
        v.pb(a);
    }

    vector<lli> cycle, self;

    for (lli i = 1; i <= n; i++) {
        lli p = find(i), q = find(v[i]);
        if (p == q) {
            if (i == v[i]) {
                self.pb(i);
            } else {
                cycle.pb(i);
            }
        } else {
            merge(p, q);
        }
    }

    lli ans = 0;
    if (sz(self) == 0 && sz(cycle) != 0) {
        ans = sz(cycle);
        v[cycle[0]] = cycle[0];
        for (lli i = 1; i < sz(cycle); i++) {
            v[cycle[i]] = cycle[0];
        }
    } else if (sz(self) != 0) {
        ans = sz(self) - 1 + sz(cycle);
        for (lli i = 1; i < sz(self); i++) {
            v[self[i]] = self[0];
        }
        for (lli i = 0; i < sz(cycle); i++) {
            v[cycle[i]] = self[0];
        }
    }

    cout << ans << endl;
    for (lli i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}