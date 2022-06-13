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
    lli n, a, q, k;
    cin >> q;

    while (q--) {
        string st;
        cin >> n >> k;
        cin >> st;
        lli l = st.length();
        vector<lli> v(l + 2, 2), ve, c;
        lli cnt = 0;

        for (lli i = 0; i < st.length(); i++) {
            if (st[i] == '1') {
                v[i] = 1;
                ++cnt;
            } else {
                v[i] = 0;
                ve.pb(i);
                c.pb(cnt);
            }
        }

        // lli in = 0, p = 0;
        // cout << "K" << endl;

        for (lli i = 0; i < ve.size(); i++) {
            if (c[i] == 0) {
                continue;
            }
            if (k == 0) {
                break;
            }
            if (c[i] <= k) {
                k -= c[i];
                v[ve[i] - c[i]] = 0;
                v[ve[i]] = 1;
            } else {
                v[ve[i] - k] = 0;
                v[ve[i]] = 1;
                k = 0;
            }
        }

        for (lli i = 0; i < l; i++) {
            cout << v[i];
        }
        cout << endl;
    }
    rt;
}
