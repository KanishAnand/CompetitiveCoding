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
    cin >> n;
    lli ind = -1;

    vector<lli> prince(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        lli k, flag = 0;
        cin >> k;
        for (lli j = 0; j < k; j++) {
            cin >> a;
            if (prince[a] == 0 && flag == 0) {
                prince[a] = 1;
                flag = 1;
            }
        }
        if (flag == 0 && ind == -1) {
            ind = i;
        }
    }

    if (ind == -1) {
        cout << "OPTIMAL" << endl;
    } else {
        for (lli i = 1; i <= n; i++) {
            if (prince[i] == 0) {
                cout << "IMPROVE" << endl;
                cout << ind + 1 << " " << i << endl;
                return;
            }
        }
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