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
    lli n, m;
    cin >> n >> m;
    string st;

    vector<vector<char>> adj(n + 2, vector<char>(n + 2));

    for (lli i = 0; i < n; i++) {
        cin >> st;
        for (lli j = 0; j < n; j++) {
            adj[i + 1][j + 1] = st[j];
        }
    }

    if (m % 2 == 1) {
        cout << "YES" << endl;
        lli flag = 1;
        for (lli i = 0; i < m; i++) {
            cout << flag << " ";
            if (flag == 1) {
                flag = 2;
            } else {
                flag = 1;
            }
        }
        cout << flag << endl;
        return;
    }

    lli ind1 = -1, ind2 = -1, ind3 = -1;

    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (adj[i][j] == adj[j][i]) {
                ind1 = i;
                ind2 = j;
                break;
            }
        }
        if (ind1 != -1) {
            break;
        }
    }

    if (ind1 != -1) {
        cout << "YES" << endl;
        lli flag = 1;
        for (lli i = 0; i < m + 1; i++) {
            if (flag == 1) {
                cout << ind1 << " ";
                flag = 0;
            } else {
                cout << ind2 << " ";
                flag = 1;
            }
        }
        cout << endl;
        return;
    }

    if (n == 2) {
        cout << "NO" << endl;
        return;
    }

    for (lli ind = 1; ind <= 3; ind++) {
        ind1 = -1, ind2 = -1, ind3 = -1;
        for (lli i = 1; i <= n; i++) {
            if (i == ind) {
                continue;
            }
            if (adj[i][ind] == 'a') {
                ind1 = i;
                ind2 = ind;
            }
            if (adj[i][ind] == 'b') {
                ind3 = i;
                ind2 = ind;
            }
        }
        if (ind1 != -1 && ind2 != -1 && ind3 != -1) {
            break;
        }
    }

    cout << "YES" << endl;

    if (m == 2) {
        cout << ind1 << " " << ind2 << " " << ind3 << endl;
    } else if (m % 4 == 0) {
        for (lli i = 0; i < m / 4; i++) {
            cout << ind2 << " " << ind3 << " " << ind2 << " " << ind1 << " ";
        }
        cout << ind2 << endl;
    } else {
        for (lli i = 0; i < m / 4; i++) {
            cout << ind1 << " " << ind2 << " " << ind3 << " " << ind2 << " ";
        }
        cout << ind1 << " " << ind2 << " " << ind3 << " ";
        cout << endl;
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