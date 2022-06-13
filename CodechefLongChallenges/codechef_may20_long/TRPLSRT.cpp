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
struct ans {
    lli a, b, c;
};

void solve() {
    lli n, a, k, cnt = 0;
    cin >> n >> k;
    vector<lli> v;
    vector<lli> ind(n + 2);
    vector<struct ans> op;
    v.pb(0);

    for (lli i = 1; i <= n; i++) {
        cin >> a;
        v.pb(a);
        ind[a] = i;
    }

    vector<pair<lli, lli>> store;
    vector<lli> flag(n + 2, 0);

    for (lli i = n; i >= 1; i--) {
        if (i == v[i] || flag[i] == 1) {
            continue;
        }
        lli ind3 = ind[i];
        lli ind2 = ind[ind3];
        if (ind2 != i) {
            struct ans p;
            p.a = ind2;
            p.b = ind3;
            p.c = i;
            ind[i] = i;
            ind[ind3] = ind3;
            ind[v[i]] = ind2;
            v[ind2] = v[i];
            v[i] = i;
            v[ind3] = ind3;
            op.pb(p);
            cnt++;
        } else {
            store.pb({i, ind3});
            flag[i] = 1;
            flag[ind3] = 1;
        }
    }

    if (store.size() % 2 == 1) {
        cout << "-1" << endl;
    } else {
        for (lli i = 0; i < store.size(); i++) {
            op.pb({store[i].second, store[i + 1].first, store[i + 1].second});
            op.pb({store[i].first, store[i].second, store[i + 1].first});
            cnt += 2;
            i++;
        }
        cout << cnt << endl;
        for (lli i = 0; i < op.size(); i++) {
            cout << op[i].a << " " << op[i].b << " " << op[i].c << endl;
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