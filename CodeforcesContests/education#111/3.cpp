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
    return (a * (a + 1)) / 2;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;

    lli beg = 0, ans = 0;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);

        lli mn = -1;
        for (lli j = beg; j <= i; j++) {
            for (lli k = j + 1; k <= i; k++) {
                for (lli l = k + 1; l <= i; l++) {
                    if (v[j] >= v[k] && v[k] >= v[l]) {
                        mn = max(mn, j);
                    }
                    if (v[j] <= v[k] && v[k] <= v[l]) {
                        mn = max(mn, j);
                    }
                }
            }
        }

        if (mn == -1) {
            continue;
        }

        ans += calc(i - beg);
        beg = mn + 1;
        ans -= calc(i - beg);
    }

    ans += calc(n - beg);
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