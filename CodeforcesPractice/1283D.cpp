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
    lli n, a, m;
    cin >> n >> m;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    queue<lli> qu;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        qu.push(v[i]);
        mp[v[i]] = 1;
    }

    vector<lli> ans;

    while (!qu.empty()) {
        if (ans.size() == m) {
            break;
        }

        a = qu.front();
        if (mp[a] > 1) {
            ans.pb(a);
        }
        qu.pop();
        if (mp[a - 1] == 0) {
            qu.push(a - 1);
            mp[a - 1] = mp[a] + 1;
        }
        if (mp[a + 1] == 0) {
            qu.push(a + 1);
            mp[a + 1] = mp[a] + 1;
        }
    }

    lli sum = 0;
    for (lli i = 0; i < m; i++) {
        sum += mp[ans[i]] - 1;
    }
    cout << sum << endl;

    for (lli i = 0; i < m; i++) {
        cout << ans[i] << " ";
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