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
    lli n, a;
    vector<lli> v, cost;
    cin >> n;
    input(n, v);
    input(n, cost);
    vector<lli> ans(n + 1, 0), val(n + 1, 0);
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (ans[i] == 0) {
                    ans[i] = cost[j] + cost[i];
                } else {
                    ans[i] = min(cost[j] + cost[i], ans[i]);
                }
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (ans[j] != 0) {
                    if (val[i] == 0) {
                        val[i] = ans[j] + cost[i];
                    } else {
                        val[i] = min(ans[j] + cost[i], val[i]);
                    }
                }
            }
        }
    }

    lli an = 1e10;

    for (lli i = 0; i < n; i++) {
        if (val[i] != 0) {
            an = min(an, val[i]);
        }
    }
    if (an == 1e10) {
        an = -1;
    }

    cout << an << endl;
    rt;
}