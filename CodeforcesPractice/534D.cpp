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
    vector<vector<lli>> v(n + 2);
    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        v[a].pb(i + 1);
    }

    vector<lli> ans;
    if (mp[0] == 0) {
        cout << "Impossible" << endln;
        return;
    }
    mp[0]--;
    ans.pb(v[0][mp[0]]);
    lli beg = 1;

    for (lli i = 1; i < n; i++) {
        if (mp[beg] > 0) {
            mp[beg]--;
            ans.pb(v[beg][mp[beg]]);
            beg++;
        } else {
            beg -= 3;
            while (beg >= 0 && mp[beg] == 0) {
                beg -= 3;
            }
            if (beg < 0 || mp[beg] == 0) {
                break;
            }

            mp[beg]--;
            ans.pb(v[beg][mp[beg]]);
            beg++;
        }
    }

    if (sz(ans) != n) {
        cout << "Impossible" << endln;
    } else {
        cout << "Possible" << endln;
        for (lli i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endln;
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