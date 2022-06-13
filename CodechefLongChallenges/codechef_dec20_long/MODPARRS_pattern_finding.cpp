#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
    lli n, a;
    n = 7;
    // lli a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 1;
    // lli a1 = 0, a2 = 0, a3 = 1;
    // lli a1, a2, a3;
    // cin >> a1 >> a2 >> a3;
    for (lli a1 = 1; a1 < n; a1++) {
        for (lli a2 = 1; a2 < n; a2++) {
            for (lli a3 = 1; a3 < n; a3++) {
                for (lli a4 = 1; a4 < n; a4++) {
                    for (lli a5 = 1; a5 < n; a5++) {
                        map<lli, lli> mp;
                        for (lli i = 1; i < n; i++) {
                            for (lli j = 1; j < n; j++) {
                                for (lli k = 1; k < n; k++) {
                                    for (lli p = 1; p < n; p++) {
                                        for (lli q = 1; q < n; q++) {
                                            set<lli> st;
                                            st.insert(i);
                                            st.insert(j);
                                            st.insert(k);
                                            st.insert(p);
                                            st.insert(q);
                                            if (sz(st) != 5) {
                                                continue;
                                            }
                                            lli val = a1 * i + a2 * j + a3 * k + a4 * p + a5 * q;
                                            // lli val = a1 * i + a2 * j + a3 * k;
                                            val %= n;
                                            // cout << i << " " << j << " " << k << " " << p << " " << q << " " << val << endl;
                                            // cout << i << " " << j << " " << k << " " << val << endl;
                                            mp[val]++;
                                        }
                                    }
                                }
                            }
                        }

                        // if (mp[0] != 360 || mp[1] != 360 || mp[2] != 360 || mp[3] != 360 || mp[4] != 360) {
                        cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << endl;
                        for (lli i = 0; i < n; i++) {
                            cout << mp[i] << " ";
                            // cout << i << " " << mp[i] << endl;
                        }
                        cout << endl;
                        // }
                    }
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}