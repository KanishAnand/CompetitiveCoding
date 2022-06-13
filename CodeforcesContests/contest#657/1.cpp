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

lli n;
lli len = 7;
string ch = "abacaba";

lli check(lli ind, string st) {
    if (n - ind < len) {
        return 0;
    }

    lli p = 0;
    for (lli i = ind; i < ind + 7; i++) {
        if (st[i] != ch[p]) {
            return 0;
        }
        p++;
    }

    return 1;
}

void solve() {
    cin >> n;
    string st;
    cin >> st;

    lli cnt = 0;
    for (lli i = 0; i < n; i++) {
        lli a = check(i, st);
        if (a == 1) {
            cnt++;
        }
    }

    if (cnt >= 2) {
        cout << "NO" << endl;
        return;
    } else if (cnt == 1) {
        for (lli i = 0; i < n; i++) {
            if (st[i] == '?') {
                st[i] = 'z';
            }
        }
        cout << "YES" << endl;
        cout << st << endl;
        return;
    } else {
        for (lli i = 0; i <= n - 7; i++) {
            string tmp = st;
            lli p = 0, flag = 0;

            for (lli j = i; j < i + 7; j++) {
                if (st[j] != '?' && st[j] != ch[p]) {
                    flag = 1;
                    break;
                }
                p++;
            }

            if (flag == 1) {
                continue;
            }

            p = 0;
            for (lli j = i; j < i + 7; j++) {
                tmp[j] = ch[p];
                p++;
            }

            // cout << tmp << endl;
            lli a, cnt = 0;
            for (lli j = 0; j < n; j++) {
                a = check(j, tmp);
                if (a == 1) {
                    cnt++;
                }
            }

            if (cnt == 1) {
                cout << "YES" << endl;
                for (lli j = 0; j < n; j++) {
                    if (tmp[j] == '?') {
                        tmp[j] = 'z';
                    }
                }
                cout << tmp << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}