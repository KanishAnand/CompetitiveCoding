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
    lli n, a, q, l, r;
    string st;
    cin >> st;
    n = st.length();
    vector<vector<lli>> cnt(n + 2, vector<lli>(26, 0));
    cnt[0][st[0] - 'a']++;

    for (lli i = 1; i < n; i++) {
        for (lli j = 0; j < 26; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][st[i] - 'a']++;
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        if (r - l + 1 == 1) {
            cout << "YES" << endl;
        } else {
            vector<lli> tmp(26, 0);
            for (lli i = 0; i < 26; i++) {
                tmp[i] = cnt[r][i] - cnt[l][i];
            }
            tmp[st[l] - 'a']++;
            lli no = 0;
            for (lli i = 0; i < 26; i++) {
                if (tmp[i] != 0) {
                    no++;
                }
            }

            if (no >= 3) {
                cout << "YES" << endl;
            } else if (st[l] != st[r]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}