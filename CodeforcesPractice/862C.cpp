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
    lli n, a, x;
    cin >> n >> x;

    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return;
    }

    if (n == 2) {
        if (x != 0) {
            cout << "YES" << endl;
            cout << "0 " << x << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    vector<lli> v;
    lli val = 0;

    for (lli i = 0; i < n - 1; i++) {
        v.pb(i);
        val ^= i;
    }

    lli p = (1ll << 18);

    lli no = x ^ val;
    no += p;
    v.pb(no);

    for (lli i = 0; i < n - 1; i++) {
        lli val = v[i] + p;
        if (val != no) {
            v[i] = val;
            break;
        }
    }

    cout << "YES" << endl;
    for (lli i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}