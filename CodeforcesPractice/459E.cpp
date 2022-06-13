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
#define len(x) (lli)(x.length())
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
    lli n, m, a, b, w;
    cin >> n >> m;

    vector<pair<lli, pair<lli, lli>>> edges;
    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.pb({w, {a, b}});
    }

    sort(all(edges));
    vector<lli> ans(n + 2, 0);

    lli i = 0;
    while (i < m) {
        vector<pair<lli, lli>> pending;
        while (i != m - 1 && edges[i].first == edges[i + 1].first) {
            a = edges[i].second.first, b = edges[i].second.second;
            pending.pb({b, ans[a] + 1});
            i++;
        }

        a = edges[i].second.first, b = edges[i].second.second;
        ans[b] = max(ans[b], ans[a] + 1);

        for (auto el : pending) {
            ans[el.first] = max(ans[el.first], el.second);
        }
        i++;
    }

    lli mx = -1;
    for (lli i = 1; i <= n; i++) {
        mx = max(mx, ans[i]);
    }

    cout << mx << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}