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
    lli n, a, t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        vector<lli> ch(27, 0);
        lli len = s.length(), len2 = p.length();
        fr(i, 0, len) {
            ch[s[i] - 'a']++;
        }
        if (len2 < len) {
            cout << "NO" << endl;
            continue;
        }

        lli flag = 0;
        for (lli i = 0; i <= len2 - len; i++) {
            flag = 0;
            vector<lli> v(27, 0);
            // cout << i << " " << i + len << endl;

            for (lli j = i; j < i + len; j++) {
                // cout << p[j] << endl;
                v[p[j] - 'a']++;
            }
            // cout << v[25] << " " << ch[25] << endl;

            fr(k, 0, 26) {
                if (v[k] != ch[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    rt;
}
