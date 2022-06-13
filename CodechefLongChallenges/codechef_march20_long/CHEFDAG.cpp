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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<lli>> v(k + 2);
        vector<vector<lli>> ind(k + 2, vector<lli>(n + 2, 0));

        fr(i, 0, k) {
            fr(j, 0, n) {
                cin >> a;
                ind[i][a] = j;
                v[i].pb(a);
            }
        }

        lli mnval = 1e15;
        vector<lli> mnans;

        for (lli beg = 0; beg < k; beg++) {
            vector<lli> flag(n + 2, 0);
            lli val = 1;

            for (lli no = 1; no <= n; no++) {
                if (flag[no] != 0) {
                    continue;
                }
                // if flag == 0:
                lli check = no, prev = no;
                flag[no] = val;

                for (lli i = ind[beg][no] + 1; i < n; i++) {
                    check = v[beg][i];

                    if (flag[check] != 0) {
                        continue;
                    }

                    lli ff = 0;
                    for (lli j = 0; j < k; j++) {
                        if (ind[j][check] < ind[j][prev]) {
                            ff = 1;
                            break;
                        }
                    }

                    if (ff == 0) {
                        flag[check] = val;
                        prev = check;
                    }
                }

                prev = no;

                for (lli i = ind[beg][no] - 1; i >= 0; i--) {
                    check = v[beg][i];

                    if (flag[check] != 0) {
                        continue;
                    }

                    lli ff = 0;
                    for (lli j = 0; j < k; j++) {
                        if (ind[j][check] > ind[j][prev]) {
                            ff = 1;
                            break;
                        }
                    }

                    if (ff == 0) {
                        flag[check] = val;
                        prev = check;
                    }
                }

                val++;
            }

            vector<lli> store(val + 2, 0), ans(n + 2, 0);

            for (lli i = n - 1; i >= 0; i--) {
                lli pp = v[beg][i];
                if (store[flag[pp]] != 0) {
                    ans[pp] = store[flag[pp]];
                }
                store[flag[pp]] = pp;
            }

            if (val - 1 < mnval) {
                mnval = val - 1;
                mnans = ans;
            }
        }

        cout << mnval << endl;
        fr(i, 1, n + 1) {
            cout << mnans[i] << " ";
        }
        cout << endl;
    }
    rt;
}
