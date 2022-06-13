#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const long long int MOD = 1e9 + 7, sixinverse = 166666668;
set<lli> st;
vector<lli> vs;

lli sumofsqares(lli a) {
    lli val = (a % MOD * (a + 1) % MOD) % MOD;
    val = (val * (2 * a + 1) % MOD) % MOD;
    return val;
}

void solve() {
    lli n;
    lli ans;
    cin >> n;
    ans = n % MOD;

    for (lli i = 0; i < vs.size(); i++) {
        lli vv = vs[i];
        lli val = n / vv;
        if (val == 0) {
            break;
        }

        lli tmp = (val * vv) % MOD;
        ans += tmp;
        ans %= MOD;
    }

    if (n <= 1e12) {
        cout << ans << '\n';
        return;
    }

    lli oo = 1e6 + 1;
    oo *= oo;
    lli lim = n / oo;

    for (lli i = 1; i <= lim; i++) {
        lli val1 = n / (i + 1);
        lli val2 = n / i;

        lli start = sqrt(val1);
        if (start * start > val1) {
            start--;
        }

        start++;
        lli finish = sqrt(val2);
        if (finish * finish > val2) {
            finish--;
        }

        if (start <= 1e6) {
            start = 1e6 + 1;
        }

        if (start > finish) {
            continue;
        }

        lli fval = sumofsqares(finish);
        lli sval = sumofsqares(start - 1);

        lli p = (fval - sval + 2 * MOD) % MOD;
        p = (p * sixinverse) % MOD;

        lli tmp = (p * i) % MOD;
        ans += tmp;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli n = 1e18, val;

    for (lli i = 2; i <= 1e6; i++) {
        val = i;
        val *= val;

        while (val <= n) {
            if (val > 1e12) {
                lli q = sqrt(val);
                if (q * q != val) {
                    st.insert(val);
                }
            } else {
                st.insert(val);
            }

            if (n / val < i) {
                break;
            }
            val *= i;
        }
    }

    for (auto it = st.begin(); it != st.end(); it++) {
        vs.push_back(*it);
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}