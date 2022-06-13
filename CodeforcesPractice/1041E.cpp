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
    lli n, a, b;
    cin >> n;

    lli flag = 0;

    map<lli, lli> mp;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        mp[a]++;
        if (b != n) {
            flag = 1;
        }
    }

    if (flag) {
        cout << "NO" << endl;
        return;
    }

    lli ind = 0;
    vector<lli> v;
    for (lli i = 1; i < n; i++) {
        if (!mp[i]) {
            v.pb(i);
        }
    }

    vector<pair<lli, lli>> edges;
    for (lli i = 1; i < n; i++) {
        if (!mp[i]) {
            continue;
        }

        mp[i]--;
        lli last = i;
        while (mp[i] != 0) {
            if (v[ind] < i) {
                edges.pb({v[ind], last});
                last = v[ind];
                ind++;
            } else {
                flag = 1;
                break;
            }
            mp[i]--;
        }

        if (flag) {
            break;
        }
        edges.pb({last, n});
    }

    if (flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (lli i = 0; i < sz(edges); i++) {
            cout << edges[i].first << " " << edges[i].second << endln;
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