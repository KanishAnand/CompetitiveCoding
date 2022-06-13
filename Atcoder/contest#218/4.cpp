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

lli calc(lli a) {
    return (a * (a - 1)) / 2;
}

void solve() {
    lli n, a, b;
    cin >> n;
    vector<lli> y;

    map<lli, vector<lli>> store;
    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        if (sz(store[b]) == 0) {
            y.pb(b);
        }
        store[b].pb(a);
    }

    lli ny = sz(y), ans = 0;
    for (lli i = 0; i < ny; i++) {
        map<lli, lli> cnt;
        for (auto el : store[y[i]]) {
            cnt[el]++;
        }
        for (lli j = i + 1; j < ny; j++) {
            lli psbl = 0;
            for (auto el : store[y[j]]) {
                if (cnt[el] != 0) {
                    psbl++;
                }
            }
            ans += calc(psbl);
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