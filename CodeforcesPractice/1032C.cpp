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
    lli n, a;
    vector<lli> v;
    cin >> n;
    input(n, v);
    vector<vector<lli>> dp(n + 2, vector<lli>(6, 0));
    fr(i, 1, 6) {
        dp[0][i] = 1;
    }

    fr(i, 1, n) {
        fr(j, 1, 6) {
            lli val = 0;
            if (v[i] > v[i - 1]) {
                fr(k, 1, j) {
                    if (dp[i - 1][k] != 0) {
                        val = 1;
                    }
                }
            } else if (v[i] < v[i - 1]) {
                fr(k, j + 1, 6) {
                    if (dp[i - 1][k] != 0) {
                        val = 1;
                    }
                }
            } else {
                fr(k, 1, 6) {
                    if (k != j) {
                        if (dp[i - 1][k] != 0) {
                            val = 1;
                        }
                    }
                }
            }
            dp[i][j] = val;
        }
    }

    lli ind = -1;
    fr(i, 1, 6) {
        if (dp[n - 1][i] != 0) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << "-1" << endl;
        rt;
    }

    vector<lli> ans;
    ans.pb(ind);
    for (lli i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            fr(j, 1, ind) {
                if (dp[i][j] != 0) {
                    ind = j;
                    break;
                }
            }
        } else if (v[i] > v[i + 1]) {
            fr(j, ind + 1, 6) {
                if (dp[i][j] != 0) {
                    ind = j;
                    break;
                }
            }
        } else {
            fr(j, 1, 6) {
                if (j != ind && dp[i][j] != 0) {
                    ind = j;
                    break;
                }
            }
        }
        ans.pb(ind);
    }

    reverse(all(ans));

    fr(i, 0, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;

    rt;
}
