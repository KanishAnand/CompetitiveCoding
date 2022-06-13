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
    lli n, a, q, b;
    cin >> n >> q;
    lli arr[3][n + 3];
    fr(i, 0, 3) {
        fr(j, 0, n + 2) {
            arr[i][j] = 0;
        }
    }
    lli flag = 1;
    // flag = 1 yes
    lli cols = 0;
    vector<lli> v(n + 3, 0);
    fr(i, 0, q) {
        cin >> a >> b;
        lli val = 1;
        if (a == 1) {
            val = 2;
        }
        if (arr[a][b] == 1 && flag == 1) {
            arr[a][b] = 0;
            if (v[b] == 1 && b != 1) {
                lli f = 0;
                if (arr[val][b] == 0 && arr[val][b - 1] == 0) {
                    f = 1;
                } else if (arr[a][b] == 0 && arr[a][b - 1] == 0) {
                    f = 1;
                }
                if (f == 1) {
                    cols--;
                    v[b] = 0;
                }
            }
            if (b != n && v[b + 1] == 1) {
                lli f = 0;
                if (arr[val][b] == 0 && arr[val][b + 1] == 0) {
                    f = 1;
                } else if (arr[a][b] == 0 && arr[a][b + 1] == 0) {
                    f = 1;
                }
                if (f == 1) {
                    cols--;
                    v[b + 1] = 0;
                }
            }
            cout << "YES" << endl;
        } else if (arr[a][b] == 0 && flag == 1) {
            arr[a][b] = 1;
            if (v[b] == 0) {
                if (b != 1) {
                    lli f = 0;
                    if (arr[val][b] == 0 && arr[val][b - 1] == 0) {
                        f = 1;
                    }
                    if (arr[a][b] == 0 && arr[a][b - 1] == 0) {
                        f = 1;
                    }
                    if (f == 0) {
                        cols++;
                        v[b] = 1;
                    }
                }
            }
            if (b != n && v[b + 1] == 0) {
                lli f = 0;
                if (arr[val][b + 1] == 0 && arr[val][b] == 0) {
                    f = 1;
                }
                if (arr[a][b] == 0 && arr[a][b + 1] == 0) {
                    f = 1;
                }
                if (f == 0) {
                    cols++;
                    v[b + 1] = 1;
                }
            }
            if (cols == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
                flag = 0;
            }

        } else if (arr[a][b] == 0 && flag == 0) {
            arr[a][b] = 1;
            if (v[b] == 0) {
                if (b != 1) {
                    lli f = 0;
                    if (arr[val][b] == 0 && arr[val][b - 1] == 0) {
                        f = 1;
                    }
                    if (arr[a][b] == 0 && arr[a][b - 1] == 0) {
                        f = 1;
                    }
                    if (f == 0) {
                        cols++;
                        v[b] = 1;
                    }
                }
            }
            if (b != n && v[b + 1] == 0) {
                lli f = 0;
                if (arr[val][b + 1] == 0 && arr[val][b] == 0) {
                    f = 1;
                }
                if (arr[a][b] == 0 && arr[a][b + 1] == 0) {
                    f = 1;
                }
                if (f == 0) {
                    cols++;
                    v[b + 1] = 1;
                }
            }
            cout << "NO" << endl;
        } else {
            arr[a][b] = 0;
            if (v[b] == 1) {
                lli f = 0;
                if (arr[val][b - 1] == 0 && arr[val][b] == 0) {
                    f = 1;
                }
                if (arr[a][b] == 0 && arr[a][b - 1] == 0) {
                    f = 1;
                }
                if (f == 1) {
                    cols--;
                    v[b] = 0;
                }
            }
            if (b != n && v[b + 1] == 1) {
                lli f = 0;
                if (arr[val][b + 1] == 0 && arr[val][b] == 0) {
                    f = 1;
                }
                if (arr[a][b] == 0 && arr[a][b + 1] == 0) {
                    f = 1;
                }
                if (f == 1) {
                    cols--;
                    v[b + 1] = 0;
                }
            }
            if (cols == 0) {
                flag = 1;
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    rt;
}