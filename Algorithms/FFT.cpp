#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

const double PI = acos(-1);
#define cd complex<double>

lli reverse(lli num, lli lg_n) {
    lli res = 0;
    for (lli i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd>& a, bool invert) {
    lli n = a.size();
    lli lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (lli i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (lli len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (lli i = 0; i < n; i += len) {
            cd w(1);
            for (lli j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

vector<lli> multiply(vector<lli> const& a, vector<lli> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    lli n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (lli i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector<lli> result(n);
    for (lli i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    lli n, a, q, b;
    cin >> n >> q;
    vector<pair<lli, lli>> store;

    for (lli i = 0; i < q; i++) {
        cin >> a >> b;
        store.pb({a, b});
    }

    vector<lli> v, res;

    v.pb(1);
    for (lli i = 1; i <= n; i++) {
        v.pb(0);
    }

    for (lli i = 0; i < q; i++) {
        a = store[i].first;
        b = store[i].second;

        vector<lli> v1;
        v1.pb(1);
        for (lli j = 1; j <= n; j++) {
            if (j % a == 0 && (j / a) <= b) {
                v1.pb(1);
            } else {
                v1.pb(0);
            }
        }

        res = multiply(v, v1);
        vector<lli> tmp;
        for (lli i = 0; i <= n; i++) {
            tmp.pb(res[i]);
        }
        v = tmp;
    }

    for (lli i = 1; i <= n; i++) {
        cout << v[i] << " ";
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