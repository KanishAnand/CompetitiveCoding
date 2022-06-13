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

void solve() {
    lli n, a, k;
    cin >> n >> k;
    map<lli, lli> mp;
    vector<lli> vec, v;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        if (mp[a] == k) {
            cout << "0" << endl;
            return;
        }
        vec.pb(a);
    }

    set<lli> st;

    for (lli i = 0; i < n; i++) {
        st.insert(vec[i]);
    }
    for (auto it = st.begin(); it != st.end(); it++) {
        v.pb(*it);
    }

    vector<pair<lli, lli>> pref, suf(v.size() + 1, {0, 0});

    pref.pb({0, 0});
    lli cnt = 0, val = 0;

    for (lli i = 1; i < v.size(); i++) {
        lli p = v[i] - v[i - 1];
        cnt += mp[v[i - 1]];
        pref.pb({cnt, val + ((p - 1) * cnt)});
        val += cnt * p;
    }

    cnt = 0;
    val = 0;
    for (lli i = v.size() - 2; i >= 0; i--) {
        lli p = v[i + 1] - v[i];
        cnt += mp[v[i + 1]];
        suf[i] = {cnt, val + ((p - 1) * cnt)};
        val += cnt * p;
    }

    lli ans = 1e18;

    for (lli i = 0; i < v.size(); i++) {
        lli val = mp[v[i]];

        if (i == v.size() - 1) {
            lli p = k - val;
            lli q = pref[i].second + p;
            ans = min(ans, q);
        }
        if (i == 0) {
            lli p = k - val;
            lli q = suf[i].second + p;
            ans = min(ans, q);
        }

        if (i != 0 && i != v.size() - 1) {
            lli p = k - val, q = 0;
            lli o = p, oo = p;

            lli vv = min(p, pref[i].first);
            o -= vv;
            q = pref[i].second + vv;
            if (o != 0) {
                q += suf[i].second + o;
            }
            ans = min(ans, q);

            q = 0;
            vv = min(p, suf[i].first);
            oo -= vv;
            q = suf[i].second + vv;
            if (oo != 0) {
                q += pref[i].second + oo;
            }
            ans = min(ans, q);
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}