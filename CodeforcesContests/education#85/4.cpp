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
    lli n, a, l, r, ind = 0;
    cin >> n >> l >> r;
    vector<lli> v;

    for (lli i = 1; i <= n; i++) {
        if (i * (i + 1) < l) {
            ind = i;
        }
    }

    lli beg = ind * (ind + 1) + 1;
    lli flag = 0, val = 1, cnt = 0;
    ind++;

    if (beg >= l && beg <= r) {
        cout << "1 ";
    }
    beg++;

    while (1) {
        if (cnt == 2 * ind - 1) {
            if (beg >= l && beg <= r) {
                cout << "1 ";
            }
            ind++;
            cnt = 0;
            val = 1;
            flag = 0;
            beg++;
            continue;
        }

        if (flag == 0) {
            if (beg >= l && beg <= r) {
                cout << ind + 1 << " ";
            }
            flag = 1;
        } else {
            if (beg >= l && beg <= r) {
                cout << val + 1 << " ";
            }
            val++;
            flag = 0;
        }

        cnt++;
        beg++;
        if (beg > r) {
            break;
        }
    }

    cout << endl;
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