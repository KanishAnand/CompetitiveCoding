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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<lli> king, rankk;

lli find(lli val) {
    if (king[val] == val) {
        return val;
    }
    king[val] = find(king[val]);
    return king[val];
}

lli merge(lli a, lli b) {
    if (rankk[a] < rankk[b]) {
        king[a] = king[b];
    } else if (rankk[a] == rankk[b]) {
        king[a] = king[b];
        ++rankk[b];
    } else {
        king[b] = king[a];
    }
    return 0;
}

void solve() {
    lli n, m;
    cin >> n >> m;

    lli a, b, c;
    vector<pair<lli, pair<lli, lli>>> edges;
    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.pb({c, {a, b}});
    }

    sort(all(edges));

    king.resize(n + 2);
    rankk.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    lli ans = 0;
    for (auto edg : edges) {
        a = edg.second.first, b = edg.second.second;
        lli c = find(a), d = find(b);
        if (c != d) {
            merge(c, d);
        } else {
            if (edg.first > 0) {
                ans += edg.first;
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}