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
vector<lli> col;
map<lli, map<lli, lli>> mp;

void fun(vector<lli> &v, lli a) {
    lli st = 0;
    for (lli i = 1; i <= n; i++) {
        if (col[i] == 0) {
            st = i;
            break;
        }
    }

    if (st == 0) {
        cout << "-1" << endl;
        exit(0);
    }

    v.pb(st);
    col[st] = a;
    for (lli i = st + 1; i <= n; i++) {
        if (col[i] == 0 && mp[st][i] == 0) {
            v.pb(i);
            col[i] = a;
        }
    }
}

void solve() {
    lli a, m, b;
    cin >> n >> m;
    col.resize(n + 2, 0);

    vector<pair<lli, lli>> edg;

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        edg.pb({a, b});
        mp[a][b] = 1;
        mp[b][a] = 1;
    }

    vector<lli> one, two, three;
    fun(one, 1);
    fun(two, 2);
    fun(three, 3);

    if (sz(one) == 0 || sz(two) == 0 || sz(three) == 0) {
        cout << "-1" << endl;
        return;
    }

    if (sz(one) + sz(two) + sz(three) != n) {
        cout << "-1" << endl;
        return;
    }

    for (auto val : edg) {
        if (col[val.first] == col[val.second]) {
            cout << "-1" << endl;
            return;
        }
    }

    lli val = sz(one) * sz(two) + sz(three) * sz(two) + sz(one) * sz(three);
    if (sz(edg) != val) {
        cout << "-1" << endl;
        return;
    }

    for (lli i = 1; i <= n; i++) {
        cout << col[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}