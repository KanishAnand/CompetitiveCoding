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
    vector<lli> even, odd;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            even.pb(i);
        } else {
            odd.pb(i);
        }
    }

    lli ev = sz(even), od = sz(odd);

    if (n % 2 == 0 && ev != od) {
        cout << "-1" << endl;
        return;
    }

    if (n % 2 == 1 && abs(ev - od) != 1) {
        cout << "-1" << endl;
        return;
    }

    lli ans = -1;

    if (n % 2 == 0) {
        lli val1 = 0, cnt = 0, val2 = 0;
        for (lli i = 0; i < n; i += 2) {
            val1 += abs(even[cnt] - i);
            val2 += abs(odd[cnt] - i);
            cnt++;
        }
        ans = val1;
        ans = min(ans, val2);

        val1 = 0, cnt = 0, val2 = 0;
        for (lli i = 1; i < n; i += 2) {
            val1 += abs(even[cnt] - i);
            val2 += abs(odd[cnt] - i);
            cnt++;
        }
        ans = min(ans, val1);
        ans = min(ans, val2);
    } else {
        if (ev > od) {
            swap(odd, even);
        }
        lli val1 = 0, cnt = 0, val2 = 0;
        for (lli i = 0; i < n; i += 2) {
            val1 += abs(odd[cnt] - i);
            cnt++;
        }
        ans = val1;

        cnt = 0;
        for (lli i = 1; i < n; i += 2) {
            val2 += abs(even[cnt] - i);
            cnt++;
        }
        ans = min(ans, val2);
    }

    cout << ans << endln;
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