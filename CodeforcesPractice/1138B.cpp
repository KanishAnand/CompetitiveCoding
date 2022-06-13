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
    lli n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    lli a = 0, b = 0, c = 0, d = 0;

    for (lli i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '0') {
            a++;
        } else if (s[i] == '1' && t[i] == '0') {
            b++;
        } else if (s[i] == '0' && t[i] == '1') {
            c++;
        } else {
            d++;
        }
    }

    lli ansb, ansd, ansc, flag = 0;

    for (lli i = 0; i <= b; i++) {
        for (lli j = 0; j <= d; j++) {
            if (i + j > n / 2) {
                break;
            }
            lli req_c = (i + j) - (d - j);
            if (req_c <= c && req_c >= 0) {
                lli val1 = i + j + (c - req_c);
                lli val2 = (d - j) + req_c + (b - i);
                if (val1 <= n / 2 && val2 <= n / 2) {
                    flag = 1;
                    ansb = i;
                    ansd = j;
                    ansc = c - req_c;
                    break;
                }
            }
        }
        if (flag == 1) {
            break;
        }
    }

    if (!flag) {
        cout << "-1" << endl;
        return;
    }

    lli ansa = n / 2 - (ansb + ansc + ansd);
    for (lli i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '0') {
            if (ansa > 0) {
                cout << i + 1 << " ";
                ansa--;
            }
        } else if (s[i] == '1' && t[i] == '0') {
            if (ansb > 0) {
                cout << i + 1 << " ";
                ansb--;
            }
        } else if (s[i] == '0' && t[i] == '1') {
            if (ansc > 0) {
                cout << i + 1 << " ";
                ansc--;
            }
        } else {
            if (ansd > 0) {
                cout << i + 1 << " ";
                ansd--;
            }
        }
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