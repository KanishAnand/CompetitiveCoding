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
    lli n, a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    lli val = a - b, ans, k = 0;
    ans = (a * b) / __gcd(a, b);
    vector<lli> factors;

    for (lli i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) {
            factors.pb(i);
            factors.pb(val / i);
        }
    }

    if (val > 1) {
        factors.pb(val);
    }

    for (lli i = 0; i < factors.size(); i++) {
        val = factors[i];
        lli p = b / val;
        if (b % val != 0) {
            p++;
        }
        lli q = val * p - b;
        lli chk = (a + q) * (b + q);
        chk /= val;
        if (chk < ans) {
            ans = chk;
            k = q;
        }
    }

    cout << k << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}