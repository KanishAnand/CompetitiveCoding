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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

lli INF = 1e7;
vector<lli> seg, lazy;

void push(lli pos) {
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    seg[2 * pos] += lazy[pos];
    seg[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    return;
}

void update(lli pos, lli beg, lli end, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        seg[pos] += val;
        lazy[pos] += val;
        return;
    }

    update(2 * pos, beg, end, val, l, mid);
    update(2 * pos + 1, beg, end, val, mid + 1, r);
    seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return INF;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    return min(query(2 * pos, beg, end, l, mid),
               query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, m;
    cin >> n >> m;
    m--;
    vector<pair<lli, pair<lli, lli>>> segments;

    lli l, r, w;
    for (lli i = 0; i < n; i++) {
        cin >> l >> r >> w;
        r--;
        segments.pb({w, {l, r}});
    }
    sort(all(segments));

    seg.resize(4 * m + 2, 0);
    lazy.resize(4 * m + 2, 0);

    lli end = 0, ans = INF;
    for (lli beg = 0; beg < n; beg++) {
        end = max(beg, end);

        for (; end < n; end++) {
            update(1, segments[end].second.first, segments[end].second.second, 1, 1, m);
            lli mn = query(1, 1, m, 1, m);
            if (mn != 0) {
                ans = min(ans, segments[end].first - segments[beg].first);
                update(1, segments[end].second.first, segments[end].second.second, -1, 1, m);
                break;
            }
        }

        lli mn = query(1, 1, m, 1, m);
        if (end >= n && mn != 0) {
            ans = min(ans, segments[n - 1].first - segments[beg].first);
        }

        update(1, segments[beg].second.first, segments[beg].second.second, -1, 1, m);
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