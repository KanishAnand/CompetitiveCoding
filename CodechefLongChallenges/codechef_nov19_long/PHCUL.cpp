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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        long double x, y, n, m, k;
        cin >> x >> y;
        cin >> n >> m >> k;
        vector<long double> a, b, c, d, e, f;
        long double p, q;
        fr(i, 0, n) {
            cin >> p >> q;
            a.pb(p);
            b.pb(q);
        }
        fr(i, 0, m) {
            cin >> p >> q;
            c.pb(p);
            d.pb(q);
        }
        fr(i, 0, k) {
            cin >> p >> q;
            e.pb(p);
            f.pb(q);
        }

        vector<long double> v2, v1;

        for (lli i = 0; i < m; i++) {
            long double mn = 1e15;
            for (lli j = 0; j < k; j++) {
                long double mm = abs(f[j] - d[i]);
                long double nn = abs(e[j] - c[i]);
                mm *= mm;
                nn *= nn;
                long double dis = sqrt(nn + mm);
                if (dis < mn) {
                    mn = dis;
                }
            }
            v2.pb(mn);
        }

        for (lli i = 0; i < n; i++) {
            long double mn = 1e15;
            for (lli j = 0; j < m; j++) {
                long double mm = abs(d[j] - b[i]);
                long double nn = abs(c[j] - a[i]);
                mm *= mm;
                nn *= nn;
                long double dis = sqrt(mm + nn);
                if (dis + v2[j] < mn) {
                    mn = dis + v2[j];
                }
            }
            v1.pb(mn);
        }

        long double ans = 1e15;
        for (lli i = 0; i < n; i++) {
            long double mm = abs(y - b[i]);
            long double nn = abs(x - a[i]);
            mm *= mm;
            nn *= nn;
            long double dis = sqrt(mm + nn);
            if (dis + v1[i] < ans) {
                ans = dis + v1[i];
            }
        }

        //
        vector<long double> ve2, ve1;

        for (lli i = 0; i < n; i++) {
            long double mn = 1e15;
            for (lli j = 0; j < k; j++) {
                long double mm = abs(f[j] - b[i]);
                long double nn = abs(e[j] - a[i]);
                mm *= mm;
                nn *= nn;
                long double dis = sqrt(mm + nn);
                if (dis < mn) {
                    mn = dis;
                }
            }
            ve2.pb(mn);
        }

        for (lli i = 0; i < m; i++) {
            long double mn = 1e15;
            for (lli j = 0; j < n; j++) {
                long double mm = abs(d[i] - b[j]);
                long double nn = abs(c[i] - a[j]);
                mm *= mm;
                nn *= nn;
                long double dis = sqrt(mm + nn);
                if (dis + ve2[j] < mn) {
                    mn = dis + ve2[j];
                }
            }
            ve1.pb(mn);
        }

        for (lli i = 0; i < m; i++) {
            long double mm = abs(y - d[i]);
            long double nn = abs(x - c[i]);
            mm *= mm;
            nn *= nn;
            long double dis = sqrt(nn + mm);
            if (dis + ve1[i] < ans) {
                ans = dis + ve1[i];
            }
        }

        cout << fixed << setprecision(12) << ans << endl;
    }
    rt;
}
