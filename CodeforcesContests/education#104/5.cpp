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
    lli n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    vector<pair<lli, lli>> a, b, c, d;
    lli p;
    for (lli i = 0; i < n1; i++) {
        cin >> p;
        a.pb({p, i});
    }
    for (lli i = 0; i < n2; i++) {
        cin >> p;
        b.pb({p, i});
    }
    for (lli i = 0; i < n3; i++) {
        cin >> p;
        c.pb({p, i});
    }
    for (lli i = 0; i < n4; i++) {
        cin >> p;
        d.pb({p, i});
    }

    lli m, x, y;

    sort(all(a));
    vector<pair<lli, lli>> v = a;
    map<lli, lli> mp;
    for (lli i = 0; i < n1; i++) {
        mp[v[i].second] = i;
    }

    for (lli tt = 0; tt < 3; tt++) {
        cin >> m;
        vector<pair<lli, lli>> tmp;
        for (lli i = 0; i < n2; i++) {
            tmp.pb({b[i].first + v[0].first, 0});
        }

        for (lli i = 0; i < m; i++) {
            cin >> x >> y;
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