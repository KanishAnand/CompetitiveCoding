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
    } else {
        return a;
    }
}

lli merge(lli a, lli b) {
    if (rankk[a] >= rankk[b]) {
        rankk[a] += rankk[b];
        king[b] = king[a];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void solve() {
    lli n, a, b, p, q;
    cin >> n;
    king.resize(n + 2);
    rankk.resize(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    vector<pair<lli, lli>> remove, add;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        p = find(a);
        q = find(b);
        if (p == q) {
            remove.pb({a, b});
        } else {
            merge(p, q);
        }
    }

    for (lli i = 1; i <= n; i++) {
        p = find(1);
        q = find(i);
        if (q != p) {
            add.pb({p, q});
            merge(p, q);
        }
    }

    cout << remove.size() << endl;
    for (lli i = 0; i < sz(remove); i++) {
        cout << remove[i].first << " " << remove[i].second << " "
             << add[i].first << " " << add[i].second << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}