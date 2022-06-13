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
#define len(x) (lli)(x.length())
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
    lli zeros, ones, k;
    cin >> zeros >> ones >> k;

    if (k == 0) {
        string first = "", second = "";
        for (lli i = 0; i < ones; i++) {
            first += '1';
            second += '1';
        }
        for (lli i = 0; i < zeros; i++) {
            first += '0';
            second += '0';
        }
        cout << "Yes" << endl;
        cout << first << endl;
        cout << second << endl;
    } else if (ones == 1) {
        cout << "No" << endl;
    } else {
        if (k == zeros + 1) {
            if (ones >= 2) {
                string first = "", second = "";
                for (lli i = 0; i < ones - 2; i++) {
                    first += '1';
                    second += '1';
                }
                first += '1';
                second += '0';
                first += '1';
                second += '1';
                for (lli i = 0; i < k - 1; i++) {
                    first += '0';
                    second += '0';
                }
                first += '0';
                second += '1';
                for (lli i = 0; i < zeros - k; i++) {
                    first += '0';
                    second += '0';
                }
                cout << "Yes" << endl;
                cout << first << endl;
                cout << second << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (zeros + 1 < k) {
            cout << "No" << endl;
        } else {
            string first = "", second = "";
            for (lli i = 0; i < ones - 1; i++) {
                first += '1';
                second += '1';
            }
            first += '1';
            second += '0';
            for (lli i = 0; i < k - 1; i++) {
                first += '0';
                second += '0';
            }
            first += '0';
            second += '1';
            for (lli i = 0; i < zeros - k; i++) {
                first += '0';
                second += '0';
            }

            cout << "Yes" << endl;
            cout << first << endl;
            cout << second << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}
