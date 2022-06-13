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
    lli n, a, m;
    vector<lli> v1, v2;
    cin >> n >> m;
    input(n, v1);
    input(n, v2);

    unordered_map<lli, lli> mp1, mp2, ans;
    vector<lli> st, st1, ans2;

    fr(i, 0, n) {
        if (mp1[v1[i]] == 0) {
            st1.pb(v1[i]);
        }
        if (mp2[v2[i]] == 0) {
            st.pb(v2[i]);
        }
        mp1[v1[i]]++;
        mp2[v2[i]]++;
    }
    cout << "kan" << endl;
    // sort(all(st));

    vector<vector<lli>> cnt1;
    cnt1.resize(n + 2);

    for (auto it = st1.begin(); it != st1.end(); it++) {
        lli val = *it;
        lli cc = mp1[val];
        cnt1[cc].pb(val);
    }
    cout << "kan" << endl;
    for (auto it = st.begin(); it != st.end(); it++) {
        lli val = *it;
        lli cc = mp2[val];
        for (lli i = 0; i < (lli)(cnt1[cc].size()); i++) {
            lli valu = cnt1[cc][i];
            if (valu <= val) {
                ans2.pb(val - valu);
            } else {
                ans2.pb(m - valu + val);
            }
        }
    }

    cout << ans2.size() << endl;
    cout << "kan" << endl;
    fr(i, 0, ans2.size()) {
        ans[ans2[i]]++;
    }
    cout << ans.size() << endl;
    cout << "kan" << endl;
    lli fn = m + 2;

    for (auto it = ans.begin(); it != ans.end(); it++) {
        if ((*it).second == (lli)(st.size())) {
            lli val = (*it).first;
            fn = min(fn, val);
        }
    }
    cout << "kan" << endl;
    cout << fn << "\n";

    rt;
}
