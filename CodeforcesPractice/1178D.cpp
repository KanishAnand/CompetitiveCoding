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
    vector<pair<lli, lli>> edges;

    vector<lli> isprime(3001, 1);

    for (lli i = 2; i <= sqrt(3000); i++) {
        if (isprime[i] == 0) {
            continue;
        }
        for (lli j = i * i; j <= 3000; j += i) {
            isprime[j] = 0;
        }
    }

    lli no, val = n;

    while (1) {
        if (isprime[val] == 1) {
            no = val;
            break;
        }
        val++;
    }

    for (lli i = 1; i < n; i++) {
        edges.pb({i, i + 1});
    }

    edges.pb({n, 1});
    lli rem = no - n, beg = 1, end = n / 2 + 1;

    while (rem > 0) {
        edges.pb({beg, end});
        beg++, end++;
        rem--;
    }

    cout << edges.size() << endl;
    for (lli i = 0; i < edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
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