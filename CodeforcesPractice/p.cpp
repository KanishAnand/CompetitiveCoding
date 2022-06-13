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

vector<lli> seg;
void build(lli pos, lli l, lli r) {
    // build(1, 0, n - 1);
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = v[l];
        return;
    }
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

void update(lli pos, lli in, lli val, lli l, lli r) {
    // update(1, index, val, 0, n - 1);
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        // v[in] = val;
        seg[pos] = val;
        return;
    }
    if (in <= mid) {
        update(2 * pos, in, val, l, mid);
    } else {
        update(2 * pos + 1, in, val, mid + 1, r);
    }
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    // query(1, beg, end, 0, n - 1)
    if (l > r || end < l || beg > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    lli n, a, x;
    cin >> n >> x;
    vector<pair<lli, lli>> v;
    lli l, r;
    lli beg = 0, flag = 0;

    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        if (flag == 0 && x >= l && x <= r) {
            beg++;
        } else {
            flag = 1;
        }
        v.pb({l, r});
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(2, -1));

    dp[beg][0] = abs(x - v[beg].first);
    dp[beg][1] = abs(x - v[beg].second);
    seg.resize(4 * n + 2, 0);

    for (lli i = beg + 1; i < n; i++) {
        vector<pair<lli, lli>> store;
        for (lli j = beg; j < i; j++) {
            store.pb(v[j].second);
        }
        sort(all(store));
        update(1, j, v[j].second, 0, n - 1);

        for (lli j = beg; j < i; j++) {
            update(1, j, 0, 0, n - 1);
            auto it = upper_bound(store.begin(), store.end(), v[j].second);
            lli val = query(1, 0, n - 1, 0, n - 1);
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