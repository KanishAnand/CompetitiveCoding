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

double fun(lli l, lli r, lli prize, lli flag) {
    double val = 1;
    if (flag == 0) {
        if (prize >= r) {
            val *= 1;
        } else if (prize >= l) {
            double num = prize - l + 1;
            double den = r - l + 1;
            val *= (num / den);
        } else {
            val = 0;
        }
    } else {
        if (prize <= l) {
            val *= 1;
        } else if (prize <= r) {
            double num = r - prize + 1;
            double den = r - l + 1;
            val *= (num / den);
        } else {
            val = 0;
        }
    }
    return val;
}

void solve() {
    lli n, l, r;
    cin >> n;
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        v.pb({l, r});
    }

    double ans = 0;

    for (lli winner = 0; winner < n; winner++) {
        for (lli prize = 1; prize <= 10000; prize++) {
            double val = 1, val_sub = 1;
            for (lli i = 0; i < n; i++) {
                if (i != winner) {
                    val *= fun(v[i].first, v[i].second, prize, 0);
                    val_sub *= fun(v[i].first, v[i].second, prize - 1, 0);
                } else {
                    val *= fun(v[i].first, v[i].second, prize + 1, 1);
                    val_sub *= fun(v[i].first, v[i].second, prize + 1, 1);
                }
            }
            double mon = prize;
            mon *= (val - val_sub);
            ans += mon;
        }
    }

    for (lli prize = 1; prize <= 10000; prize++) {
        double val = 1, val_sub = 1;
        for (lli i = 0; i < n; i++) {
            val *= fun(v[i].first, v[i].second, prize, 0);
            val_sub *= fun(v[i].first, v[i].second, prize - 1, 0);
        }
        double mon = prize;
        mon *= (val - val_sub);
        ans += mon;

        for (lli i = 0; i < n; i++) {
            double val = 1;
            for (lli j = 0; j < n; j++) {
                if (i != j) {
                    val *= fun(v[j].first, v[j].second, prize - 1, 0);
                } else {
                    if (prize >= v[j].first && prize <= v[j].second) {
                        double den = v[j].second - v[j].first + 1;
                        double p = 1;
                        p /= den;
                        val *= p;
                    } else {
                        val = 0;
                    }
                }
            }
            ans -= (prize * val);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}