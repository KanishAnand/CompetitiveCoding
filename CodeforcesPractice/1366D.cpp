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

void solve() {
    vector<lli> prime(1e7 + 2, 0);
    lli p = sqrt(1e7);

    for (lli i = 2; i < p; i++) {
        if (prime[i] != 0) {
            continue;
        }
        for (lli j = i * i; j <= 1e7; j += i) {
            if (prime[j] == 0) {
                prime[j] = i;
            }
        }
    }

    lli n, a;
    cin >> n;
    vector<lli> v1, v2;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        lli val = prime[a];
        if (val == 0) {
            v1.pb(-1);
            v2.pb(-1);
            continue;
        }
        while (a % val == 0) {
            a /= val;
        }
        if (a != 1) {
            v1.pb(val);
            v2.pb(a);
        } else {
            v1.pb(-1);
            v2.pb(-1);
        }
    }

    for (lli i = 0; i < n; i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (lli i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}