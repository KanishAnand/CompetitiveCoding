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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli ans = 0;

    for (lli start = 0; start < n; start += 2) {
        lli open = 0, mnStart = 0;
        for (lli i = start + 1; i < n; i++) {
            if (i % 2 == 0) {
                open += v[i];
                continue;
            }

            if (v[start] < mnStart) {
                break;
            }

            if (v[start] >= mnStart && v[i] >= open) {
                lli x = mnStart, y = open;
                lli pp = min(v[start] - x, v[i] - y) + 1;
                ans += pp;
                if (i == start + 1) {
                    ans--;
                }
                // cout << start << " " << i << " " << pp << endl;
            }

            lli close = v[i];
            lli p = min(close, open);
            close -= p;
            open -= p;
            mnStart += close;
            close = 0;
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