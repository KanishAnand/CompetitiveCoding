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
    lli n, a, q, p, k;
    vector<lli> v;
    cin >> n;
    lli o = sqrt(n);
    vector<lli> r(o + 2, 0);
    vector<vector<lli>> store(n + 2, r);
    v.pb(0);
    input(n, v);
    cin >> q;

    for (lli i = 1; i <= sqrt(n); i++) {
        for (lli j = n; j >= 0; j--) {
            if (store[j][i] == 0) {
                lli val = j, cnt = 0, flag = 0;
                while (val <= n) {
                    if (store[val][i] != 0) {
                        store[j][i] = store[val][i] + cnt;
                        flag = 1;
                        break;
                    }
                    val += v[val] + i;
                    ++cnt;
                }
                if (flag == 0) {
                    store[j][i] = cnt;
                }
            }
        }
    }

    while (q--) {
        cin >> p >> k;
        lli cnt = 0;
        if (k >= sqrt(n)) {
            lli val = p;
            while (val <= n) {
                val += v[val] + k;
                ++cnt;
            }
            cout << cnt << endln;
        } else {
            cout << store[p][k] << endln;
        }
    }
    rt;
}
