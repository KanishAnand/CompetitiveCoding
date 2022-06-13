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
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

void solve() {
    lli n, a, k, b, x;
    cin >> n >> k;

    king.resize(n + 2);
    rankk.resize(n + 2, 1);

    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    for (lli i = 1; i < n; i++) {
        cin >> a >> b >> x;
        if (x == 0) {
            lli p = find(a);
            lli q = find(b);
            merge(p, q);
        }
    }

    set<lli> st;
    for (lli i = 1; i <= n; i++) {
        st.insert(find(i));
    }

    lli ans = 0;
    for (auto val : st) {
        ans += power(rankk[val], k);
        ans %= MOD;
    }

    ans -= power(n, k);
    ans = -ans;
    ans += MOD;
    ans %= MOD;
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