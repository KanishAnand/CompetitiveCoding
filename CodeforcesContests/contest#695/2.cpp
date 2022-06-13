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

lli check(lli ind, vector<lli> &v) {
    if (ind > 0 && ind < sz(v) - 1) {
        if (v[ind] > v[ind - 1] && v[ind] > v[ind + 1]) {
            return 1;
        }
        if (v[ind] < v[ind - 1] && v[ind] < v[ind + 1]) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli ans = 0;
    vector<lli> mark(n + 6, 0);
    for (lli i = 1; i < n - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            // hill
            mark[i] = 1;
            ans++;
        }
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            // valley
            mark[i] = 1;
            ans++;
        }
    }

    lli mx = 0;
    for (lli i = 0; i < n; i++) {
        lli tmp = v[i];
        lli orr = mark[i] + mark[i + 1];
        if (i != 0) {
            orr += mark[i - 1];
        }

        if (i != 0) {
            v[i] = v[i - 1];
            lli p = check(i, v);
            p += check(i - 1, v);
            p += check(i + 1, v);
            mx = max(mx, orr - p);
        }
        if (i != n - 1) {
            v[i] = v[i + 1];
            lli p = check(i, v);
            p += check(i - 1, v);
            p += check(i + 1, v);
            mx = max(mx, orr - p);
        }
        v[i] = tmp;
    }

    ans -= mx;
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