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

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % MOD;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

void solve() {
    lli n, a, s, b;
    vector<pair<lli, lli>> v;
    cin >> n >> s;
    lli beg = 1e15, end = -1, left = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        left += a;
        beg = min(beg, a);
        end = max(end, b);
        v.pb({a, b});
    }

    lli ans = -1;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli cnt = 0, left2 = 0, left3 = 0, cnt2 = 0;
        multiset<lli> st;

        for (lli i = 0; i < n; i++) {
            if (mid >= v[i].first && mid <= v[i].second) {
                cnt++;
                left2 += v[i].first;
                st.insert(v[i].first);
            } else if (v[i].first > mid) {
                cnt2++;
                left3 += v[i].first;
            }
        }

        if (cnt + cnt2 < (n + 1) / 2) {
            end = mid - 1;
        } else if (cnt2 >= (n + 1) / 2) {
            beg = mid + 1;
            ans = max(ans, mid);
        } else {
            lli val = left3;
            val += mid * ((n + 1) / 2 - cnt2);
            val += left - (left2 + left3);
            lli c = cnt + cnt2 - (n + 1) / 2;

            for (auto it : st) {
                if (c == 0) {
                    break;
                }
                val += it;
                c--;
            }

            if (val > s) {
                end = mid - 1;
            } else {
                beg = mid + 1;
                ans = max(ans, mid);
            }
        }
    }
    cout << ans << endl;
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