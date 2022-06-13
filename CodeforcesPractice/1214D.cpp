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

lli n, m, flag;
vector<string> path;

void dfs(lli r, lli c) {
    if (r == n - 1 && c == m - 1) {
        flag = 1;
    }

    if (flag == 0 && r + 1 < n && path[r + 1][c] == '.') {
        // mark visited
        path[r + 1][c] = '$';
        dfs(r + 1, c);
    }
    if (flag == 0 && c + 1 < m && path[r][c + 1] == '.') {
        path[r][c + 1] = '$';
        dfs(r, c + 1);
    }
}

void solve() {
    lli a;
    cin >> n >> m;
    string st;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        path.pb(st);
    }

    flag = 0;
    dfs(0, 0);

    if (flag == 0) {
        cout << "0" << endl;
        return;
    }

    flag = 0;
    path[n - 1][m - 1] = '.';
    dfs(0, 0);

    if (flag == 0) {
        cout << "1" << endl;
    } else {
        cout << "2" << endl;
    }

    // lli cnt = 0;
    // queue<pair<pair<lli, lli>, lli>> qu;
    // qu.push({{0, 0}, 1});
    // path[0][0] = '$';

    // while (!qu.empty()) {
    //     auto a = qu.front();
    //     qu.pop();
    //     lli lvl = a.second, r = a.first.first, c = a.first.second;

    //     if (r + 1 == n - 1 && c == m - 1) {
    //         cnt++;
    //     }
    //     if (r == n - 1 && c + 1 == m - 1) {
    //         cnt++;
    //     }

    //     if (r + 1 < n && path[r + 1][c] == '.') {
    //         // mark visited
    //         path[r + 1][c] = '$';
    //         qu.push({{r + 1, c}, lvl + 1});
    //     }
    //     if (c + 1 < m && path[r][c + 1] == '.') {
    //         path[r][c + 1] = '$';
    //         qu.push({{r, c + 1}, lvl + 1});
    //     }
    // }

    // cnt = min(2ll, cnt);
    // cout << cnt << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}