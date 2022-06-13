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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a;
    cin >> n;

    vector<lli> univ;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        univ.pb(a);
    }

    set<lli> st;
    vector<vector<lli>> store(n + 2);

    lli total = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        total += a;
        lli p = univ[i];
        store[p].pb(a);
        st.insert(p);
    }

    for (auto el : st) {
        sort(all(store[el]));
    }

    vector<vector<lli>> pref(n + 2);
    for (auto el : st) {
        pref[el].resize(store[el].size(), 0);
        for (lli i = 0; i < store[el].size(); i++) {
            if (i != 0) {
                pref[el][i] = pref[el][i - 1];
            }
            pref[el][i] += store[el][i];
        }
    }

    lli sum = 0;
    for (lli i = 1; i <= n; i++) {
        lli ans = total;
        vector<lli> erased;
        for (auto el : st) {
            lli val = store[el].size() % i;
            if (val > 0) {
                ans -= pref[el][val - 1];
            }

            if (store[el].size() == i) {
                total -= pref[el][i - 1];
                erased.pb(el);
            }
        }

        for (auto el : erased) {
            st.erase(el);
        }

        cout << ans << " ";
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