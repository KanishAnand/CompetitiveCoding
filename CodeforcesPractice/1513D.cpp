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

lli find(vector<lli> &king, lli a) {
    if (king[a] != a) {
        king[a] = find(king, king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(vector<lli> &king, vector<lli> &rankk, lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void solve() {
    lli n, p, a, b;
    cin >> n >> p;

    vector<lli> king(n + 2), rankk(n + 2, 1);
    for (lli i = 0; i < n; i++) {
        king[i] = i;
    }

    vector<pair<lli, lli>> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb({a, i});
    }

    auto cp = v;
    sort(all(cp));

    lli ans = 0, cnt = 0;
    for (auto pr : cp) {
        lli el = pr.first, ind = pr.second, gcd = el;
        if (el >= p) {
            break;
        }

        for (lli i = ind + 1; i < n; i++) {
            gcd = __gcd(gcd, v[i].first);
            if (gcd != el) {
                break;
            }
            a = find(king, ind);
            b = find(king, v[i].second);
            if (a == b) {
                break;
            } else {
                cnt++;
                ans += el;
                merge(king, rankk, a, b);
            }
        }

        gcd = el;
        for (lli i = ind - 1; i >= 0; i--) {
            gcd = __gcd(gcd, v[i].first);
            if (gcd != el) {
                break;
            }
            a = find(king, ind);
            b = find(king, v[i].second);
            if (a == b) {
                break;
            } else {
                cnt++;
                ans += el;
                merge(king, rankk, a, b);
            }
        }
    }

    ans += (n - 1 - cnt) * p;
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