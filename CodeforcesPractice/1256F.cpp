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
const double PI = 3.14159265358979323846264338;
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
    lli n, a, b;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    vector<lli> v1(26, 0), v2(26, 0);

    for (lli i = 0; i < n; i++) {
        v1[s[i] - 'a']++;
        v2[t[i] - 'a']++;
    }

    lli flag = 0, no = 0;

    for (lli i = 0; i < 26; i++) {
        if (v1[i] != v2[i]) {
            flag = 1;
            break;
        }
        if (v1[i] > 1) {
            no = 1;
        }
    }

    if (flag == 1) {
        cout << "NO" << endl;
        return;
    }
    if (no == 1) {
        cout << "YES" << endl;
        return;
    }

    // checking for number of inversions
    lli cnt1 = 0, cnt2 = 0;
    for (lli i = 0; i < n; i++) {
        a = s[i] - 'a';
        b = t[i] - 'a';
        for (lli j = 0; j < i; j++) {
            lli c = s[j] - 'a';
            lli d = t[j] - 'a';
            if (c > a) {
                cnt1++;
            }
            if (d > b) {
                cnt2++;
            }
        }
    }

    if (cnt1 % 2 == cnt2 % 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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