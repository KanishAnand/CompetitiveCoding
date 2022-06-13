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

vector<pair<lli, lli>> seg;

void update(lli pos, lli in, pair<lli, lli> val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        if (val.first >= seg[pos].first) {
            seg[pos] = val;
        }
        return;
    }
    if (in <= mid) {
        update(2 * pos, in, val, l, mid);
        if (seg[pos].first <= val.first) {
            seg[pos] = val;
        }
    } else {
        update(2 * pos + 1, in, val, mid + 1, r);
        if (seg[pos].first <= val.first) {
            seg[pos] = val;
        }
    }
    return;
}

pair<lli, lli> query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return {-1, 0};
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    auto val1 = query(2 * pos, beg, end, l, mid);
    auto val2 = query(2 * pos + 1, beg, end, mid + 1, r);
    if (val1.first >= val2.first) {
        return val1;
    } else {
        return val2;
    }
}

void solve() {
    lli n, a, d;
    cin >> n >> d;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    if (n == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
        return;
    }

    vector<lli> tmp = v;
    sort(all(tmp));
    lli beg = 1;

    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        if (mp[tmp[i]] == 0) {
            mp[tmp[i]] = beg;
            beg++;
        }
    }

    beg--;
    seg.resize(4 * beg + 2, {-1, 0});

    vector<lli> ind(n + 2, 0);

    lli ans = -1, no;
    for (lli i = 0; i < n; i++) {
        lli val = v[i];
        lli no1 = val - d;

        auto it = lower_bound(tmp.begin(), tmp.end(), no1);
        if (it == tmp.end()) {
            it--;
            no1 = *it;
        } else if (*it != no1) {
            if (it != tmp.begin()) {
                it--;
                no1 = *it;
            } else {
                no1 = -1;
            }
        } else {
            no1 = *it;
        }

        pair<lli, lli> p1, p2;
        p1 = {-1, 0};
        p2 = {-1, 0};
        no1 = mp[no1];
        if (no1 >= 1) {
            p1 = query(1, 1, no1, 1, beg);
        }
        lli no2 = val + d;

        auto itt = lower_bound(tmp.begin(), tmp.end(), no2);
        if (itt == tmp.end()) {
            no2 = 1e16;
        } else {
            no2 = *itt;
        }

        no2 = mp[no2];
        if (no2 >= 1) {
            p2 = query(1, no2, beg, 1, beg);
        }

        if (p1.first == -1 && p2.first == -1) {
            if (ans < 1) {
                ans = 1;
                no = i + 1;
            }
            update(1, mp[v[i]], {1, i + 1}, 1, beg);
        } else if (p1.first >= p2.first) {
            if (ans < p1.first + 1) {
                ans = p1.first + 1;
                no = i + 1;
            }
            ind[i + 1] = p1.second;
            update(1, mp[v[i]], {p1.first + 1, i + 1}, 1, beg);
        } else {
            if (ans < p2.first + 1) {
                ans = p2.first + 1;
                no = i + 1;
            }
            ind[i + 1] = p2.second;
            update(1, mp[v[i]], {p2.first + 1, i + 1}, 1, beg);
        }
    }

    cout << ans << endl;
    vector<lli> ans_ind;
    while (ind[no] != 0) {
        ans_ind.pb(no);
        no = ind[no];
    }
    ans_ind.pb(no);

    reverse(all(ans_ind));
    for (auto vv : ans_ind) {
        cout << vv << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}