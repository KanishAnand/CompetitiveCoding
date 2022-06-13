#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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
    vector<lli> v, zero, flag(n + 2, 0), st;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            zero.pb(i + 1);
        } else {
            flag[a] = 1;
        }
        v.pb(a);
    }

    for (lli i = 1; i <= n; i++) {
        if (flag[i] == 0) {
            st.pb(i);
        }
    }

    sort(all(zero));
    sort(all(st));
    lli ptr = 0;
    for (lli i = 0; i < zero.size(); i++) {
        if (zero[i] == st[ptr]) {
            if (i == zero.size() - 1) {
                v[zero[i] - 1] = v[zero[i - 1] - 1];
                v[zero[i - 1] - 1] = st[ptr];
            } else {
                v[zero[i] - 1] = st[ptr + 1];
                st[ptr + 1] = st[ptr];
                ptr++;
            }
        } else {
            v[zero[i] - 1] = st[ptr];
            ptr++;
        }
    }

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