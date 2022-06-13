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
vector<lli> king, rankk;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] >= rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        king[a] = king[b];
        rankk[b] += rankk[a];
    }
}

void solve() {
    lli n, a, m, b, c;
    cin >> n >> m;
    king.resize(n + 2, 0);
    rankk.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    vector<lli> v;
    v.pb(0);
    lli mn = 1e14, ind;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        if (a < mn) {
            mn = a;
            ind = i + 1;
        }
    }

    vector<pair<lli, pair<lli, lli>>> edges;
    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.pb({c, {a, b}});
    }

    for (lli i = 1; i <= n; i++) {
        if (i == ind) {
            continue;
        }
        edges.pb({v[ind] + v[i], {ind, i}});
    }

    sort(all(edges));
    lli ans = 0, cnt = 0;

    for (lli i = 0; i < sz(edges); i++) {
        a = edges[i].second.first;
        b = edges[i].second.second;
        a = find(a);
        b = find(b);
        if (a != b) {
            merge(a, b);
            ans += edges[i].first;
            cnt++;
        }
        if (cnt == n - 1) {
            break;
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