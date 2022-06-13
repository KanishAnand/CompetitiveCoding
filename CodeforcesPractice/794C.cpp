#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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
    string s, t;
    cin >> s >> t;
    n = s.length();
    vector<lli> cnts(27, 0), cntt(27, 0);
    for (lli i = 0; i < s.length(); i++) {
        cnts[s[i] - 'a']++;
        cntt[t[i] - 'a']++;
    }

    vector<lli> ans(n + 2, -1);
    lli flag = 0;
    lli cnt = 0;

    while (cnt < n) {
        if (flag == 0) {
            // cout << "DF" << endl;
            // cout << cnt << endl;
            lli ind;
            for (lli i = 0; i < 26; i++) {
                if (cnts[i] != 0) {
                    ind = i;
                    break;
                }
            }
            lli p = 0;
            for (lli i = 25; i >= ind; i--) {
                if (cntt[i] != 0) {
                    p = 1;
                    break;
                }
            }

            if (p == 1) {
                flag = 1;
                ans[cnt] = ind;
                cnts[ind]--;
                cnt++;
            } else {
                break;
            }
        } else {
            // cout << "DE" << endl;
            // cout << cnt << endl;
            lli ind;
            for (lli i = 25; i >= 0; i--) {
                if (cntt[i] != 0) {
                    ind = i;
                    break;
                }
            }
            lli p = 0;
            for (lli i = 0; i <= ind; i++) {
                if (cnts[i] != 0) {
                    p = 1;
                    break;
                }
            }

            if (p == 1) {
                flag = 0;
                ans[cnt] = ind;
                cntt[ind]--;
                cnt++;
            } else {
                break;
            }
        }
    }

    vector<lli> v1, v2;
    lli ocnt = cnt, oflag = flag;

    while (cnt != n) {
        if (flag == 0) {
            flag = 1;
            for (lli i = 0; i < 26; i++) {
                if (cnts[i] != 0) {
                    cnts[i]--;
                    v1.pb(i);
                }
            }
        } else {
            flag = 0;
            for (lli i = 25; i >= 0; i--) {
                if (cntt[i] != 0) {
                    cntt[i]--;
                    v2.pb(i);
                }
            }
        }
        cnt++;
    }

    sort(all(v1));
    sort(v2.rbegin(), v2.rend());
    lli ptr1 = 0, ptr2 = 0;

    for (lli i = 0; i < n; i++) {
        if (ans[i] == -1) {
            if (oflag == 0) {
                oflag = 1;
                ans[i] = v1[ptr1];
                ptr1++;
            } else {
                oflag = 0;
                ans[i] = v2[ptr2];
                ptr2++;
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        cout << (char)(ans[i] + 'a');
    }

    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}