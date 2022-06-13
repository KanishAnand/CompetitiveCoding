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
    if (n == 1) {
        cout << "FastestFinger" << endl;
        return;
    }
    if (n == 2) {
        cout << "Ashishgup" << endl;
        return;
    }

    lli two = 0;
    while (n % 2 == 0) {
        two++;
        n /= 2;
    }

    if (n == 1) {
        cout << "FastestFinger" << endl;
        return;
    }
    if (two != 1) {
        cout << "Ashishgup" << endl;
        return;
    }

    lli p = sqrt(n);
    lli cnt = 0;

    for (lli i = 2; i <= p; i++) {
        if (n % i == 0) {
            cnt++;
            break;
        }
    }

    if (cnt == 0) {
        cout << "FastestFinger" << endl;
    } else {
        cout << "Ashishgup" << endl;
    }
    return;
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