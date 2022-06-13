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

lli cntBits(lli a) {
    lli cnt = 0;
    while (a > 0) {
        cnt += a % 2;
        a /= 2;
    }
    return cnt;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(cntBits(a));
    }

    lli even = 1, odd = 0, sum = 0, ans = 0;
    for (lli i = 0; i < n; i++) {
        sum += v[i];
        if (sum % 2) {
            ans += odd;
            odd++;
        } else {
            ans += even;
            even++;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli sm = 0, mx = -1;
        for (lli j = i; j <= min(n - 1, i + 60); j++) {
            sm += v[j];
            mx = max(mx, v[j]);
            if (sm % 2 == 0 && sm < 2 * mx) {
                ans--;
            }
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