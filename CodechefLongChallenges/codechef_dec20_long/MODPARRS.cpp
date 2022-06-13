#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli P = 239;
const lli MOD = 998244353;

vector<vector<lli>> dp;

vector<lli> fac(245, 1), invfac(245, 1);

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

lli nCr(lli n, lli r) {
    if (r > n) {
        return 0;
    }
    lli ans = fac[n];
    lli val = (invfac[n - r] * invfac[r]) % MOD;
    ans *= val;
    ans %= MOD;
    return ans;
}

lli inverseMod(lli a) {
    return power(a, MOD - 2);
}

lli fun(lli n) {
    lli ans = nCr(P, n);
    ans %= MOD;
    ans *= fac[n];
    ans %= MOD;
    ans *= inverseMod(P);
    ans %= MOD;
    return ans;
}

void solve() {
    for (lli i = 1; i <= 240; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        invfac[i] = inverseMod(fac[i]);
    }

    lli n, a;
    cin >> n;
    vector<lli> v;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    dp.resize(pow(2, n), vector<lli>(2, 0));

    for (lli mask = 1; mask < pow(2, n); mask++) {
        lli tmp = mask, sum = 0, ind = 0;
        vector<lli> one;
        while (tmp > 0) {
            if (tmp % 2 == 1) {
                sum += v[ind];
                one.pb(ind);
                sum %= P;
            }
            tmp /= 2;
            ind++;
        }

        //base case
        if (sz(one) == 1) {
            if (v[one[0]] != 0) {
                dp[mask][0] = 1;
                dp[mask][1] = 0;
            } else {
                dp[mask][0] = 239;
                dp[mask][1] = 238;
            }
            continue;
        }

        // for dp[mask][0]
        if (sum == 0) {
            lli tmp_no = pow(2, one[0]);
            lli new_mask = (mask ^ tmp_no);
            dp[mask][0] = (dp[new_mask][1] * 239) % MOD;
        } else {
            dp[mask][0] = fun(sz(one));
        }

        // for dp[mask][1]
        lli val = 0;
        for (auto pos : one) {
            lli tmp_no = pow(2, pos);
            lli new_mask = (mask ^ tmp_no);
            val += dp[new_mask][1];
            val %= MOD;
        }
        val = dp[mask][0] - val;
        val += MOD;
        val %= MOD;
        dp[mask][1] = val;
    }

    lli all_one = (pow(2, n) - 1);
    lli ans = dp[all_one][0];

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}