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
    lli a, m;
    string st;
    cin >> st;

    vector<lli> cnt(30, 0);
    for (lli i = 0; i < st.length(); i++) {
        cnt[st[i] - 'a']++;
    }

    cin >> m;

    vector<lli> v;
    for (lli i = 0; i < m; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> ans(m + 2, -1);

    while (1) {
        vector<lli> store;
        for (lli i = 0; i < m; i++) {
            if (v[i] == 0) {
                store.pb(i);
            }
        }

        if (sz(store) == 0) {
            break;
        }

        lli ind;
        for (lli i = 25; i >= 0; i--) {
            if (cnt[i] >= sz(store)) {
                ind = i;
                break;
            }
            cnt[i] = 0;
        }

        for (lli i = 0; i < sz(store); i++) {
            lli val = store[i];
            ans[val] = ind;
            v[val] = -1;
        }

        cnt[ind] = 0;

        for (lli i = 0; i < sz(store); i++) {
            lli val = store[i];
            for (lli j = 0; j < m; j++) {
                if (v[j] != -1) {
                    v[j] -= abs(j - val);
                }
            }
        }
    }

    for (lli i = 0; i < m; i++) {
        char ch = (char)(ans[i] + 'a');
        cout << ch;
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