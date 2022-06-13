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
const lli mod = 1e9 + 7;
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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> st(n + 2, 0);
    st[0] = 1;
    st[1] = 1;
    lli ans = 0;

    for (lli i = 1; i < n; i++) {
        lli val = v[i];

        for (lli j = 1; j <= sqrt(val); j++) {
            if (v[i] % j == 0) {
                lli val1 = j, val2 = v[i] / j;
                if (val1 <= i + 1 && val1 == val2) {
                    st[val1] += st[val1 - 1];
                    st[val1] %= mod;
                } else {
                    if (val2 <= i + 1) {
                        st[val2] += st[val2 - 1];
                        st[val2] %= mod;
                    }
                }
            }
        }

        for (lli j = sqrt(val); j >= 1; j--) {
            if (v[i] % j == 0) {
                lli val1 = j, val2 = v[i] / j;
                if (val1 != val2) {
                    if (val1 <= i + 1) {
                        st[val1] += st[val1 - 1];
                        st[val1] %= mod;
                    }
                }
            }
        }
    }

    for (lli i = 1; i < st.size(); i++) {
        ans += st[i];
        ans %= mod;
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