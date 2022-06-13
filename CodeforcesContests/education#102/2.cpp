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

void solve() {
    string s, t;
    cin >> s >> t;
    lli a = len(s), b = len(t);
    lli g = __gcd(a, b);
    lli lcm = (a * b) / g;
    string ch1 = "", ch2 = "";

    lli p = lcm / a, q = lcm / b;

    for (lli i = 0; i < p; i++) {
        ch1 += s;
    }

    for (lli i = 0; i < q; i++) {
        ch2 += t;
    }

    // cout << ch1 << " " << ch2 << endl;
    if (ch1 == ch2) {
        cout << ch1 << endl;
    } else {
        cout << "-1" << endl;
    }
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