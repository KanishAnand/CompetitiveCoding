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
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

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
        string st;
        cin >> st;
        lli flag = 0;
        vector<set<lli>> v;
        v.resize(26);
        fr(i, 1, st.length()) {
            lli val1 = st[i - 1] - 'a';
            lli val2 = st[i] - 'a';
            v[val1].insert(val2);
            v[val2].insert(val1);
            if (v[val1].size() >= 3 || v[val2].size() >= 3) {
                flag = 1;
                // cout << "DF2" << endl;
                break;
            }
        }

        vector<lli> ans, mk(26, 0);
        lli ind = -1, flag2 = 0;
        fr(i, 0, 26) {
            if (v[i].size() == 0) {
                mk[i] = 1;
                ans.pb(i);
            }
            if (v[i].size() == 1) {
                ind = i;
            }
            if (v[i].size() == 2) {
                flag2 = 1;
            }
        }

        if (ind == -1 && flag2 == 1) {
            flag = 1;
        }

        if (ind == -1 && flag2 == 0) {
            cout << "YES" << endl;
            fr(i, 0, 26) {
                char ch = (char)(i + 'a');
                cout << ch;
            }
            cout << endl;
        } else if (flag == 1) {
            cout << "NO" << endl;
        } else {
            // cout << ans.size() << endl;
            mk[ind] = 1;
            ans.pb(ind);
            // auto it = v[ind].begin();
            // ind = *it;
            // ans.pb(ind);
            while (1) {
                // cout << ind << endl;
                if (v[ind].size() == 1) {
                    auto it = v[ind].begin();
                    ind = *it;
                    if (mk[ind] == 1) {
                        break;
                    }
                    ans.pb(ind);
                    mk[ind] = 1;
                    // break;
                } else {
                    auto it = v[ind].begin();
                    lli val1 = *it;
                    it++;
                    lli val2 = *it;
                    if (mk[val1] == 1) {
                        ind = val2;
                    } else if (mk[val2] == 1) {
                        ind = val1;
                    } else {
                        break;
                    }
                    ans.pb(ind);
                    mk[ind] = 1;
                }
            }
            if (ans.size() != 26) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                fr(i, 0, 26) {
                    char ch = (char)(ans[i] + 'a');
                    cout << ch;
                }
                cout << endl;
            }
        }
    }
    rt;
}