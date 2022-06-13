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
    lli n, a;
    cin >> n;
    if (n == 3) {
        cout << "1" << endl;
        cout << "3" << endl;
        return;
    }

    lli val = n - 2;
    while (1) {
        lli flag = 0;
        for (lli i = 2; i <= sqrt(val); i++) {
            if (val % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            break;
        } else {
            val--;
        }
    }

    if (val == n - 2) {
        cout << "2" << endl;
        cout << "2 " << n - 2 << endl;
        return;
    }

    vector<lli> ans;
    ans.pb(val);
    n -= val;
    vector<lli> prime(n + 2, 1);

    for (lli i = 2; i <= n; i++) {
        if (prime[i] != 0) {
            for (lli j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    set<lli> st;
    for (lli i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            st.insert(i);
        }
    }

    for (auto it = st.begin(); it != st.end(); it++) {
        lli val = n - *it;
        if (st.find(val) != st.end()) {
            ans.pb(val);
            ans.pb(*it);
            break;
        }
    }

    cout << "3" << endl;
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}