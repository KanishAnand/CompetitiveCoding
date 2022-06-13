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

string f;
vector<lli> seg, lazy;

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        if (f[l] == '1') {
            seg[pos] = 1;
        }
        return;
    }
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

void push(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (lazy[pos] != -1) {
        lazy[2 * pos] = lazy[pos];
        lazy[2 * pos + 1] = lazy[pos];
    }

    if (lazy[pos] == 0) {
        seg[2 * pos] = 0;
        seg[2 * pos + 1] = 0;
    } else if (lazy[pos] == 1) {
        seg[2 * pos] = mid - l + 1;
        seg[2 * pos + 1] = r - (mid + 1) + 1;
    }

    lazy[pos] = -1;
    return;
}

void update(lli pos, lli beg, lli end, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        if (val == 0) {
            seg[pos] = 0;
        } else {
            seg[pos] = r - l + 1;
        }
        lazy[pos] = val;
        return;
    }

    update(2 * pos, beg, end, val, l, mid);
    update(2 * pos + 1, beg, end, val, mid + 1, r);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }

    if (l != r) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    seg.clear();
    lazy.clear();

    lli n, q;
    cin >> n >> q;
    string s;
    cin >> s >> f;

    lli l, r;
    vector<pair<lli, lli>> store;
    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        store.pb({l, r});
    }

    seg.resize(4 * n + 2, 0);
    lazy.resize(4 * n + 2, -1);
    build(1, 0, n - 1);

    reverse(all(store));
    for (auto pr : store) {
        lli mx = pr.second - pr.first + 1;

        if (mx % 2 == 0) {
            mx = mx / 2 - 1;
        } else {
            mx /= 2;
        }

        lli cnt = query(1, pr.first, pr.second, 0, n - 1);

        if (mx >= cnt) {
            update(1, pr.first, pr.second, 0, 0, n - 1);
        } else if (mx >= pr.second - pr.first + 1 - cnt) {
            update(1, pr.first, pr.second, 1, 0, n - 1);
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli cnt = query(1, i, i, 0, n - 1);
        if (s[i] == '1' && cnt == 0) {
            cout << "NO" << endl;
            return;
        }
        if (s[i] == '0' && cnt == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}