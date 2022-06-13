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
    lli n, d, a;
    cin >> n >> d;
    vector<lli> v;

    lli on = 0;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a) {
            on++;
        }
        v.pb(a);
    }

    if (!on) {
        cout << "0" << endln;
        return;
    }

    lli mx = 1, cycle = 0;
    for (lli i = 0; i < n; i++) {
        if (v[i] != 1) {
            continue;
        }

        lli ln = 0, prev = i;
        while (v[prev] == 1) {
            v[prev] = 2;
            prev = (prev - d + n) % n;
            ln++;
        }

        if (v[prev] == 2) {
            cycle = 1;
            break;
        }

        prev = i;
        ln--;
        v[prev] = 1;
        while (v[prev] == 1) {
            v[prev] = 2;
            prev = (prev + d + n) % n;
            ln++;
        }

        mx = max(mx, ln);
    }

    if (cycle) {
        mx = -1;
    }
    cout << mx << endln;
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