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
    lli n, a;
    cin >> n;
    lli gcd = 0;
    vector<lli> v(1e6 + 5, 0);
    lli mx = -1;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v[a] = 1;
        mx = max(mx, a);
        gcd = __gcd(gcd, a);
    }

    if (gcd != 1) {
        cout << "not coprime" << endl;
        return;
    }

    lli flag = 0;
    for (lli i = 2; i <= mx; i++) {
        lli cnt = 0;
        for (lli j = i; j <= mx; j += i) {
            if (v[j] == 1) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "pairwise coprime" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}