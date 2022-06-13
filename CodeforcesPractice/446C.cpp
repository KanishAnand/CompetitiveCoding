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
const lli MOD = 1e9 + 9;

vector<lli> seg, v, lazy;
vector<lli> fib, prefib;

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = v[l];
        return;
    }
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = (seg[2 * pos] + seg[2 * pos + 1]) % MOD;
    seg[pos] %= MOD;
    return;
}

void push(lli pos, lli l, lli r) {
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos] %= MOD;
    lazy[2 * pos + 1] += lazy[pos];
    lazy[2 * pos + 1] %= MOD;

    lli mid = (l + r) / 2;
    seg[2 * pos] += (lazy[pos] * (prefib[mid])) % MOD;
    seg[2 * pos] %= MOD;
    seg[2 * pos + 1] +=
        (lazy[pos] * (prefib[r] - prefib[mid] + MOD) % MOD) % MOD;
    seg[2 * pos + 1] %= MOD;
    lazy[pos] = 0;
    return;
}

void update(lli pos, lli beg, lli end, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        seg[pos] += prefib[r + 1];
        seg[pos] %= MOD;
        lazy[pos]++;
        return;
    }

    update(2 * pos, beg, end, l, mid);
    update(2 * pos + 1, beg, end, mid + 1, r);
    seg[pos] = (seg[2 * pos] + seg[2 * pos + 1]) % MOD;
    seg[pos] %= MOD;
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 1e17;
    }

    if (l != r) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    return (query(2 * pos, beg, end, l, mid) +
            query(2 * pos + 1, beg, end, mid + 1, r)) %
           MOD;
}

void solve() {
    lli n, a, m, l, r, val;
    cin >> n >> m;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    seg.resize(4 * n + 2, 0);
    lazy.resize(4 * n + 2, 0);

    build(1, 0, n - 1);
    fib.resize(n + 2, 1);
    prefib.resize(n + 2, 0);

    for (lli i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    prefib[1] = 1;
    for (lli i = 2; i <= n; i++) {
        prefib[i] = (prefib[i - 1] + fib[i]) % MOD;
    }

    while (m--) {
        cin >> a >> l >> r;
        l--;
        r--;
        if (a == 1) {
            update(1, l, r, 0, n - 1)
        } else {
            cout << query(1, l, r, 0, n - 1) << endl;
        }
    }
}

int main(void) {
    solve();
    rt;
}