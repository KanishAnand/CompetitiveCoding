#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

lli val;
vector<lli> segtree, v;

lli build(lli l, lli r, lli pos) {
    if (l > r) {
        return 0;
    } else if (l == r) {
        segtree[pos] = v[l];
    } else {
        lli mid = (l + r) / 2;
        lli no = r - l + 1;
        lli t = log2(no);
        if (t % 2 == 1) {
            segtree[pos] =
                build(l, mid, 2 * pos) | build(mid + 1, r, 2 * pos + 1);
        } else {
            segtree[pos] =
                build(l, mid, 2 * pos) ^ build(mid + 1, r, 2 * pos + 1);
        }
    }
    return segtree[pos];
}

lli update(lli l, lli r, lli pos, lli ind, lli valu) {
    if (l > r) {
        return 0;
    } else if (l == r) {
        v[l] == valu;
        segtree[pos] = valu;
    } else {
        lli mid = (l + r) / 2;
        if (ind <= mid) {
            update(l, mid, 2 * pos, ind, valu);

        } else {
            update(mid + 1, r, 2 * pos + 1, ind, valu);
        }
        lli no = r - l + 1;
        lli t = log2(no);
        if (t % 2 == 1) {
            segtree[pos] = segtree[2 * pos] | segtree[2 * pos + 1];
        } else {
            segtree[pos] = segtree[2 * pos] ^ segtree[2 * pos + 1];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m;
    cin >> n >> m;
    val = pow(2, n);
    segtree.resize(4 * val + 2, 0);

    v.pb(0);
    input(val, v);
    build(1, val, 1);

    lli ind, valu;
    while (m--) {
        cin >> ind >> valu;
        update(1, val, 1, ind, valu);
        cout << segtree[1] << endl;
    }
    rt;
}
