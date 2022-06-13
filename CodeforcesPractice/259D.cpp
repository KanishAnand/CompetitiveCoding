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

vector<lli> no;
vector<vector<vector<lli>>> dp(12, vector<vector<lli>>(12, vector<lli>(2, 0)));

// less means current number built is surely less than upper limit or not
void fun() {
    // BASE CASE
    lli indd = sz(no) - 1;
    dp[indd][0][1] = 8;
    dp[indd][1][1] = 2;

    for (lli i = 0; i <= no[indd]; i++) {
        lli req = 0;
        if (i == 4 || i == 7) {
            req = 1;
        }
        dp[indd][req][0]++;
    }

    for (lli ind = sz(no) - 2; ind >= 0; ind--) {
        for (lli req = 0; req <= 9; req++) {
            for (lli less = 0; less <= 1; less++) {
                lli higher;
                if (less == 0) {
                    higher = no[ind];
                } else {
                    higher = 9;
                }
                for (lli x = 0; x <= higher; x++) {
                    lli new_req = req;
                    if (x == 4 || x == 7) {
                        new_req--;
                    }
                    lli ch = (x < no[ind]);
                    lli new_less = (less | ch);
                    if (new_req >= 0) {
                        dp[ind][req][less] += dp[ind + 1][new_req][new_less];
                        dp[ind][req][less] %= MOD;
                    }
                }
            }
        }
    }
}

void solve() {
    lli m;
    cin >> m;
    lli tmp = m;
    while (tmp > 0) {
        no.pb(tmp % 10);
        tmp /= 10;
    }

    reverse(all(no));

    // calculate dp
    fun();

    map<lli, lli> mp;
    lli tot = 0;

    // to subtract case of 0
    dp[0][0][0]--;
    for (lli i = 1; i <= 9; i++) {
        mp[i] = dp[0][i][0];
        tot += dp[0][i][0];
    }

    mp[0] = m - tot;

    lli ans = 0;
    for (lli i = 1; i <= 9; i++) {
        vector<lli> tmp;
        tmp.pb(mp[i]);
        mp[i]--;
        for (lli a = 0; a <= 9; a++) {
            tmp.pb(mp[a]);
            mp[a]--;
            for (lli b = 0; b < i; b++) {
                tmp.pb(mp[b]);
                mp[b]--;
                for (lli c = 0; c < i; c++) {
                    tmp.pb(mp[c]);
                    mp[c]--;
                    for (lli d = 0; d < i; d++) {
                        tmp.pb(mp[d]);
                        mp[d]--;
                        for (lli e = 0; e < i; e++) {
                            tmp.pb(mp[e]);
                            mp[e]--;
                            for (lli f = 0; f < i; f++) {
                                tmp.pb(mp[f]);
                                mp[f]--;
                                lli calc = a + b + c + d + e + f;
                                if (i > calc) {
                                    lli no = 1;
                                    for (lli j = 0; j < sz(tmp); j++) {
                                        no *= tmp[j];
                                        no %= MOD;
                                    }
                                    ans += no;
                                    ans %= MOD;
                                }
                                tmp.pop_back();
                                mp[f]++;
                            }
                            tmp.pop_back();
                            mp[e]++;
                        }
                        tmp.pop_back();
                        mp[d]++;
                    }
                    tmp.pop_back();
                    mp[c]++;
                }
                tmp.pop_back();
                mp[b]++;
            }
            tmp.pop_back();
            mp[a]++;
        }
        tmp.pop_back();
        mp[i]++;
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}