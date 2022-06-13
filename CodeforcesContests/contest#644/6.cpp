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

void solve() {
    lli n, a, m;
    cin >> n >> m;
    string st;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        reverse(all(st));
        lli val = 0, p = 1;
        for (lli j = 0; j < m; j++) {
            val += (st[j] - '0') * p;
            p *= 2;
        }
        v.pb(val);
    }

    sort(all(v));
    lli pp = pow(2, m);
    lli ind = pp - n;
    ind = (ind - 1) / 2;
    lli vv = pow(2, m);
    vv--;
    lli beg = 0, end = vv;
    lli ans;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli val = mid;
        auto it = lower_bound(v.begin(), v.end(), val);
        lli no = it - v.begin();
        // if (it != v.end() && *it == val) {
        //     val--;
        // }
        val -= no;
        if (val < ind) {
            beg = mid + 1;
        } else if (val > ind) {
            end = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }

    set<lli> stt;
    for (lli i = 0; i < v.size(); i++) {
        stt.insert(v[i]);
    }

    while (stt.find(ans) != stt.end()) {
        ans++;
    }

    vector<lli> an;
    while (ans > 0) {
        lli rem = ans % 2;
        an.pb(rem);
        ans /= 2;
    }

    while (an.size() < m) {
        an.pb(0);
    }

    reverse(all(an));

    for (lli i = 0; i < an.size(); i++) {
        cout << an[i];
    }
    cout << endl;
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