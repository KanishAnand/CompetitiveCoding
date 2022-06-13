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

struct range {
    lli l, r;
};

void solve() {
    lli n, a, x;
    cin >> n >> x;
    vector<struct range> v;
    set<lli> st;
    st.insert(x);

    for (lli i = 0; i < n; i++) {
        struct range tmp;
        cin >> tmp.l >> tmp.r;
        st.insert(tmp.l);
        st.insert(tmp.r);
        v.pb(tmp);
    }

    vector<lli> no;
    for (auto val : st) {
        no.pb(val);
    }

    lli inf = 1e15;
    vector<lli> dp(sz(no) + 2, inf);
    vector<lli> prevdp(sz(no) + 2, inf);

    for (lli i = 0; i < sz(no); i++) {
        lli p = 0, pos = no[i];
        if (pos < v[0].l) {
            p = v[0].l - pos;
        } else if (pos > v[0].r) {
            p = pos - v[0].r;
        }
        dp[i] = p + abs(x - pos);
    }

    prevdp = dp;

    for (lli i = 1; i < n; i++) {
        lli mn = inf;
        for (lli j = 0; j < sz(no); j++) {
            lli p = 0, pos = no[j], q = 0;
            if (pos < v[i].l) {
                p = v[i].l - pos;
            } else if (pos > v[i].r) {
                p = pos - v[i].r;
            }
            if (j != 0) {
                q = no[j] - no[j - 1];
            }
            mn = min(mn + q, prevdp[j]);
            dp[j] = mn + p;
        }

        mn = inf;
        for (lli j = sz(no) - 1; j >= 0; j--) {
            lli p = 0, pos = no[j], q = 0;
            if (pos < v[i].l) {
                p = v[i].l - pos;
            } else if (pos > v[i].r) {
                p = pos - v[i].r;
            }
            if (j != sz(no) - 1) {
                q = no[j + 1] - no[j];
            }
            mn = min(mn + q, prevdp[j]);
            dp[j] = min(dp[j], mn + p);
        }

        prevdp = dp;
    }

    lli ans = inf;
    for (lli i = 0; i < sz(no); i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}