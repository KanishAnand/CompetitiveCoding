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

int ans = -1, n, MAX = 4;
vector<int> final, szz;
vector<vector<int>> store;
map<vector<int>, int> mp;

void fun(int ind, int nuk, vector<int> &elements) {
    if (ind >= n) {
        if (mp[elements]) {
            return;
        }

        if (ans == -1) {
            ans = nuk;
            final = elements;
        }
        if (nuk < ans) {
            ans = nuk;
            final = elements;
        }
        return;
    }

    int last_el = store[ind][0];
    int szzz = szz[ind];
    int end = min(MAX, szzz);
    // int end = szzz;
    for (int i = 0; i < end; i++) {
        elements.push_back(szzz - i);
        fun(ind + 1, nuk + (last_el - store[ind][i]), elements);
        elements.pop_back();
    }
}

void solve() {
    int a;
    cin >> n;
    store.resize(n);

    int no;
    for (int i = 0; i < n; i++) {
        cin >> no;
        szz.pb(no);
        for (int j = 0; j < no; j++) {
            cin >> a;
            store[i].pb(a);
        }
        reverse(store[i].begin(), store[i].end());
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            cin >> a;
            tmp.pb(a);
        }
        mp[tmp] = 1;
    }

    vector<int> tmpp;
    tmpp.clear();
    fun(0, 0, tmpp);

    for (int i = 0; i < n; i++) {
        lli p = store[i][0] - store[i][szz[i] - 1];
        if (ans == -1 || p < ans) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    tmp.pb(1);
                } else {
                    tmp.pb(szz[j]);
                }
            }
            if (mp[tmp] == 0) {
                final = tmp;
            }
        }
    }

    int cnt = 0;
    for (auto el : final) {
        // int szzz = szz[cnt];
        cout << el << " ";
        cnt++;
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}