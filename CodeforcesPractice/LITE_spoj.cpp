#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

// lli o;
vector<lli> seg, v, lazy;

// lli build(lli pos, lli l, lli r) {
//     lli mid = (l + r) / 2;
//     if (l > r) {
//         return 0;
//     } else if (l == r) {
//         seg[pos] = v[l];
//         return seg[pos];
//     } else {
//         seg[pos] = build(2 * pos, l, mid) + build(2 * pos + 1, mid + 1, r);
//     }
//     return seg[pos];
// }

lli update(lli pos, lli beg, lli end, lli l, lli r) {
    lli mid = (l + r) / 2, val = 0, o;
    if (l > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        if (lazy[pos] == 0) {
        } else {
            seg[pos] = (r - l + 1) - seg[pos];
            lazy[pos] = 0;
            if (l != r) {
                if (lazy[2 * pos] != 0) {
                    lazy[2 * pos] = 0;
                } else {
                    lazy[2 * pos] = 1;
                }
                if (lazy[2 * pos + 1] != 0) {
                    lazy[2 * pos + 1] = 0;
                } else {
                    lazy[2 * pos + 1] = 1;
                }
            }
        }

        o = (r - l + 1) - seg[pos] * 2;
        seg[pos] = (r - l + 1) - seg[pos];

        if (l != r) {
            if (lazy[2 * pos] != 0) {
                lazy[2 * pos] = 0;
            } else {
                lazy[2 * pos] = 1;
            }
            if (lazy[2 * pos + 1] != 0) {
                lazy[2 * pos + 1] = 0;
            } else {
                lazy[2 * pos + 1] = 1;
            }
        }
        return o;
    }
    if (end < l || beg > r) {
        return 0;
    } else {
        if (lazy[pos] == 0) {
        } else {
            seg[pos] = (r - l + 1) - seg[pos];
            lazy[pos] = 0;
            if (l != r) {
                if (lazy[2 * pos] != 0) {
                    lazy[2 * pos] = 0;
                } else {
                    lazy[2 * pos] = 1;
                }
                if (lazy[2 * pos + 1] != 0) {
                    lazy[2 * pos + 1] = 0;
                } else {
                    lazy[2 * pos + 1] = 1;
                }
            }
        }
        val = update(2 * pos, beg, end, l, mid) +
              update(2 * pos + 1, beg, end, mid + 1, r);
        seg[pos] += val;
        // if (l < r) {
        //     seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
        // }
    }

    return val;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        // cout << lazy[pos] << endl;
        // cout << pos << " " << beg << " " << end << endl;
        if (lazy[pos] == 0) {
        } else {
            seg[pos] = (r - l + 1) - seg[pos];
            lazy[pos] = 0;
            if (l != r) {
                if (lazy[2 * pos] != 0) {
                    lazy[2 * pos] = 0;
                } else {
                    lazy[2 * pos] = 1;
                }
                if (lazy[2 * pos + 1] != 0) {
                    lazy[2 * pos + 1] = 0;
                } else {
                    lazy[2 * pos + 1] = 1;
                }
            }
        }
        return seg[pos];
    }

    if (end < l || beg > r) {
        return 0;
    } else {
        lli mid = (l + r) / 2;
        if (lazy[pos] == 0) {
        } else {
            seg[pos] = (r - l + 1) - seg[pos];
            lazy[pos] = 0;
            if (l != r) {
                if (lazy[2 * pos] != 0) {
                    lazy[2 * pos] = 0;
                } else {
                    lazy[2 * pos] = 1;
                }
                if (lazy[2 * pos + 1] != 0) {
                    lazy[2 * pos + 1] = 0;
                } else {
                    lazy[2 * pos + 1] = 1;
                }
            }
        }
        return query(2 * pos, beg, end, l, mid) +
               query(2 * pos + 1, beg, end, mid + 1, r);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    cin >> n;
    seg.resize(4 * n + 2, 0);
    lazy.resize(4 * n + 2, 0);
    v.resize(n + 2, 0);
    lli q;
    cin >> q;

    while (q--) {
        cin >> a;
        if (a == 0) {
            lli beg, end;
            cin >> beg >> end;
            update(1, beg - 1, end - 1, 0, n - 1);
            // fr(i, 0, 3 * n) {
            //     cout << seg[i] << " " << i << endl;
            // }
            // cout << endl;
        } else {
            lli beg, end;
            cin >> beg >> end;
            cout << query(1, beg - 1, end - 1, 0, n - 1) << endl;
        }
    }
    rt;
}
