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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

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
    cin >> n;
    string st;
    cin >> st;
    lli mn = -1;
    lli val1, val2;

    for (lli beg = 0; beg < n; beg++) {
        for (lli end = beg; end < n; end++) {
            char temp = st[end];
            st[end] = st[beg];
            st[beg] = temp;
            lli f = 0, val = 0;
            fr(i, 0, n) {
                if (st[i] == ')') {
                    if (f != 0) {
                        f -= 1;
                    } else {
                        val++;
                    }
                } else {
                    f++;
                }

                if (f == 0) {
                    pref[i][1] = val;
                    pref[i][0] = 0;
                } else {
                    pref[i][0] = 1;
                    pref[i][1] = 0;
                }
            }
            f = 0, val = 0;
            for (lli i = n - 1; i >= 0; i--) {
                if (st[i] == '(') {
                    if (f != 0) {
                        f -= 1;
                    } else {
                        val++;
                    }
                } else {
                    f++;
                }
                if (f == 0) {
                    suff[i][1] = val;
                    suff[i][0] = 0;
                } else {
                    suff[i][0] = 1;
                    suff[i][1] = 0;
                }
            }

            lli ans = 0;
            for (lli i = n - 1; i >= 0; i--) {
                if (i != 0) {
                    if (pref[i - 1][0] != 1 && suff[i][0] != 1) {
                        if (pref[i - 1][1] == suff[i][1]) {
                            ans++;
                        }
                    }
                } else {
                    if (suff[i][0] == 0 && suff[i][1] == 0) {
                        ans++;
                    }
                }
            }
            if (ans > mn) {
                mn = ans;
                val1 = beg;
                val2 = end;
            }
            temp = st[end];
            st[end] = st[beg];
            st[beg] = temp;
        }
    }
    cout << mn << "\n";
    cout << val1 + 1 << " " << val2 + 1 << "\n";
    rt;
}