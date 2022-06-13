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

void solve() {
    string st;
    cin >> st;

    lli n = len(st);

    set<lli> tmp_st;
    for (lli i = 0; i < n; i++) {
        tmp_st.insert(st[i] - 'a');
    }

    lli tot = sz(tmp_st);

    vector<vector<string>> v(26, vector<string>(30, "0"));
    string ans = "0";

    for (lli j = 0; j < n; j++) {
        lli ind = st[j] - 'a';
        for (lli cnt = 1; cnt < tot; cnt++) {
            string new_st = "0";
            if (cnt == 1) {
                new_st = st[j];
            } else if (v[ind][cnt - 1] != "0") {
                new_st = v[ind][cnt - 1] + st[j];
            }

            string stt = new_st;
            if (stt != "0") {
                set<lli> cp = tmp_st;
                for (lli i = 0; i < len(stt); i++) {
                    lli no = stt[i] - 'a';
                    if (cp.find(no) != cp.end()) {
                        cp.erase(no);
                    }
                }

                for (auto no : cp) {
                    if (v[no][cnt] == "0") {
                        v[no][cnt] = stt;
                    }
                    v[no][cnt] = max(v[no][cnt], stt);
                }
            }

            if (cnt == tot - 1) {
                if (v[ind][cnt] != "0") {
                    string new_st = v[ind][cnt] + st[j];
                    if (ans == "0") {
                        ans = new_st;
                    }
                    ans = max(ans, new_st);
                }
            }
        }
    }

    // for (lli i = 0; i < 26; i++) {
    //     cout << v[i][tot - 1] << endl;
    // }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}