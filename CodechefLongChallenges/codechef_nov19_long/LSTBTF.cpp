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
    // fr(i, 1, 10) {
    //     v.pb(i * i);
    // }

    // fr(i, 0, 9) {
    //     fr(j, 0, 9) {
    //         fr(k, 0, 9) {
    //             fr(u, 0, 9) {
    //                 fr(z, 0, 9) {
    //                     lli p = v[i] * v[i] + v[j] * v[j] + v[k] * v[k] +
    //                             v[u] * v[u] + v[z] * v[z];
    //                     lli q = sqrt(p);
    //                     if (q * q == p) {
    //                         cout << v[i] << " " << v[j] << " " << v[k] << " "
    //                              << v[u] << " " << v[z] << endl;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << "34" << endl;
        } else if (n == 5) {
            cout << "11149" << endl;
        } else {
            lli p = sqrt(n);
            if (p * p == n) {
                fr(i, 0, n) {
                    cout << "1";
                }
            } else {
                cout << "-1";
            }
            cout << endl;
        }
    }
    rt;
}