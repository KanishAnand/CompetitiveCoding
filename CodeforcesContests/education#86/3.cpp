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

void solve() {
    lli n, a, b, q, l, r;
    cin >> a >> b >> q;
    if (a > b) {
        lli tmp = a;
        a = b;
        b = tmp;
    }

    lli lcm = (a * b) / __gcd(a, b);

    for (lli i = 0; i < q; i++) {
        cin >> l >> r;

        lli val1 = l / lcm, ans = 0;
        set<lli> st;

        for (lli j = val1 * lcm; j < val1 * lcm + b; j++) {
            if (j >= l && j <= r) {
                st.insert(j);
            }
        }

        lli fin = r / lcm;
        lli p = fin - val1 - 1;
        if (p > 0) {
            ans += p * (b);
        }

        for (lli j = fin * lcm; j < fin * lcm + b; j++) {
            if (j >= l && j <= r) {
                st.insert(j);
            }
        }

        ans += st.size();

        cout << r - l + 1 - ans << " ";
    }
    cout << endl;
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