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
    string st;
    cin >> st;
    n = st.length();

    vector<lli> zeros(n + 5, 0), ones(n + 5, 0);
    vector<lli> suffzeros(n + 5, 0), suffones(n + 5, 0);

    if (st[0] == '0') {
        zeros[0] = 1;
    } else {
        ones[0] = 1;
    }

    if (st[n - 1] == '0') {
        suffzeros[n - 1] = 1;
    } else {
        suffones[n - 1] = 1;
    }

    for (lli i = 1; i < n; i++) {
        zeros[i] = zeros[i - 1];
        ones[i] = ones[i - 1];
        if (st[i] == '0') {
            zeros[i]++;
        } else {
            ones[i]++;
        }
    }

    for (lli i = n - 2; i >= 0; i--) {
        suffzeros[i] = suffzeros[i + 1];
        suffones[i] = suffones[i + 1];
        if (st[i] == '0') {
            suffzeros[i]++;
        } else {
            suffones[i]++;
        }
    }

    lli ans = n + 2;

    for (lli i = 0; i < n; i++) {
        // 01
        lli val1 = ones[i] + suffzeros[i + 1];
        lli val2;

        if (i != 0) {
            val2 = ones[i - 1] + suffzeros[i];
        } else {
            val2 = suffzeros[i];
        }

        lli val3 = zeros[i] + suffones[i + 1];
        lli val4;
        if (i != 0) {
            val4 = zeros[i - 1] + suffones[i];
        } else {
            val4 = suffones[i];
        }

        // cout << ans << endl;
        ans = min({ans, val1, val2, val3, val4});
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    // cout << "p" << endl;
    while (t--)
        solve();
    rt;
}