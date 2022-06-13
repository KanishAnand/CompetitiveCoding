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
    vector<pair<lli, lli>> v;
    vector<lli> deg(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        deg[i + 1] = a;
        v.pb({a, i + 1});
    }

    sort(all(v));

    lli cnt = 0;

    vector<pair<lli, lli>> ans;

    lli beg = v[0].second;
    stack<lli> one;

    for (lli i = 2; i < n; i++) {
        if (v[i].first == 1) {
            one.push(v[i].second);
        } else {
            cnt++;
            ans.pb({beg, v[i].second});
            beg = v[i].second;
        }
    }

    ans.pb({beg, v[1].second});

    if (one.size() != 0) {
        for (lli i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                continue;
            }
            lli val = deg[i] - 2;
            while (val != 0 && one.size() != 0) {
                ans.pb({i, one.top()});
                one.pop();
                val--;
            }
        }
    }

    if (one.size() == 0) {
        cout << "YES " << cnt + 1 << endl;
        cout << ans.size() << endl;
        for (lli i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    } else {
        cout << "NO" << endl;
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