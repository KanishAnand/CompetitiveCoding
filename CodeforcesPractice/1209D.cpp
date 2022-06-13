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
    lli n, a, k, b, ans = 0;
    cin >> n >> k;
    vector<lli> vis(k + 2, 0), eaten(n + 2, 0);

    vector<vector<lli>> store(n + 2), person(k + 2);

    for (lli i = 0; i < k; i++) {
        cin >> a >> b;
        person[i + 1].pb(a);
        person[i + 1].pb(b);
        store[a].pb(i + 1);
        store[b].pb(i + 1);
    }

    queue<lli> qu;

    for (lli p = 1; p <= k; p++) {
        if (vis[p] == 1) {
            continue;
        }
        vis[p] = 1;
        eaten[person[p][0]] = 1;
        eaten[person[p][1]] = 1;
        qu.push(person[p][1]);
        qu.push(person[p][0]);

        while (!qu.empty()) {
            a = qu.front();
            qu.pop();
            for (lli i = 0; i < sz(store[a]); i++) {
                lli val = store[a][i];
                if (vis[val] == 1) {
                    continue;
                }
                vis[val] = 1;
                lli snack1 = person[val][0], snack2 = person[val][1];
                if (eaten[snack1] == 1 && eaten[snack2] == 1) {
                    ans++;
                    continue;
                } else if (eaten[snack1] == 0) {
                    eaten[snack1] = 1;
                    qu.push(snack1);
                } else {
                    eaten[snack2] = 1;
                    qu.push(snack2);
                }
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