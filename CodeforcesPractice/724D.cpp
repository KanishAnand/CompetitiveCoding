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
    lli n, a, m;
    cin >> m;
    string st;
    cin >> st;
    n = st.length();
    vector<vector<lli>> mx(n + 2, vector<lli>(26, -2));

    for (lli i = 0; i < n; i++) {
        if (i != 0) {
            mx[i] = mx[i - 1];
        }
        mx[i][st[i] - 'a'] = i;
    }

    set<lli> s;
    s.insert(-1);
    s.insert(n);

    lli alph = 0;

    while (alph < 26) {
        auto it = s.begin();
        lli flag = 0;

        while (1) {
            if (*it == n) {
                break;
            }

            auto it2 = it;
            it2++;
            lli val = *it2 - *it;
            val--;

            if (val >= m) {
                lli ind = *it;
                ind += m;
                if (mx[ind][alph] > *it) {
                    s.insert(mx[ind][alph]);
                    lli no = mx[ind][alph];
                    it = s.find(no);
                } else {
                    for (lli i = 0; i < n; i++) {
                        if (st[i] - 'a' == alph) {
                            s.insert(i);
                        }
                    }
                    flag = 1;
                }
            } else {
                it++;
            }

            if (flag == 1) {
                break;
            }
        }

        if (flag == 0) {
            break;
        }
        alph++;
    }

    s.erase(-1);
    s.erase(n);
    vector<lli> ans;
    for (auto it = s.begin(); it != s.end(); it++) {
        lli p = st[*it] - 'a';
        ans.pb(p);
    }

    sort(all(ans));
    for (lli i = 0; i < ans.size(); i++) {
        char ch = (char)(ans[i] + 'a');
        cout << ch;
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