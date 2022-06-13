#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())

lli P;
vector<lli> sum_a, sum_c, vector_c, vector_a, cnt;
vector<vector<lli>> adj;

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % P;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= P;
        }
        y = y >> 1;
        x = (x * x) % P;
    }
    return ans;
}

struct Solution {
    lli root1, root2;
    bool exists;
};

struct Solution makeSolution(lli root1, lli root2, bool exists) {
    struct Solution sol;
    sol.root1 = root1;
    sol.root2 = root2;
    sol.exists = exists;
    return sol;
}

struct Solution ts(lli n) {
    lli q = P - 1;
    lli ss = 0;
    lli z = 2;
    lli c, r, t, m;

    if (power(n, (P - 1) / 2) != 1) {
        return makeSolution(0, 0, false);
    }

    while ((q & 1) == 0) {
        ss += 1;
        q >>= 1;
    }

    if (ss == 1) {
        lli r1 = power(n, (P + 1) / 4);
        return makeSolution(r1, P - r1, true);
    }

    while (power(z, (P - 1) / 2) != P - 1) {
        z++;
    }

    c = power(z, q);
    r = power(n, (q + 1) / 2);
    t = power(n, q);
    m = ss;

    while (true) {
        lli i = 0, zz = t;
        lli b = c, e;
        if (t == 1) {
            return makeSolution(r, P - r, true);
        }
        while (zz != 1 && i < (m - 1)) {
            zz = zz * zz % P;
            i++;
        }
        e = m - i - 1;
        while (e > 0) {
            b = b * b % P;
            e--;
        }
        r = r * b % P;
        c = b * b % P;
        t = t * c % P;
        m = i;
    }
}

void dfs(lli a) {
    for (auto val : adj[a]) {
        dfs(val);
        sum_c[a] += sum_c[val];
        sum_a[a] += sum_a[val];
        sum_c[a] %= P;
        sum_a[a] %= P;
    }

    lli b = (2 * sum_a[a]) % P;
    lli c = (sum_a[a] * sum_a[a]) % P - sum_c[a] + P;
    c %= P;

    c -= vector_c[a];
    c += P;
    c %= P;

    // (2ax + b)^2 ≡ b2−4ac (mod P)
    lli val = (b * b) % P - (4 * c) % P;
    val += P;
    val %= P;

    lli res1, res2, res;

    struct Solution sol = ts(val);

    // if (val == 0) {
    //     res1 = 0;
    //     res2 = 0;
    // }

    // cout << " a " << a << " P " << P << " b " << b << " c " << c << " val " << val << " res " << res << endl;
    if (val != 0 && sol.exists == false) {
        // cout << a << endl;
        res = 0;
        cnt[a] = 0;
    } else {
        res1 = sol.root1;
        res2 = sol.root2;
        if (val == 0) {
            res1 = 0;
            res2 = 0;
        }
        // cout << a << " " << res1 << " " << res2 << endl;

        res1 = (res1 - b + 2 * P) % P;
        res1 *= power(2, P - 2);
        res1 %= P;

        res2 = (res2 - b + 2 * P) % P;
        res2 *= power(2, P - 2);
        res2 %= P;

        res = res1;
        if (res1 == res2) {
            cnt[a] = 1;
        } else {
            cnt[a] = 2;
        }
    }

    vector_a[a] = res;

    // add value of parent
    sum_a[a] += vector_a[a];
    sum_c[a] += vector_c[a];
    sum_c[a] %= P;
    sum_a[a] %= P;
}

void solve() {
    adj.clear();
    cnt.clear();
    vector_c.clear();
    vector_a.clear();
    sum_a.clear();
    sum_c.clear();

    lli a, n;
    cin >> n >> P;

    adj.resize(n + 2);
    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
    }

    vector_c.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        vector_c.pb(a);
    }

    sum_a.resize(n + 2, 0);
    sum_c.resize(n + 2, 0);
    vector_a.resize(n + 2, 0);
    cnt.resize(n + 2, 0);

    dfs(1);

    lli ans = 1, flag = 1;
    lli m = 998244353;

    for (lli i = 1; i <= n; i++) {
        // cout << cnt[i] << " ";
        if (cnt[i] == 0) {
            flag = 0;
        }
        ans *= cnt[i];
        ans %= m;
    }
    // cout << endl;

    cout << ans << endl;
    if (flag == 0) {
        cout << "-1" << endl;
    } else {
        for (lli i = 1; i <= n; i++) {
            cout << vector_a[i] << " ";
        }
        cout << endl;
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