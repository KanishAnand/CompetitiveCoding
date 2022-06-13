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

void solve(vector<int> &mp) {
    int n;
    cin >> n;
    cout << mp[n] << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int mx = 1e7;
    int cnt = 0;
    vector<int> store(mx + 1, 0);
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            if (store[j] > mx - i) {
                store[j] = 1e7 + 1;
                continue;
            }
            store[j] += i;
        }
    }

    vector<int> mp(mx + 1, -1);
    for (int i = 1; i <= mx; i++) {
        if (store[i] > mx) {
            continue;
        }
        if (mp[store[i]] == -1) {
            mp[store[i]] = i;
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve(mp);
    rt;
}