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
    lli n, a, t;
    vector<lli> v;
    cin >> t;
    while (t--) {
        cin >> n;
        string st;
        lli cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        vector<string> v1, v2;
        vector<lli> v1i, v2i;
        set<string> s1, s2;
        fr(i, 0, n) {
            cin >> st;
            lli len = st.length();
            if (st[0] == '0' && st[len - 1] == '1') {
                cnt1++;
                v1.pb(st);
                v1i.pb(i + 1);
                s1.insert(st);
            }
            if (st[0] == '1' && st[len - 1] == '0') {
                cnt2++;
                v2.pb(st);
                v2i.pb(i + 1);
                s2.insert(st);
            }
            if (st[0] == '1' && st[len - 1] == '1') {
                cnt3++;
            }
            if (st[0] == '0' && st[len - 1] == '0') {
                cnt4++;
            }
        }

        if (cnt1 == 0 && cnt2 == 0) {
            if (cnt3 != 0 && cnt4 != 0) {
                cout << "-1" << endl;
            } else {
                cout << "0" << endl;
            }
            continue;
        }

        lli ans = 0, flag = 0, p = 0;
        vector<lli> pp;

        if (cnt1 > cnt2) {
            p = cnt1 - cnt2;
            p = p / 2;
            for (lli i = 0; i < v1.size(); i++) {
                if (p <= 0) {
                    break;
                }
                string tt = v1[i];
                reverse(all(tt));
                if (s2.find(tt) == s2.end()) {
                    pp.pb(v1i[i]);
                    --p;
                }
            }
        } else if (cnt1 < cnt2) {
            p = cnt2 - cnt1;
            p = p / 2;
            for (lli i = 0; i < v2.size(); i++) {
                if (p <= 0) {
                    break;
                }
                string tt = v2[i];
                reverse(tt.begin(), tt.end());
                if (s1.find(tt) == s1.end()) {
                    pp.pb(v2i[i]);
                    --p;
                }
            }
        }
        flag = p;
        if (flag == 0) {
            cout << (abs(cnt1 - cnt2)) / 2 << endl;
            for (lli i = 0; i < pp.size(); i++) {
                cout << pp[i] << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    rt;
}
