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
// vector<vector<int>> pref(200001, vector<int>(201, 0));
int pref[201][200001];

void solve() {
    int n, a, ans = 0;
    cin >> n;
    vector<int> v;
    int mxval = -1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mxval = max(mxval, a);
        v.pb(a);
    }

    for (int i = 1; i <= 200; i++) {
        for (int j = 0; j < n; j++) {
            pref[i][j] = 0;
        }
    }

    pref[v[0]][0]++;
    ans = max(ans, pref[v[0]][0]);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= mxval; j++) {
            pref[j][i] = pref[j][i - 1];
        }
        pref[v[i]][i]++;
        ans = max(ans, pref[v[i]][i]);
    }

    vector<int> cnt(mxval + 1, 0);

    vector<vector<int>> store_ind(201);

    for (int i = n - 1; i >= 0; i--) {
        cnt[v[i]]++;
        store_ind[v[i]].pb(i);
    }

    for (int i = 0; i < n; i++) {
        int val = pref[v[i]][i];
        if (val > store_ind[v[i]].size()) {
            continue;
        }
        int suff_ind = store_ind[v[i]][val - 1];
        int tmp = 0;
        if (suff_ind != -1 && suff_ind > i) {
            int beg = i + 1, finish = suff_ind - 1;
            if (beg <= finish) {
                for (int j = 1; j <= mxval; j++) {
                    tmp = max(tmp, pref[j][finish] - pref[j][beg - 1]);
                }
            }
            ans = max(ans, val * 2 + tmp);
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    rt;
}