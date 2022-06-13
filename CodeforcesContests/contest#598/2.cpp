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
    lli n, a, q;
    cin >> q;
    while (q--) {
        cin >> n;
        vector<lli> v;
        fr(i, 0, n) {
            cin >> a;
            v.pb(a);
        }

        lli in = 0;
        vector<lli> ans;

        while (in < n) {
            lli m = 1000, indx;
            for (lli i = in; i < n; i++) {
                if (v[i] < m) {
                    m = v[i];
                    indx = i;
                }
            }
            ans.pb(m);

            if (in == indx) {
                in++;
            } else {
                for (lli i = in; i < indx - 1; i++) {
                    ans.pb(v[i]);
                }
                in = indx;
                v[indx] = v[indx - 1];
            }
        }

        fr(i, 0, n) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    rt;
}
