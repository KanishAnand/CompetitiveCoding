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

void solve() {
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    set<lli> st;
    vector<lli> primes_k(1e6 + 5, 0);

    for (lli i = 2; i <= k; i++) {
        lli cnt = 0;
        while (k % i == 0) {
            cnt++;
            k /= i;
        }
        primes_k[i] = cnt;
        if (cnt) {
            st.insert(i);
        }
    }

    vector<lli> primes(1e6 + 2, 0);

    for (auto no : v) {
        for (auto i : st) {
            lli cnt = 0;
            while (no % i == 0) {
                cnt++;
                no /= i;
            }
            primes[i] = max(primes[i], cnt);
        }
    }

    lli flag = 0;
    for (auto i : st) {
        if (primes[i] < primes_k[i]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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