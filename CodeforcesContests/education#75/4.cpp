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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    cin >> t;
    while (t--) {
        lli s, sum = 0;
        cin >> n >> s;
        vector<pair<lli, lli>> v, v2, v3;
        fr(i, 0, n) {
            lli l, r;
            cin >> l >> r;
            sum += l;
            v.pb({l, r});
            v2.pb({r, l});
        }
        sort(all(v));
        sort(all(v2));
        lli mx = -1;
        for (lli i = 0; i < n / 2; i++) {
            // sum += v2[i].second;
            if (v2[i].second > mx) {
                mx = v2[i].second;
            }
        }
        s -= sum;

        lli p = v2.size() / 2, mn = 1e11;
        for (lli i = p; i < v2.size(); i++) {
            v3.pb({v2[i].second, v2[i].first});
            if (v2[i].first < mn) {
                mn = v2[i].first;
            }
        }
        sort(all(v3));
        vector<lli> pref(n + 2, 0);
        for (lli i = 1; i < v3.size(); i++) {
            pref[i] = pref[i - 1] + (v3[i].first - v3[i - 1].first) * i;
        }
        lli val = -1;
        for (lli i = 0; i < v3.size(); i++) {
            if (pref[i] <= s && v3[i].second <= mn) {
                val = v3[i].first;
            } else {
                break;
            }
        }

        s -= pref[val];
        if (val != v3.size() - 1) {
            lli t = v3[val + 1].first - v3[val].first;
            lli r = s / t;
            r = min(r, s / mn);
            s -= r * (val + 1);
        } else {
        }
    }
    rt;
}
