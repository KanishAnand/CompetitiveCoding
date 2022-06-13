// #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// // using namespace __gnu_pbds;
// #define lli long long int
// #define llu unsigned long long int
// #define fr(va, beg, end) for (lli va = beg; va < end; va++)
// #define pb push_back
// #define rt return 0
// #define endln "\n"
// #define all(x) x.begin(), x.end()
// #define sz(x) (lli)(x.size())
// const lli MOD = 1e9 + 7;
// // cout << fixed << setprecision(0) << pi <<endl;
// // typedef tree<int, null_type, less<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// // order_of_key(val): returns the number of values less than val
// // find_by_order(k): returns an iterator to the kth largest element (0-based)
// lli o;
// vector<lli> v;
// vector<vector<lli>> seg;

// lli build(lli pos, lli l, lli r) {
//     lli mid = (l + r) / 2;
//     if (l > r) {
//         return 0;
//     } else if (l == r) {
//         seg[pos][0] = v[l];
//         seg[pos][1] = l;
//         return v[l];
//     } else {
//         if (build(2 * pos, l, mid) > build(2 * pos + 1, mid + 1, r)) {
//         } else {
//         }
//     }
//     return seg[pos];
// }

// lli update(lli pos, lli in, lli val, lli l, lli r) {
//     lli mid = (l + r) / 2;
//     if (l > r) {
//         return 0;
//     }
//     if ((l == r) && (l == in)) {
//         v[in] = val;
//         seg[pos][0] = val;
//         seg[pos][1] = l;
//         return o;
//     }
//     if (l > in || r < in) {
//         return 0;
//     }
//     if (in <= mid) {
//         seg[pos] += update(2 * pos, in, val, l, mid);
//     } else {
//         seg[pos] += update(2 * pos + 1, in, val, mid + 1, r);
//     }
//     return o;
// }

// lli query(lli pos, lli beg, lli end, lli l, lli r) {
//     if (l > r) {
//         return 0;
//     }
//     if (beg <= l && end >= r) {
//         return seg[pos];
//     }
//     if (end < l || beg > r) {
//         return 0;
//     } else {
//         lli mid = (l + r) / 2;
//         return query(2 * pos, beg, end, l, mid) +
//                query(2 * pos + 1, beg, end, mid + 1, r);
//     }
// }

// void solve() {
//     lli n, a, m, x, l, r;
//     cin >> n >> m;
//     for (lli i = 0; i < n; i++) {
//         cin >> a;
//         v.pb(a);
//     }
//     seg.resize(4 * n + 2, vector<lli>(2, 0));
//     build(1, 0, n - 1);

//     for (lli i = 0; i < m; i++) {
//         cin >> l >> r >> x;
//     }
// }

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // lli t; cin >> t; while(t--)
//     solve();
//     rt;
// }