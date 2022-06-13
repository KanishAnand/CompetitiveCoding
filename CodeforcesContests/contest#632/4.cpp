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
    string st;
    vector<lli> ans;
    vector<lli> cnt;
    cin >> n >> k;
    cin >> st;

    n = st.length();
    lli no = 0, sum = 0;

    while (no < k) {
        lli flag = 0, ct = 0;

        for (lli i = n - 1; i > 0; i--) {
            if (st[i] == 'L' && st[i - 1] == 'R') {
                flag = 1;
                st[i] = 'R';
                st[i - 1] = 'L';
                ans.pb(i);
                i--;
                ct++;
            }
        }

        if (flag == 0) {
            break;
        }

        cnt.pb(ct);
        sum += ct;
        no++;
    }

    lli flag = 0;
    for (lli i = 0; i < n - 1; i++) {
        if (st[i] == 'R' && st[i + 1] == 'L') {
            flag = 1;
            break;
        }
    }

    if (flag == 1 || sum < k) {
        cout << "-1" << endl;
    } else {
        lli prev = 0;
        // vector<lli> cntt;
        // for (lli i = 0; i < cnt.size(); i++) {
        //     lli val = cnt.size() - (i + 1);
        // }

        for (lli i = 0; i < cnt.size(); i++) {
            cout << cnt[i] << " ";

            for (lli j = 0; j < cnt[i]; j++) {
                cout << ans[j + prev] << " ";
            }

            prev = cnt[i];
            cout << endl;
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