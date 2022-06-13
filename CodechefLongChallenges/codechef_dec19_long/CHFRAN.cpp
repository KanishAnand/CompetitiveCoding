#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
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
    lli n, a, t, b;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<lli, lli>> v;
        fr(i, 0, n) {
            cin >> a >> b;
            v.pb({a, b});
        }

        sort(all(v));
        // set<lli> p;
        new_data_set p;
        // vector<lli> p;
        if (n == 1) {
            cout << "-1" << endl;
            continue;
        }
        lli mn = -1;
        map<lli, lli> mp;
        p.insert(v[0].second);

        for (lli i = 1; i < n; i++) {
            // auto it = lower_bound(p.begin(), p.end(), v[i].first);
            // lli val = p.end() - it;
            lli val = p.order_of_key(v[i].first);
            // cout << val << endl;
            val = i - val;
            // lli val = 0;
            // cout << val << endl;
            // lli val = distance(it, p.end());
            if (val != i) {
                if (mn == -1) {
                    mn = val;
                }
                if (val < mn) {
                    mn = val;
                }
            }
            // cout << val << " " << mn << endl;
            p.insert(v[i].second);
            // sort(all(p));
        }
        cout << mn << endl;
    }
    rt;
}
