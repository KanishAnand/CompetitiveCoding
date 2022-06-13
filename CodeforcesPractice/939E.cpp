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
vector<double> st;
vector<double> pref;

double calc() {
    lli beg = 0, end = sz(st) - 2;
    double mx = st[sz(st) - 1];
    double ans = 0;

    while ((end - beg) >= 2) {
        lli mid = (beg + end) / 2;
        // cout << beg << " " << end << endl;
        // cout << mid << endl;
        double val1 = st[sz(st) - 1] - (pref[mid - 1] + mx) / (mid + 1);
        double val2 = st[sz(st) - 1] - (pref[mid] + mx) / (mid + 2);
        double val3 = st[sz(st) - 1] - (pref[mid + 1] + mx) / (mid + 3);

        if (val1 <= val2 && val2 <= val3) {
            beg = mid + 1;
        } else if (val1 >= val2 && val2 >= val3) {
            end = mid - 1;
        } else {
            ans = val2;
            break;
        }
    }

    for (lli i = beg; i <= end; i++) {
        double qq = (pref[i] + mx) / (i + 2);
        double val = mx - qq;
        ans = max(ans, val);
    }

    return ans;
}

void solve() {
    lli n, a, q;
    double x;
    cin >> q;

    while (q--) {
        cin >> a;

        if (a == 1) {
            cin >> x;
            if (pref.size() == 0) {
                pref.pb(x);
            } else {
                double val = x + pref[sz(pref) - 1];
                pref.pb(val);
            }
            st.pb(x);
        } else {
            double ans = calc();
            cout << fixed << setprecision(7) << ans << endln;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}