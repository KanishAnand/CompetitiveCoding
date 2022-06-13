#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
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

struct val {
    lli a, b, c;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, c;
    vector<struct val> v;
    cin >> n;
    fr(i, 0, n) {
        struct val t;
        cin >> t.a >> t.b >> t.c;
        v.pb(t);
    }

    struct val p;
    p.a = -1, p.b = -1, p.c = -1;

    vector<struct val> dp(n + 2, p);
    dp[0].a = v[0].a;
    dp[0].b = v[0].b;
    dp[0].c = v[0].c;

    for (lli i = 1; i < n; i++) {
        dp[i].a = max(v[i].a + dp[i - 1].b, v[i].a + dp[i - 1].c);
        dp[i].b = max(v[i].b + dp[i - 1].a, v[i].b + dp[i - 1].c);
        dp[i].c = max(v[i].c + dp[i - 1].b, v[i].c + dp[i - 1].a);
    }

    cout << max({dp[n - 1].a, dp[n - 1].b, dp[n - 1].c}) << endl;
    rt;
}