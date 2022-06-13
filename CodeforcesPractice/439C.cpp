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
    lli n, a, k, p;
    cin >> n >> k >> p;
    vector<lli> ve, vo;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            ve.pb(a);
        } else {
            vo.pb(a);
        }
    }

    lli flag = 0;
    lli pp = k - p;
    if (sz(vo) < pp) {
        cout << "NO" << endl;
        return;
    }

    if (p == 0) {
        lli val = sz(vo) - k - 1;
        if (val % 2 == 0) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for (lli i = 0; i < k - 1; i++) {
            cout << "1 " << vo[i] << endl;
        }
        vector<lli> tmp;
        for (lli i = k - 1; i < sz(vo); i++) {
            tmp.pb(vo[i]);
        }
        for (lli i = 0; i < sz(ve); i++) {
            tmp.pb(ve[i]);
        }
        cout << tmp.size() << " ";
        for (lli i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << endl;
        return;
    }

    lli val = sz(vo) - pp;
    if (val % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    lli no = val / 2 + ve.size();
    if (no < p || (p == 0 && no != 0)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (lli i = 0; i < pp; i++) {
        cout << "1 " << vo[i] << endl;
    }

    k = p;

    lli beg = 0, beg2 = pp;
    while (k > 1 && beg < sz(ve)) {
        cout << "1 " << ve[beg] << endl;
        beg++;
        k--;
    }

    while (k > 1 && beg2 < sz(vo)) {
        cout << "2 " << vo[beg2] << " " << vo[beg2 + 1] << endl;
        beg2 += 2;
        k--;
    }

    if (k == 1) {
        vector<lli> tmp;
        for (lli i = beg; i < ve.size(); i++) {
            tmp.pb(ve[i]);
        }
        for (lli i = beg2; i < vo.size(); i += 2) {
            tmp.pb(vo[i]);
            tmp.pb(vo[i + 1]);
        }
        cout << tmp.size() << " ";
        for (lli i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << endl;
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