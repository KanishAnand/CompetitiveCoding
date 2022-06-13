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
    string a, b;
    cin >> a >> b;

    int n1 = len(a);
    int n2 = len(b);

    int ans = n1 + n2;

    for (int start_a = 0; start_a < n1; start_a++) {
        string tmp_a = "";
        for (int end_a = start_a; end_a < n1; end_a++) {
            tmp_a += a[end_a];
            int val1 = start_a + (n1 - 1 - end_a);

            for (int start_b = 0; start_b < n2; start_b++) {
                string tmp_b = "";
                for (int end_b = start_b; end_b < n2; end_b++) {
                    tmp_b += b[end_b];
                    int val2 = start_b + (n2 - 1 - end_b);

                    if (tmp_a == tmp_b) {
                        int val = val1 + val2;
                        ans = min(ans, val);
                    }
                }
            }
        }
    }

    cout << ans << endl;
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