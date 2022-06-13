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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<pair<lli, lli>> store;

    for (lli i = 0; i < n; i++) {
        store.pb({v[i], i});
    }
    for (lli i = 0; i < n; i++) {
        store.pb({v[i], i + n});
    }

    sort(all(store));

    vector<pair<lli, lli>> check;
    for (lli i = 0; i < n; i++) {
        lli val = v[i] / 2;
        if (v[i] % 2 == 0) {
            val--;
        }
        check.pb({val, i});
    }

    sort(all(check));

    vector<lli> ans(n + 2);
    lli beg = 0;

    set<lli> st;

    for (lli i = 0; i < n; i++) {
        lli no = check[i].first;
        lli ind = check[i].second;
        while (beg < sz(store)) {
            if (store[beg].first <= no) {
                st.insert(store[beg].second);
                beg++;
            } else {
                break;
            }
        }

        if (st.empty() == 1) {
            ans[ind] = -1;
        } else {
            auto it = st.upper_bound(ind);
            lli cur = ind;
            lli next = *it;
            lli p = next - cur;
            ans[ind] = p;
        }
    }

    lli val = v[n - 1] / 2;
    if (v[n - 1] % 2 == 0) {
        val--;
    }

    for (lli i = 0; i < 2 * n; i++) {
        if (v[i % n] <= val) {
            ans[n - 1] = i + 1;
            break;
        }
        lli no = v[i % n] / 2;
        if (v[i % n] % 2 == 0) {
            no--;
        }
        val = max(val, no);
    }

    for (lli i = n - 2; i >= 0; i--) {
        if (ans[i] == -1 && ans[i + 1] == -1) {
            continue;
        }
        if (ans[i] == -1) {
            ans[i] = ans[i + 1] + 1;
        } else {
            ans[i] = min(ans[i], ans[i + 1] + 1);
        }
    }

    for (lli i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}