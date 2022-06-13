#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m, k, b, c, u, v;
    // vector<vector<lli>> adj;
    set<set<pair<lli, lli>>> adj;  // sort reverse
    cin >> n >> m >> k;
    vector<lli> ve(n + 1, 0);
    adj.resize(n + 2);
    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, 0));
    struct store {
        lli p, q, r;
    };
    vector<struct store> st;

    fr(i, 0, n) {
        struct store o;
        cin >> o.p >> o.q >> o.r;
        st.pb(o);
    }

    fr(i, 0, m) {
        cin >> u >> v;
        ve[v] = max(ve[v], u);
    }

    vector<pair<lli, lli>> mx;
    fr(i, 1, n + 1) {
        if (ve[v] == n) {
            mx.pb({st[v].r, v});
        }
    }

    mx.pb({st[n - 1].r, n});
    sort(mx.rbegin(), mx.rend());
    lli cnt = st[n - 1].q, beg = 0;
    vector<lli> mark(n + 2, 0);
    lli ans;

    while (cnt > 0 && beg < mx.size()) {
        mark[mx[beg].second] = 1;
        ans += mx[beg].first;
        beg++;
    }

    fr(i, 1, n + 1) {
        if (ve[v] != 0 && mark[v] == 0) {
            adj[ve[v]].pb({st[v].r, v});
        } else if (ve[v] == 0) {
            adj[v].pb({st[v].r, v});
        }
    }

    vector<lli> extra;
    lli val = k;
    fr(i, 0, n) {
        if (val < st[i].p) {
            cout << "-1" << endl;
            rt;
        }
        extra.pb(val - st[i].p);
        val += st[i].q;
    }

    vector<lli> defend(n + 2, 0);
    val = extra[n - 1];
    for (lli i = n - 2; i >= 0; i--) {
        defend.pb(val);
        val = min(val, extra[i]);
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, 0));
    for (lli i = 1; i <= defend[0]; i++) {
    }
