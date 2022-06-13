#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m, b;
    vector<lli> v;
    cin >> n >> m;
    map<lli, map<lli, lli>> mp;
    vector<vector<lli>> parent, child;

    parent.resize(n + 2);
    child.resize(n + 2);
    fr(i, 0, m) {
        lli c;
        cin >> a >> b >> c;
        mp[a][b] = c;
        parent[b].pb(a);
        child[a].pb(b);
    }

    lli ans = m;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 0; j < parent[i].size(); j++) {
            // for (auto j = parent[i].begin(); j != parent[i].end(); j++) {
            for (lli k = 0; k < child[i].size(); k++) {
                // lli flag = 0;
                // for (auto k = child[i].begin(); k != child[i].end(); k++) {
                lli val1 = parent[i][j];
                lli val2 = child[i][k];
                // flag++;
                // cout << val1 << " " << val2 << " " << child[i].size() <<
                // endl;
                lli wt1 = mp[val1][i];
                lli wt2 = mp[i][val2];
                // cout << wt1 << " " << wt2 << endl;
                // if (flag == 2) {
                //     rt;
                // }

                if (wt1 > wt2) {
                    mp[val1][i] -= wt2;
                    // if (mp[val1][i] == 0) {
                    //     parent[i].erase(val1);
                    //     ans--;
                    // }
                    mp[i][val2] -= wt2;
                    if (mp[i][val2] == 0) {
                        // child[i].erase(val2);
                        ans--;
                    }
                    if (mp[val1][val2] == 0 && wt2 != 0) {
                        parent[val2].pb(val1);
                        child[val1].pb(val2);
                        ans++;
                    }
                    mp[val1][val2] += wt2;
                } else {
                    mp[val1][i] -= wt1;
                    if (mp[val1][i] == 0) {
                        // parent[i].erase(val1);
                        ans--;
                    }
                    mp[i][val2] -= wt1;
                    if (mp[i][val2] == 0) {
                        // child[i].erase(val2);
                        ans--;
                    }
                    if (mp[val1][val2] == 0 && wt1 != 0) {
                        parent[val2].pb(val1);
                        child[val1].pb(val2);
                        ans++;
                    }
                    mp[val1][val2] += wt1;
                }
            }
        }
    }

    lli value = 0;

    for (auto it = mp.begin(); it != mp.end(); it++) {
        lli par = (*it).first;
        auto pp = (*it).second;
        for (auto itr = pp.begin(); itr != pp.end(); itr++) {
            lli chld = (*itr).first;
            if (mp[par][chld] != 0) {
                value++;
            }
        }
    }
    cout << value << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        lli par = (*it).first;
        auto pp = (*it).second;
        for (auto itr = pp.begin(); itr != pp.end(); itr++) {
            lli chld = (*itr).first;
            if (mp[par][chld] != 0) {
                cout << par << " " << chld << " " << mp[par][chld] << endl;
            }
        }
    }

    rt;
}
