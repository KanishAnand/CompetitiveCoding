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

lli mx = 2e5 + 20;
vector<lli> store(mx, -1);

lli fun(lli a) {
    lli orga = a;
    if (store[a] != -1) {
        return store[a];
    }

    if (a <= 9) {
        return 1;
    }

    a -= 10;
    lli val = (fun(a + 1) + fun(a)) % MOD;
    store[orga] = val;
    return val;
}

void solve() {
    lli n, m;
    cin >> n >> m;

    lli ans = 0;
    while (n > 0) {
        lli rem = n % 10;
        ans += store[m + rem];
        ans %= MOD;
        n /= 10;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (lli i = 0; i <= 9; i++) {
        store[i] = 1;
    }

    for (lli i = mx - 1; i >= 0; i--) {
        if (store[i] == -1) {
            fun(i);
        }
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}