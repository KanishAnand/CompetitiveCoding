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

struct segment {
    lli l, r;
    lli fullNonDec;
    lli maxLeft, minRight;
    lli remaining;
};

vector<lli> v;
vector<struct segment> seg;

lli calc(lli a) {
    return (a * (a + 1)) / 2;
}

struct segment merge(struct segment left, struct segment right) {
    if (left.fullNonDec == -1) {
        return right;
    }
    if (right.fullNonDec == -1) {
        return left;
    }

    struct segment mergedSeg;
    mergedSeg.l = left.l;
    mergedSeg.r = right.r;
    mergedSeg.fullNonDec = 0;

    if (left.fullNonDec == 1 && right.fullNonDec == 1) {
        if (v[left.r] <= v[right.l]) {
            mergedSeg.fullNonDec = 1;
            mergedSeg.remaining = 0;
        } else {
            mergedSeg.maxLeft = left.r;
            mergedSeg.minRight = right.l;
            mergedSeg.remaining = 0;
        }
    } else if (left.fullNonDec == 1) {
        if (v[left.r] <= v[right.l]) {
            mergedSeg.maxLeft = right.maxLeft;
            mergedSeg.minRight = right.minRight;
            mergedSeg.remaining = right.remaining;
        } else {
            mergedSeg.maxLeft = left.r;
            mergedSeg.minRight = right.minRight;
            mergedSeg.remaining = right.remaining + calc(right.maxLeft - right.l + 1);
        }
    } else if (right.fullNonDec == 1) {
        if (v[left.r] <= v[right.l]) {
            mergedSeg.maxLeft = left.maxLeft;
            mergedSeg.minRight = left.minRight;
            mergedSeg.remaining = left.remaining;
        } else {
            mergedSeg.maxLeft = left.maxLeft;
            mergedSeg.minRight = right.l;
            mergedSeg.remaining = left.remaining + calc(left.r - left.minRight + 1);
        }
    } else {
        mergedSeg.maxLeft = left.maxLeft;
        mergedSeg.minRight = right.minRight;
        mergedSeg.remaining = left.remaining + right.remaining;

        if (v[left.r] <= v[right.l]) {
            mergedSeg.remaining += calc(right.maxLeft - left.minRight + 1);
        } else {
            mergedSeg.remaining += calc(left.r - left.minRight + 1);
            mergedSeg.remaining += calc(right.maxLeft - right.l + 1);
        }
    }

    return mergedSeg;
}

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos].l = l;
        seg[pos].r = r;
        seg[pos].maxLeft = l;
        seg[pos].minRight = r;
        seg[pos].fullNonDec = 1;
        seg[pos].remaining = 0;
        return;
    }

    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = merge(seg[2 * pos], seg[2 * pos + 1]);
    return;
}

void update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        v[in] = val;
        return;
    }
    if (in <= mid) {
        update(2 * pos, in, val, l, mid);
    } else {
        update(2 * pos + 1, in, val, mid + 1, r);
    }
    seg[pos] = merge(seg[2 * pos], seg[2 * pos + 1]);
    return;
}

struct segment query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        struct segment empt;
        empt.fullNonDec = -1;
        return empt;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return merge(query(2 * pos, beg, end, l, mid),
                 query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, q, a;
    cin >> n >> q;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    seg.resize(4 * n + 2);
    build(1, 0, n - 1);

    lli op, b;
    while (q--) {
        cin >> op >> a >> b;
        if (op == 1) {
            a--;
            update(1, a, b, 0, n - 1);
        } else {
            a--;
            b--;
            auto ans = query(1, a, b, 0, n - 1);
            lli val;
            if (ans.fullNonDec) {
                val = calc(ans.r - ans.l + 1);
            } else {
                lli val1 = calc(ans.maxLeft - ans.l + 1);
                lli val2 = calc(ans.r - ans.minRight + 1);
                val = ans.remaining + val1 + val2;
            }
            cout << val << endln;
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