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
lli ans = 0;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

lli calc(lli a) {
    lli val = (a * (a - 1)) / 2;
    return val;
}

lli merge(lli a, lli b) {
    if (rankk[a] >= rankk[b]) {
        king[b] = king[a];
        ans -= calc(rankk[a]);
        ans -= calc(rankk[b]);
        rankk[a] += rankk[b];
        ans += calc(rankk[a]);
    } else {
        king[a] = king[b];
        ans -= calc(rankk[a]);
        ans -= calc(rankk[b]);
        rankk[b] += rankk[a];
        ans += calc(rankk[b]);
    }
}

void solve() {
    lli n, a, m, b, c, q;
    cin >> n >> m;
    king.resize(n + 2);
    rankk.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    vector<pair<lli, pair<lli, lli>>> edg;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        edg.pb({c, {a, b}});
    }

    lli ptr = 0;
    sort(all(edg));

    vector<pair<lli, lli>> query;
    for (lli i = 0; i < m; i++) {
        cin >> q;
        query.pb({q, i});
    }

    sort(all(query));
    vector<lli> an(m + 2, 0);

    for (lli i = 0; i < query.size(); i++) {
        lli val = query[i].first;
        while (ptr < sz(edg) && edg[ptr].first <= val) {
            lli p = edg[ptr].second.first;
            lli q = edg[ptr].second.second;
            p = find(p);
            q = find(q);
            if (p != q) {
                merge(p, q);
            }
            ptr++;
        }
        an[query[i].second] = ans;
    }

    for (lli i = 0; i < m; i++) {
        cout << an[i] << " ";
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