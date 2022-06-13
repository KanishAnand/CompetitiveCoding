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
    lli n, a, k;
    cin >> n >> k;

    string stt;
    cin >> stt;

    vector<lli> cntt(26, 0);

    for (lli i = 0; i < stt.length(); i++) {
        cntt[stt[i] - 'a']++;
    }

    multiset<lli> st;

    for (lli i = 0; i < 26; i++) {
        if (cntt[i] != 0) {
            st.insert(cntt[i]);
        }
    }

    for (lli len = n; len >= 1; len--) {
        multiset<lli> tmp = st;
        lli cnt = 0;
        vector<lli> v;
        vector<lli> vis(len + 2, 0);

        for (lli i = 0; i < len; i++) {
            lli ind = i;
            while (vis[ind] == 0) {
                cnt++;
                vis[ind] = 1;
                ind = (ind + k) % len;
            }
            if (cnt != 0) {
                v.pb(cnt);
                cnt = 0;
            }
        }

        sort(v.rbegin(), v.rend());
        lli flag = 1;

        for (lli i = 0; i < v.size(); i++) {
            auto it = tmp.lower_bound(v[i]);
            if (it == tmp.end()) {
                flag = 0;
                break;
            }
            lli val = *it;
            val -= v[i];
            tmp.erase(it);
            if (val != 0) {
                tmp.insert(val);
            }
        }

        if (flag == 1) {
            cout << len << endl;
            break;
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