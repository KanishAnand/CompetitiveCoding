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
    while (n--) {
        string s, t;
        cin >> s >> t;
        if (s < t) {
            cout << s << endl;
        } else {
            lli l1 = s.length();
            lli l2 = t.length();
            lli l = min(l1, l2);
            char temp;
            lli flag = 0, p = 0;
            for (lli i = 0; i < l; i++) {
                p = 0;
                if (s[i] > t[i]) {
                    p = 1;
                }
                for (lli j = i + 1; j < l1; j++) {
                    if (s[j] < t[i]) {
                        flag = 1;
                        temp = s[j];
                        s[j] = s[i];
                        s[i] = temp;
                    }
                    if (flag == 1) {
                        break;
                    }
                }
                if (flag == 1) {
                    break;
                }
                if (flag == 0 && p == 1) {
                    char temp;
                    for (lli k = i + 1; k < l1; k++) {
                        if (s[k] == t[i]) {
                            temp = s[k];
                            s[k] = s[i];
                            s[i] = temp;
                            if (s < t) {
                                flag = 1;
                                break;
                            } else {
                                temp = s[k];
                                s[k] = s[i];
                                s[i] = temp;
                            }
                        }
                    }
                    break;
                }
            }

            if (s < t) {
                cout << s << endl;
            } else {
                cout << "---" << endl;
            }
        }
    }
    rt;
}
