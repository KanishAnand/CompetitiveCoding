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
const double PI = 3.14159265358979323846264338;
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
    vector<lli> v1, v2;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v1.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v2.pb(a);
    }

    vector<lli> store(n + 2, 0);
    lli val = min(v2[0], v1[1]);
    store[1] = val;
    store[0] = v2[0] - val;
    v2[0] = 0;

    lli flag = 0;

    for (lli i = 1; i < n; i++) {
        lli p = v1[i] - store[i];
        if (v2[i] < p) {
            flag = 1;
            break;
        }
        if (p > 0) {
            store[i] += p;
            v2[i] -= p;
        }
        store[(i + 1) % n] += v2[i];
        v2[i] = 0;
    }

    if (store[0] < v1[0]) {
        flag = 1;
    }

    if (flag == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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