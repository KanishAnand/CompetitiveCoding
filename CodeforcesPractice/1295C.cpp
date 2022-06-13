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
    string s, t;
    cin >> s >> t;
    vector<lli> cnts(26, 0), cntt(26, 0), sub(26, 0);

    for (lli i = 0; i < s.length(); i++) {
        cnts[s[i] - 'a']++;
    }

    lli ans = 0, ind = -1;

    for (lli i = 0; i < t.length(); i++) {
        lli chr = t[i] - 'a';
        cntt[chr]++;
        lli flag = 0;

        for (lli j = 0; j < 26; j++) {
            if (cntt[j] - sub[j] > cnts[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            if (i - ind == 1) {
                cout << "-1" << endl;
                return;
            } else {
                cout << i << endl;
                ind = i - 1;
                ans++;
                for (lli j = 0; j < 26; j++) {
                    sub[j] = cntt[j];
                }
                if (i != t.length()) {
                    i--;
                }
                cntt[chr]--;
                sub[chr]--;
            }
        }
    }
    cout << ans << endl;

    cout << ans + 1 << endl;
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