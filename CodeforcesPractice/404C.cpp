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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, k;
    vector<pair<lli, lli>> v;
    vector<vector<lli>> ver;
    cin >> n >> k;
    ver.resize(n + 2);
    vector<lli> cnt(n + 2, 0);
    vector<pair<lli, lli>> edg;
    lli mx = -1;

    fr(i, 0, n) {
        cin >> a;
        ver[a].pb(i + 1);
        mx = max(mx, a);
        v.pb({a, i + 1});
    }

    if (sz(ver[0]) != 1) {
        cout << "-1" << endl;
        rt;
    }

    sort(all(v));

    lli ch = v[0].second;
    fr(i, 1, mx + 1) {
        lli val = v[i].first;
        lli p = k;
        if (val != 1) {
            p--;
        }
        if (sz(ver[val]) > sz(ver[val - 1]) * p) {
            cout << "-1" << endl;
            rt;
        }
    }

    for (lli val = 1; val <= mx; val++) {
        lli beg = 0;
        for (lli i = 0; i < ver[val].size(); i++) {
            if (cnt[ver[val - 1][beg]] < k) {
                edg.pb({ver[val - 1][beg], ver[val][i]});
                cnt[ver[val - 1][beg]]++;
                cnt[ver[val][i]]++;
            } else {
                beg++;
                i--;
            }
        }
    }

    cout << edg.size() << endl;
    fr(i, 0, edg.size()) {
        cout << edg[i].first << " " << edg[i].second << endl;
    }
    rt;
}
