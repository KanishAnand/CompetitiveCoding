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

lli n, A, R, M;
vector<lli> v;

lli fun(lli a) {
    lli val = min(M, A + R), ans = 0;
    lli more = 0, less = 0;
    for (lli i = 0; i < n; i++) {
        if (v[i] < a) {
            less += a - v[i];
        }
        if (v[i] > a) {
            more += v[i] - a;
        }
    }

    if (more <= less) {
        ans += (less - more) * A;
        ans += more * val;
    } else {
        ans += (more - less) * R;
        ans += less * val;
    }
    return ans;
}

void solve() {
    lli a, ans = 1e15;
    cin >> n >> A >> R >> M;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli start = v[0], end = v[0];

    for (lli i = 0; i < n; i++) {
        start = min(v[i], start);
        end = max(v[i], end);
    }

    while ((end - start) >= 2) {
        lli mid = (start + end) / 2;
        lli val1 = fun(mid - 1);
        lli val2 = fun(mid);
        lli val3 = fun(mid + 1);
        if (val1 >= val2 && val2 >= val3) {
            start = mid;
        } else if (val1 <= val2 && val2 <= val3) {
            end = mid;
        } else if (val1 >= val2 && val3 >= val2) {
            ans = val2;
            break;
        }
    }

    for (lli i = start; i <= end; i++) {
        ans = min(ans, fun(i));
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