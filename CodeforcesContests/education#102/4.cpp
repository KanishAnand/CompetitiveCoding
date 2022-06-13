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
lli inf = 1e6;
string st;
vector<lli> pref;
vector<pair<lli, lli>> seg;

pair<lli, lli> merge(lli l, lli r, pair<lli, lli> p1, pair<lli, lli> p2) {
    lli sum = 0;
    if (l <= r) {
        sum = pref[r];
        if (l != 0) {
            sum -= pref[l - 1];
        }
    }
    lli ll = sum + p2.first, rr = sum + p2.second;
    pair<lli, lli> ans;
    ans.first = min(p1.first, ll);
    ans.second = max(p1.second, rr);
    return ans;
}

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        if (st[l] == '+') {
            seg[pos] = {0, 1};
        } else {
            seg[pos] = {-1, 0};
        }
        return;
    }

    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);

    // lli sum = pref[r];
    // if (l != 0) {
    //     sum -= pref[l - 1];
    // }

    // lli ll = sum + seg[2 * pos + 1].first, rr = sum + seg[2 * pos + 1].second;
    // seg[pos].first = min(seg[2 * pos].first, ll);
    // seg[pos].second = max(seg[2 * pos].second, rr);
    seg[pos] = merge(l, mid, seg[2 * pos], seg[2 * pos + 1]);
    return;
}

pair<lli, lli> query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        // cout << l << " p " << r << endl;
        return {0, inf};
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;
    auto p1 = query(2 * pos, beg, end, l, mid);
    auto p2 = query(2 * pos + 1, beg, end, mid + 1, r);

    pair<lli, lli> tmp;
    if (p1.second == inf) {
        // cout << "A" << endl;
        tmp = p2;
    } else if (p2.second == inf) {
        // cout << "B" << endl;
        tmp = p1;
    } else {
        // cout << "C" << endl;
        tmp = merge(max(beg, l), mid, p1, p2);
    }
    // cout << l << " e " << r << endl;
    // cout << tmp.first << " d " << tmp.second << endl;
    return tmp;
}

void solve() {
    lli n, m;
    cin >> n >> m;
    cin >> st;

    pref.clear();
    pref.resize(n + 2, 0);

    lli s = 0;
    for (lli i = 0; i < n; i++) {
        if (st[i] == '+') {
            s++;
        } else {
            s--;
        }
        pref[i] = s;
    }

    seg.clear();
    seg.resize(4 * n + 2, {0, 0});
    build(1, 0, n - 1);

    lli l, r;
    while (m--) {
        cin >> l >> r;
        l--;
        r--;

        pair<lli, lli> ans1, ans2, ans;
        ans1 = query(1, 0, l - 1, 0, n - 1);
        ans2 = query(1, r + 1, n - 1, 0, n - 1);
        lli val;
        if (ans1.second == inf && ans2.second == inf) {
            val = 1;
        } else if (ans1.second == inf) {
            val = ans2.second - ans2.first + 1;
        } else if (ans2.second == inf) {
            val = ans1.second - ans1.first + 1;
        } else {
            ans = merge(0, l - 1, ans1, ans2);
            val = ans.second - ans.first + 1;
        }
        // cout << ans1.first << " " << ans1.second << endl;
        // cout << ans2.first << " " << ans2.second << endl;
        // cout << ans.first << " " << ans.second << endl;
        cout << val << endl;
    }
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