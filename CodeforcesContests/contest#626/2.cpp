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

lli cal(vector<lli> dim1, vector<lli> dim2, lli val1, lli val2,
        vector<lli> suff1, vector<lli> suff2) {
    auto it = lower_bound(dim1.begin(), dim1.end(), val1);
    if (it == dim1.end()) {
        return 0;
    }
    lli ind1 = it - dim1.begin();

    auto it2 = lower_bound(dim2.begin(), dim2.end(), val2);
    if (it2 == dim2.end()) {
        return 0;
    }
    lli ind2 = it2 - dim2.begin();
    lli v1 = suff1[ind1], v2 = suff2[ind2];
    lli no1 = sz(dim1) - ind1;
    lli no2 = sz(dim2) - ind2;
    v1 = v1 - no1 * (val1 - 1);
    v2 = v2 - no2 * (val2 - 1);
    return v1 * v2;
}

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<lli> v1, v2;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v1.pb(a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        v2.pb(a);
    }

    lli cnt = 0;
    vector<lli> dim1, dim2;

    for (lli i = 0; i < n; i++) {
        if (v1[i] == 1) {
            cnt++;
        } else {
            if (cnt != 0) {
                dim1.pb(cnt);
            }
            cnt = 0;
        }
    }
    if (cnt != 0) {
        dim1.pb(cnt);
    }

    cnt = 0;
    for (lli i = 0; i < m; i++) {
        if (v2[i] == 1) {
            cnt++;
        } else {
            if (cnt != 0) {
                dim2.pb(cnt);
            }
            cnt = 0;
        }
    }
    if (cnt != 0) {
        dim2.pb(cnt);
    }

    if (sz(dim1) == 0 || sz(dim2) == 0) {
        cout << "0" << endl;
        return;
    }

    sort(all(dim1));
    sort(all(dim2));
    vector<lli> suff1(n + 2, 0), suff2(m + 2, 0);

    suff1[sz(dim1) - 1] = dim1[sz(dim1) - 1];
    for (lli i = sz(dim1) - 2; i >= 0; i--) {
        suff1[i] = suff1[i + 1] + dim1[i];
    }

    suff2[sz(dim2) - 1] = dim2[sz(dim2) - 1];
    for (lli i = sz(dim2) - 2; i >= 0; i--) {
        suff2[i] = suff2[i + 1] + dim2[i];
    }

    lli ans = 0;

    for (lli i = 1; i <= sqrt(k); i++) {
        if (k % i == 0) {
            lli val1 = i;
            lli val2 = k / i;
            ans += cal(dim1, dim2, val1, val2, suff1, suff2);
            if (val1 != val2) {
                ans += cal(dim1, dim2, val2, val1, suff1, suff2);
            }
        }
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