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

lli l;
string st;
vector<lli> fw, dp, bw;

void query(lli ind, char ch) {
    st[ind] = ch;
    lli prev = bw[ind];

    if (prev != -1) {
        if (st[ind] == '?') {
            dp[ind] = dp[prev] + dp[prev + 1];
        } else if (st[ind] == '0') {
            dp[ind] = dp[prev];
        } else {
            dp[ind] = dp[prev + 1];
        }
    } else {
        if (st[ind] == '?') {
            dp[ind] = 2;
        } else {
            dp[ind] = 1;
        }
    }

    if (ind % 2 == 1) {
        ind--;
    }

    while (1) {
        if (ind == l) {
            break;
        }

        lli new_ind = fw[ind];
        // cout << ind << " a " << new_ind << " " << l << endl;

        if (st[new_ind] == '?') {
            dp[new_ind] = dp[ind] + dp[ind + 1];
        } else if (st[new_ind] == '0') {
            dp[new_ind] = dp[ind];
        } else {
            dp[new_ind] = dp[ind + 1];
        }

        ind = new_ind;
        if (ind == l) {
            break;
        }
    }
}

void solve() {
    lli k;
    cin >> k;
    cin >> st;

    fw.resize(pow(2, k) + 3, -1);
    bw.resize(pow(2, k) + 3, -1);
    dp.resize(pow(2, k) + 3, 0);

    lli tmp = k - 1, cnt = 0;
    while (tmp >= 1) {
        lli p = pow(2, tmp);
        lli j = 0;
        for (lli i = 0; i < p; i += 2) {
            // cout << cnt + i << " " << j + cnt + p << endl;
            fw[cnt + i] = j + cnt + p;
            fw[cnt + i + 1] = j + cnt + p;
            bw[j + cnt + p] = cnt + i;
            j++;
        }
        cnt += p;
        tmp--;
    }

    // for (lli i = 0; i < pow(2, k); i++) {
    //     cout << i << " " << fw[i] << " " << bw[i] << endl;
    // }

    for (lli i = 0; i < pow(2, k - 1); i++) {
        if (st[i] == '?') {
            dp[i] = 2;
        } else {
            dp[i] = 1;
        }
    }

    l = len(st) - 1;
    for (lli i = 0; i < l - 1; i += 2) {
        lli ind = fw[i];
        if (st[ind] == '?') {
            dp[ind] = dp[i] + dp[i + 1];
        } else if (st[ind] == '0') {
            dp[ind] = dp[i];
        } else {
            dp[ind] = dp[i + 1];
        }
    }

    lli q, ind;
    cin >> q;
    char ch;
    while (q--) {
        cin >> ind >> ch;
        ind--;
        query(ind, ch);
        cout << dp[l] << endln;
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