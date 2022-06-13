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
const double PI = 2 * acos(0.0);
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
    vector<lli> v;

    vector<lli> cnt(n + 2, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
        v.pb(a);
    }

    set<lli> st;
    for (lli i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            st.insert(i);
        }
    }

    vector<lli> ans;
    vector<lli> tmp1, tmp2;
    tmp1 = v;
    tmp2 = v;
    // lli mark = 0;
    lli no = n - 1;

    while (1) {
        lli flag = 0;
        for (lli i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            break;
        }

        auto it = st.begin();
        lli val = *it;
        st.erase(it);
        lli pos = val;
        if (pos == n) {
            pos = no;
        }
        //  else {
        //     pos -= mark;
        //     if (pos < 0) {
        //         pos = 0;
        //     }
        // }

        ans.pb(pos);
        lli prev_no = v[pos];
        cnt[prev_no]--;
        if (cnt[prev_no] == 0) {
            st.insert(prev_no);
        }
        v[pos] = val;
        cnt[val]++;

        if (v == tmp1) {
            for (lli i = 0; i < n; i++) {
                if (v[i] != i) {
                    no = i;
                    break;
                }
            }
            if (ans.empty() == 0) {
                ans.pop_back();
            }
            // if (ans.empty() == 0) {
            //     ans.pop_back();
            // }
            // ans.pb(-1);
        }

        tmp1 = tmp2;
        tmp2 = v;

        // for (lli i = 0; i < n; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }

    cout << sz(ans) << endln;
    for (lli i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endln;
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