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
typedef struct bracket {
    lli ans, open, close;
} bracket;

vector<bracket> seg, v;

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = v[l];
        return;
    }

    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    bracket t1, t2;
    t1 = seg[2 * pos];
    t2 = seg[2 * pos + 1];
    lli p = min(t1.open, t2.close);
    seg[pos].ans += t1.ans + t2.ans;
    seg[pos].ans += p * 2;
    t1.open -= p;
    t2.close -= p;
    seg[pos].open = t1.open + t2.open;
    seg[pos].close = t1.close + t2.close;
    return;
}

bracket query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        bracket tmp = {0, 0, 0};
        return tmp;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;
    bracket t1 = query(2 * pos, beg, end, l, mid);
    bracket t2 = query(2 * pos + 1, beg, end, mid + 1, r);
    bracket t3;
    t3.ans = t1.ans + t2.ans;
    lli p = min(t1.open, t2.close);
    t1.open -= p;
    t2.close -= p;
    t3.ans += p * 2;
    t3.open = t1.open + t2.open;
    t3.close = t1.close + t2.close;
    return t3;
}

void solve() {
    lli n, a, l, r, q;
    string st;
    cin >> st;
    n = st.length();
    seg.resize(4 * n + 2, {0, 0, 0});
    v.resize(n + 2, {0, 0, 0});

    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '(') {
            v[i].open = 1;
        } else {
            v[i].close = 1;
        }
    }

    build(1, 0, n - 1);
    cin >> q;

    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        cout << query(1, l, r, 0, n - 1).ans << endl;
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