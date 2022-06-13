#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define rt return 0
#define endln "\n"

static const int MOD = 998244353;
static const int root = 565042129;
static const int root_1 = 950391366;
static const int root_pw = 1 << 20;
vector<int> v, res;

int power(int x, int y) {
    // log y complexity
    // return (x^y) % MOD
    int ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans = (int)((1LL * ans * x) % MOD);
        }
        y = y >> 1;
        x = (int)((1LL * x * x) % MOD);
    }
    return ans;
}

void fft(vector<int>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (int)(1LL * w * wlen % MOD);
            }
        }
    }

    if (invert) {
        int n_1 = power(n, MOD - 2);
        for (int& x : a)
            x = (int)(1LL * x * n_1 % MOD);
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) {
        fa[i] = (int)((1LL * fa[i] * fb[i]) % MOD);
    }
    fft(fa, true);

    return fa;
}

void solve() {
    int n, a, q, b;
    cin >> n >> q;
    vector<pair<int, int>> store;

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        store.pb({a, b});
    }

    v.pb(1);
    for (int i = 1; i <= n; i++) {
        v.pb(0);
    }

    for (int i = 0; i < q; i++) {
        a = store[i].first;
        b = store[i].second;

        vector<int> v1;
        v1.pb(1);
        for (int j = 1; j <= n; j++) {
            if (j % a == 0 && (j / a) <= b) {
                v1.pb(1);
            } else {
                v1.pb(0);
            }
        }

        res = multiply(v, v1);
        vector<int> tmp;
        for (int i = 0; i <= n; i++) {
            tmp.pb(res[i]);
        }
        v = tmp;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}