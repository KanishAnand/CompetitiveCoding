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

    if (n % 2 == 1) {
        if (v1[n / 2] != v2[n / 2]) {
            cout << "NO" << endl;
            return;
        }
    }

    lli j = n - 1;
    multiset<pair<lli, lli>> st1, st2;

    for (lli i = 0; i < n / 2; i++) {
        if (v1[i] > v1[j]) {
            st1.insert({v1[j], v1[i]});
        } else {
            st1.insert({v1[i], v1[j]});
        }
        j--;
    }

    j = n - 1;
    for (lli i = 0; i < n / 2; i++) {
        if (v2[i] > v2[j]) {
            st2.insert({v2[j], v2[i]});
        } else {
            st2.insert({v2[i], v2[j]});
        }
        j--;
    }

    if (st1 != st2) {
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