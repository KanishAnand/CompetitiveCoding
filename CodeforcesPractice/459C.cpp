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

vector<vector<lli>> store;
lli n, k, d, flag = 0;

void fun(vector<lli> st) {
    if (sz(st) == d) {
        store.pb(st);
        if (store.size() == n) {
            flag = 1;
        }
        return;
    }
    for (lli i = 1; i <= k; i++) {
        st.pb(i);
        fun(st);
        st.pop_back();
        if (flag == 1) {
            return;
        }
    }
}

void solve() {
    cin >> n >> k >> d;
    vector<lli> tmp;
    fun(tmp);
    if (store.size() < n) {
        cout << "-1" << endl;
        return;
    }

    for (lli i = 0; i < d; i++) {
        for (lli j = 0; j < n; j++) {
            cout << store[j][i] << " ";
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