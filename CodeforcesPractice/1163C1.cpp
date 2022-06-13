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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    vector<pair<lli, lli>> v;
    cin >> n;
    fr(i, 0, n) {
        cin >> a >> b;
        v.pb({a, b});
    }

    map<lli, map<lli, set<lli>>> mp;
    map<lli, map<lli, lli>> mp2;
    lli inf = 1e10, lines = 0;

    fr(i, 0, n) {
        fr(j, i + 1, n) {
            lli slp1, slp2, flag = 0;
            if (v[j].first == v[i].first) {
                slp1 = inf;
                slp2 = 0;
            } else {
                lli r = abs(v[j].second - v[i].second);
                lli s = abs(v[j].first - v[i].first);
                lli gd = __gcd(s, r);
                slp1 = r / gd;
                slp2 = s / gd;
                lli p = v[j].second - v[i].second;
                lli q = v[j].first - v[i].first;
                if (p * q < 0) {
                    flag = 1;
                    slp1 += 1e5;
                    slp2 += 1e5;
                }
            }

            if (mp[slp1][slp2].find(i) == mp[slp1][slp2].end() &&
                mp[slp1][slp2].find(j) == mp[slp1][slp2].end()) {
                ++lines;
                mp2[slp1][slp2]++;
                mp[slp1][slp2].insert(i);
                mp[slp1][slp2].insert(j);
            } else {
                mp[slp1][slp2].insert(j);
            }
        }
    }
    lli cnt = 0;
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        auto p = (*it).second;
        for (auto itr = p.begin(); itr != p.end(); itr++) {
            lli val = (*itr).second;
            cnt += (val * (val - 1)) / 2;
        }
    }
    lli ans = (lines * (lines - 1)) / 2 - cnt;
    cout << ans << endl;
    rt;
}
