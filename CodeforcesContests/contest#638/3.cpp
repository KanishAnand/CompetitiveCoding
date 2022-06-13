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
    lli n, a, k;
    cin >> n >> k;
    string st;
    cin >> st;
    vector<lli> v;
    vector<lli> cnt(27, 0);

    for (lli i = 0; i < st.length(); i++) {
        lli val = st[i] - 'a';
        v.pb(val);
        cnt[val]++;
    }

    sort(all(v));
    if (k == 1) {
        for (lli i = 0; i < n; i++) {
            char ch = v[i] + 'a';
            cout << ch;
        }
        cout << endl;
    } else if (cnt[v[0]] < k) {
        char ch = v[k - 1] + 'a';
        cout << ch << endl;
    } else {
        set<lli> st;
        for (lli i = k; i < n; i++) {
            st.insert(v[i]);
        }
        if (st.size() == 1) {
            lli val = n - k;
            lli p = val / k;
            if (val % k != 0) {
                p += 1;
            }
            char ch = v[0] + 'a';
            cout << ch;
            ch = v[k] + 'a';
            for (lli i = 0; i < p; i++) {
                cout << ch;
            }
            cout << endl;
        } else {
            char ch = v[0] + 'a';
            cout << ch;
            for (lli i = k; i < n; i++) {
                ch = v[i] + 'a';
                cout << ch;
            }
            cout << endl;
        }
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