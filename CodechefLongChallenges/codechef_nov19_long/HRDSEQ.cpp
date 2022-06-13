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
    vector<lli> v;
    cin >> t;
    map<lli, lli> mp;
    v.pb(0);
    v.pb(0);
    mp[0] = 1;

    for (lli i = 2; i < 130; i++) {
        lli l = v.size() - 1;
        if (mp[v[l]] != 0) {
            v.pb(i - mp[v[l]]);
            mp[v[l]] = i;
        } else {
            v.pb(0);
            mp[v[l]] = i;
        }
    }

    while (t--) {
        cin >> n;
        lli p = v[n - 1], cnt = 0;
        fr(i, 0, n) {
            if (v[i] == p) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    rt;
}
