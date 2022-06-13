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
    string st;
    cin >> st;
    vector<lli> mn, mx;

    for (lli i = n; i >= 1; i--) {
        mn.pb(i);
    }
    for (lli i = 1; i <= n; i++) {
        mx.pb(i);
    }

    // for min
    vector<lli> ansmin;

    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '>') {
            ansmin.pb(mn[i]);
        } else {
            vector<lli> tmp;
            while (i < st.length() && st[i] == '<') {
                tmp.pb(mn[i]);
                i++;
            }
            tmp.pb(mn[i]);
            reverse(all(tmp));
            for (lli j = 0; j < tmp.size(); j++) {
                ansmin.pb(tmp[j]);
            }
        }
    }

    if (ansmin.size() != mn.size()) {
        ansmin.pb(mn[mn.size() - 1]);
    }

    // for max
    vector<lli> ansmax;

    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '<') {
            ansmax.pb(mx[i]);
        } else {
            vector<lli> tmp;
            while (i < st.length() && st[i] == '>') {
                tmp.pb(mx[i]);
                i++;
            }
            tmp.pb(mx[i]);
            reverse(all(tmp));
            for (lli j = 0; j < tmp.size(); j++) {
                ansmax.pb(tmp[j]);
            }
        }
    }

    if (ansmax.size() != mx.size()) {
        ansmax.pb(mx[mx.size() - 1]);
    }

    for (lli i = 0; i < ansmin.size(); i++) {
        cout << ansmin[i] << " ";
    }
    cout << endl;
    for (lli i = 0; i < ansmax.size(); i++) {
        cout << ansmax[i] << " ";
    }
    cout << endl;
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