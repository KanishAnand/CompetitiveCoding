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

vector<lli> prime;

void solve() {
    lli d;
    cin >> d;
    auto it = lower_bound(prime.begin(), prime.end(), 1 + d);
    lli first = *it;
    auto itt = lower_bound(prime.begin(), prime.end(), first + d);
    lli second = *itt;
    lli ans = first * second;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli n = 100000;
    vector<lli> mark(n + 2, 0);

    for (lli i = 2; i <= n; i++) {
        if (mark[i] == 1) {
            continue;
        }
        for (lli j = i * i; j <= n; j += i) {
            mark[j] = 1;
        }
    }

    for (lli i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            prime.pb(i);
        }
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}