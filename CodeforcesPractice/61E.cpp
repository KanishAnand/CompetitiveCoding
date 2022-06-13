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

vector<lli> seg, seg2;

void update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
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

void update2(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        seg2[pos] = val;
        return;
    }
    if (in <= mid) {
        update2(2 * pos, in, val, l, mid);
    } else {
        update2(2 * pos + 1, in, val, mid + 1, r);
    }
    seg2[pos] = seg2[2 * pos] + seg2[2 * pos + 1];
    return;
}

lli query2(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        return seg2[pos];
    }
    lli mid = (l + r) / 2;
    return query2(2 * pos, beg, end, l, mid) +
           query2(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    lli n, a;
    cin >> n;

    seg.resize(4 * n + 2, 0);
    seg2.resize(4 * n + 2, 0);

    vector<lli> v1, v2;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v1.pb(a);
    }

    v2 = v1;
    sort(all(v2));

    lli cnt = -1;
    map<lli, lli> mp;
    for (lli i = 0; i < v2.size(); i++) {
        cnt++;
        mp[v2[i]] = cnt;
    }

    // 0 - (n-1)

    lli ans = 0;

    for (lli i = 0; i < n; i++) {
        lli val = v1[i];
        val = mp[val];
        ans += query(1, val + 1, n - 1, 0, n - 1);
        update2(1, val, 1, 0, n - 1);
        lli no = query2(1, val + 1, n - 1, 0, n - 1);
        update(1, val, no, 0, n - 1);
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}