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
    vector<vector<lli>> divs(2e5 + 2);

    for (lli i = 1; i <= sqrt(2e5); i++) {
        for (lli j = i * i; j <= 2e5; j += i) {
            divs[j].pb(i);
        }
    }

    lli n, a;
    cin >> n;
    vector<lli> v(n, 0);

    for (lli i = 1; i < n; i += 2) {
        cin >> a;
        v[i] = a;
    }

    lli sum = 0;

    for (lli i = 0; i < n; i += 2) {
        lli no = v[i + 1], mn = 1e15;
        for (auto p : divs[no]) {
            lli q = no / p;
            if ((p + q) % 2 == 0) {
                lli t = (abs)(p - q);
                t /= 2;
                if (t * t > sum) {
                    mn = min(mn, t);
                }
            }
        }

        if (mn == 1e15) {
            cout << "No" << endl;
            return;
        }
        v[i] = mn * mn - sum;
        sum += (v[i] + v[i + 1]);
    }

    cout << "Yes" << endl;
    for (lli i = 0; i < n; i++) {
        cout << v[i] << " ";
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