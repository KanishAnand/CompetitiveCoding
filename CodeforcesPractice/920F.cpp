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

vector<lli> seg, v;
vector<lli> divs(1e6 + 5, 0);

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
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

void update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        v[in] = val;
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

void solve() {
    for (lli i = 1; i <= 1e6; i++) {
        for (lli j = i; j <= 1e6; j += i) {
            divs[j]++;
        }
    }

    lli n, m, a;
    cin >> n >> m;
    seg.resize(4 * n + 2, 0);
    set<lli> st;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        if (v[i] != divs[v[i]]) {
            st.insert(i);
        }
    }

    build(1, 0, n - 1);

    lli l, r;
    while (m--) {
        cin >> a >> l >> r;
        l--;
        r--;
        if (a == 1) {
            auto it = st.lower_bound(l);
            vector<lli> erase, ins;
            for (auto itt = it; itt != st.end(); itt++) {
                if (*itt > r) {
                    break;
                }
                lli no = *itt;
                no = v[no];
                lli val = divs[no];
                update(1, *itt, val, 0, n - 1);
                erase.pb(*itt);
                if (divs[val] != val) {
                    ins.pb(*itt);
                }
            }

            for (auto val : erase) {
                st.erase(val);
            }
            for (auto val : ins) {
                st.insert(val);
            }
        } else {
            lli ans = query(1, l, r, 0, n - 1);
            cout << ans << endln;
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