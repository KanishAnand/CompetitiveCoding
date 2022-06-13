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

vector<lli> seg;

lli build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return 0;
    } else if (l == r) {
        seg[pos] = 0;
        return seg[pos];
    } else {
        seg[pos] = build(2 * pos, l, mid) + build(2 * pos + 1, mid + 1, r);
    }
    return seg[pos];
}

lli update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return 0;
    }
    if ((l == r) && (l == in)) {
        seg[pos] = val;
        if (val == 1) {
            return 1;
        } else {
            return -1;
        }
    }
    if (l > in || r < in) {
        return 0;
    }
    if (in <= mid) {
        lli c = update(2 * pos, in, val, l, mid);
        seg[pos] += c;
        return c;
    } else {
        lli c = update(2 * pos + 1, in, val, mid + 1, r);
        seg[pos] += c;
        return c;
    }
}

lli qury(lli pos, lli beg, lli end, lli l, lli r) {
    // cout << beg << " " << end << endl;
    if (l > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    if (end < l || beg > r) {
        return 0;
    } else {
        lli mid = (l + r) / 2;
        return qury(2 * pos, beg, end, l, mid) +
               qury(2 * pos + 1, beg, end, mid + 1, r);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, t, q;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        lli a, x1, x2, y;
        vector<lli> v;
        fr(i, 0, n) {
            cin >> a;
            v.pb(a);
        }

        vector<pair<lli, pair<pair<lli, lli>, lli>>> query;
        // {y , {{x1,x2},i}}
        vector<vector<pair<lli, lli>>> cnt;
        cnt.resize(q + 2);

        fr(i, 0, q) {
            cin >> x1 >> x2 >> y;
            query.pb({y, {{x1, x2}, i}});
        }

        sort(all(query));
        vector<vector<lli>> start(q + 3), end(q + 3);

        for (lli i = 0; i < n - 1; i++) {
            lli y1 = v[i], y2 = v[i + 1];
            lli ind1, ind2;
            // cout << y1 << " " << y2 << endl;
            if (y1 < y2) {
                pair<lli, pair<pair<lli, lli>, lli>> pp = {y1, {{-1, -1}, -1}};
                pair<lli, pair<pair<lli, lli>, lli>> qq = {
                    y2, {{1e14, 1e14}, 1e14}};
                auto it1 = lower_bound(query.begin(), query.end(), pp);
                auto it2 = upper_bound(query.begin(), query.end(), qq);
                // cout << query.size() << endl;
                // cout << query[0].first << endl;
                // if (it2 == query.end()) {
                //     cout << "hel" << endl;
                // }
                // if (it1 == query.end()) {
                //     cout << "hel1" << endl;
                // }
                ind1 = it1 - query.begin();
                ind2 = it2 - query.begin();
            } else {
                pair<lli, pair<pair<lli, lli>, lli>> pp = {
                    y1, {{1e14, 1e14}, 1e14}};
                pair<lli, pair<pair<lli, lli>, lli>> qq = {y2, {{-1, -1}, -1}};
                auto it1 = lower_bound(query.begin(), query.end(), qq);
                auto it2 = upper_bound(query.begin(), query.end(), pp);
                ind1 = it1 - query.begin();
                ind2 = it2 - query.begin();
            }
            // cout << ind1 << " " << ind2 << endl;
            if (ind1 < ind2) {
                start[ind1].pb(i + 1);
                end[ind2].pb(i + 1);
            }
        }

        seg.resize(4 * n + 2, 0);
        build(1, 0, n - 1);
        vector<lli> ans(q + 2, 0);
        lli ct = 0;
        for (lli i = 0; i < q; i++) {
            for (lli j = 0; j < start[i].size(); j++) {
                update(1, start[i][j], 1, 0, n - 1);
                // cout << start[i][j] << endl;
                ct++;
            }
            for (lli j = 0; j < end[i].size(); j++) {
                update(1, end[i][j], 0, 0, n - 1);
                ct--;
            }
            // cout << ct << endl;
            lli beg = query[i].second.first.first;
            lli end = query[i].second.first.second - 1;
            lli ind = query[i].second.second;
            // cout << beg << " " << end << endl;
            // cout << "kan" << endl;
            ans[ind] = qury(1, beg, end, 0, n - 1);
            // cout << "kan" << endl;
        }
        fr(i, 0, q) {
            cout << ans[i] << endl;
        }
    }
    rt;
}
