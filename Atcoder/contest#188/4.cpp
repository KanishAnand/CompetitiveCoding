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

struct service {
    lli a, b, c;
};

void solve() {
    lli n, subs;
    cin >> n >> subs;
    vector<struct service> v;

    set<lli> st;
    for (lli i = 0; i < n; i++) {
        struct service tmp;
        cin >> tmp.a >> tmp.b >> tmp.c;
        st.insert(tmp.a);
        st.insert(tmp.b);
        st.insert(tmp.b + 1);
        v.pb(tmp);
    }

    map<lli, lli> mp, rev_map;

    lli cnt = 0;
    for (auto val : st) {
        mp[val] = cnt;
        rev_map[cnt] = val;
        cnt++;
    }

    vector<lli> sum(cnt + 2, 0);
    for (lli i = 0; i < n; i++) {
        sum[mp[v[i].a]] += v[i].c;
        sum[mp[v[i].b + 1]] -= v[i].c;
    }

    for (lli i = 0; i < cnt; i++) {
        if (i != 0) {
            sum[i] += sum[i - 1];
        }
    }

    lli ans = 0;
    for (lli i = 0; i < cnt; i++) {
        lli p = min(sum[i], subs);
        lli dur = rev_map[i + 1] - rev_map[i];
        if (i == cnt - 1) {
            dur = 1;
        }
        ans += dur * p;
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