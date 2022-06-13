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
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

stack<lli> topo;
vector<vector<lli>> adj;
vector<lli> vis(27, 0);

lli dfs(lli a) {
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 1) {
            cout << "Impossible" << endl;
            exit(0);
        }
        if (vis[val] == 0) {
            vis[val] = 1;
            topo.push(dfs(val));
        }
    }
    vis[a] = 2;
    return a;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    cin >> n;
    adj.resize(27);
    string str1, str2;
    cin >> str1;
    if (n == 1) {
        fr(i, 0, 26) {
            cout << char('a' + i);
        }
        cout << endl;
        rt;
    }
    fr(i, 0, n - 1) {
        cin >> str2;
        lli len = min(str1.length(), str2.length()), flag = 0;
        fr(i, 0, len) {
            if (str1[i] != str2[i]) {
                adj[str1[i] - 'a'].pb(str2[i] - 'a');
                flag = 1;
                break;
            }
        }
        if (flag == 0 && str1.length() > str2.length()) {
            cout << "Impossible" << endl;
            rt;
        }
        str1 = str2;
    }

    fr(i, 0, 26) {
        if (vis[i] == 0) {
            vis[i] = 1;
            topo.push(dfs(i));
            vis[i] = 2;
        }
    }
    while (!topo.empty()) {
        a = topo.top();
        topo.pop();
        cout << (char)(a + 'a');
    }
    cout << endl;
    rt;
}
