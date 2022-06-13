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
    lli n, a, m;
    cin >> n >> m;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli t, r;
    vector<pair<lli, lli>> store;
    for (lli i = 0; i < m; i++) {
        cin >> t >> r;
        r--;
        store.pb({t, r});
    }

    vector<lli> mx(m + 2, -1);
    lli mxx = -1, ind = -1;

    for (lli i = m - 1; i >= 0; i--) {
        if (store[i].second > mxx) {
            mxx = store[i].second;
            ind = i;
        }
        mx[i] = ind;
    }

    vector<pair<lli, lli>> new_store;
    for (lli i = 0; i < m; i++) {
        i = mx[i];
        new_store.pb({store[i]});
    }

    vector<lli> vb;
    store = new_store;
    for (lli i = 0; i <= store[0].second; i++) {
        vb.pb(v[i]);
    }

    sort(all(vb));

    lli beg = 0, end = vb.size() - 1;

    for (lli i = 0; i < store.size(); i++) {
        lli ind = store[i].second, t = store[i].first, no;
        if (i != store.size() - 1) {
            no = store[i].second - store[i + 1].second;
        } else {
            no = store[i].second + 1;
        }
        while (no > 0) {
            if (t == 1) {
                v[ind] = vb[end];
                end--;
            } else {
                v[ind] = vb[beg];
                beg++;
            }
            ind--;
            no--;
        }
    }

    for (lli i = 0; i < n; i++) {
        cout << v[i] << " ";
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