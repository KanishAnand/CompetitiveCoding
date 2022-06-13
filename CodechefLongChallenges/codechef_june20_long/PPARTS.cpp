#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
typedef long long int ll;
#define intu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define aint(x) x.begin(), x.end()
#define sz(x) (inti)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, nuint_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, nuint_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element
// (0-based)

const int G = 3;
const int MOD = 998244353;
const int N = 5e6 + 10;

int rev[N], w[N], inv_n, inv[N];

int bigMod(int a, int e) {
    if (e == -1)
        e = MOD - 2;
    int ret = 1;
    while (e) {
        if (e & 1)
            ret = (ll)ret * a % MOD;
        a = (ll)a * a % MOD;
        e >>= 1;
    }
    return ret;
}

void prepare(int n) {
    int sz = abs(31 - __builtin_clz(n));
    int r = bigMod(G, (MOD - 1) / n);
    inv_n = inv[n], w[0] = w[n] = 1;
    for (int i = 1; i < n; ++i)
        w[i] = (ll)w[i - 1] * r % MOD;
    for (int i = 1; i < n; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
}

int f[N], g[N], h[N];

void ntt(int *a, int n, int dir = 0) {
    for (int i = 1; i < n - 1; ++i) {
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    }
    for (int m = 2; m <= n; m <<= 1) {
        for (int i = 0; i < n; i += m) {
            for (int j = 0; j < (m >> 1); ++j) {
                int &u = a[i + j], &v = a[i + j + (m >> 1)];
                int t = (ll)v * w[dir ? n - n / m * j : n / m * j] % MOD;
                v = u - t < 0 ? u - t + MOD : u - t;
                u = u + t >= MOD ? u + t - MOD : u + t;
            }
        }
    }
    if (dir)
        for (int i = 0; i < n; ++i)
            a[i] = (ll)a[i] * inv_n % MOD;
}

void multiply(int *a, int *b, int n) {
    prepare(n << 1), ntt(a, n << 1), ntt(b, n << 1);
    for (int i = 0; i < n << 1; ++i)
        a[i] = (ll)a[i] * b[i] % MOD;
    ntt(a, n << 1, 1);
    for (int i = n; i < n << 1; ++i)
        a[i] = 0;
}

void inverse(int *a, int n, int *b) {
    b[0] = inv[a[0]], b[1] = 0;
    for (int m = 2; m <= n; m <<= 1) {
        for (int i = 0; i < m; ++i)
            f[i] = a[i], f[i + m] = b[i + m] = 0;
        prepare(m << 1), ntt(f, m << 1), ntt(b, m << 1);
        for (int i = 0; i < m << 1; ++i)
            b[i] = (ll)b[i] * (MOD + 2 - (ll)b[i] * f[i] % MOD) % MOD;
        ntt(b, m << 1, 1);
        for (int i = m; i < m << 1; ++i)
            b[i] = 0;
    }
}

void log(int *a, int n) {
    inverse(a, n, g);
    for (int i = 0; i + 1 < n; ++i)
        a[i] = (i + 1ll) * a[i + 1] % MOD;
    multiply(a, g, n);
    for (int i = n - 1; i; --i)
        a[i] = (ll)a[i - 1] * inv[i] % MOD;
    a[0] = 0;
}

void exp(int *a, int n, int *b) {
    b[0] = 1, b[1] = 0;
    for (int m = 2; m <= n; m <<= 1) {
        for (int i = 0; i < m; ++i)
            h[i] = b[i];
        log(h, m);
        for (int i = 0; i < m; ++i)
            h[i] = (a[i] - h[i] + MOD) % MOD;
        ++h[0], h[0] %= MOD;
        for (int i = m; i < m << 1; ++i)
            b[i] = h[i] = 0;
        multiply(b, h, m);
        for (int i = m; i < m << 1; ++i)
            b[i] = 0;
    }
}

int n, m, q, cofirst[N] = {0}, polynomial[N] = {0}, co_other[N] = {0},
             polynomial2[N] = {0}, final_poly[N] = {0};

void solve() {
    for (int i = 1; i < N; ++i) {
        inv[i] = bigMod(i, -1);
    }

    cin >> n >> q;

    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;

        b = min(n / a, b);

        ll p = 1ll * a * (b + 1);
        if (p <= n)
            cofirst[p]++;

        co_other[a]++;
    }

    m = 1 << int(ceil(log2(n)) + 1);
    if (m / 2 > n)
        m >>= 1;

    for (int i = 1; i < m; ++i) {
        for (int j = i, k = 1; j < m; j += i, ++k) {
            polynomial[j] =
                (0ll + polynomial[j] + 1ll * cofirst[i] * inv[k] % MOD) % MOD;
            polynomial2[j] =
                (0ll + polynomial2[j] + 1ll * co_other[i] * inv[k] % MOD) % MOD;
        }
    }

    for (int i = 0; i < m; i++) {
        polynomial[i] = (0ll + -polynomial[i] + polynomial2[i] + MOD) % MOD;
    }

    exp(polynomial, m, final_poly);

    for (int i = 1; i <= n; ++i)
        printf("%d ", final_poly[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}
