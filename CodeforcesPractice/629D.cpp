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
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<lli> seg;

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
    seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
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
    return max(query(2 * pos, beg, end, l, mid), query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, r, h;
    cin >> n;
    vector<lli> v;

    set<lli> tmp;
    for (lli i = 0; i < n; i++) {
        cin >> r >> h;
        v.pb(r * r * h);
        tmp.insert(v[i]);
    }

    lli cnt = 0;
    map<lli, lli> mp;
    for (auto val : tmp) {
        mp[val] = cnt++;
    }
    seg.resize(4 * cnt + 2, 0);

    for (lli i = 0; i < n; i++) {
        lli final = query(1, 0, mp[v[i]] - 1, 0, cnt - 1) + v[i];
        update(1, mp[v[i]], final, 0, cnt - 1);
    }

    double ans = query(1, 0, cnt - 1, 0, cnt - 1);
    ans = ans * PI;
    cout << fixed << setprecision(6);
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