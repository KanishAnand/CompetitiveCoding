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
const double PI = 3.14159265358979323846264338;
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
    cin >> n;
    lli cnt = 0;

    while (n % 6 == 0) {
        n /= 6;
        cnt++;
    }

    if (n == 1) {
        cout << cnt << endl;
        return;
    }

    lli flag = 0;

    while (1) {
        if (n == 1) {
            break;
        }
        if (flag == 0) {
            n *= 2;
            cnt++;
            flag = 1;
        } else {
            if (n % 6 == 0) {
                cnt++;
                n /= 6;
            } else {
                break;
            }
            flag = 0;
        }
    }

    if (n != 1) {
        cout << "-1" << endl;
    } else {
        cout << cnt << endl;
    }
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