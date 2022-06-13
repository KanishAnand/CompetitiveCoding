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

int seg[4000005], v[1000005], o, ans;

void build(int pos, int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        seg[pos] = v[l];
    } else {
        build(2 * pos, l, mid);
        build(2 * pos + 1, mid + 1, r);
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}

int update(int pos, int in, int val, int l, int r) {
    int mid = (l + r) / 2;
    if ((l == r) && (l == in)) {
        o = val - v[in];
        v[in] = val;
        seg[pos] = val;
        return o;
    }
    if (l > in || r < in) {
        return 0;
    }
    if (in <= mid) {
        seg[pos] += update(2 * pos, in, val, l, mid);
    } else {
        seg[pos] += update(2 * pos + 1, in, val, mid + 1, r);
    }
    return o;
}

void query(int pos, int val, int l, int r) {
    if (l == r) {
        ans = min(ans, l);
        return;
    } else {
        int mid = (l + r) / 2;
        if (seg[2 * pos] >= val) {
            query(2 * pos, val, l, mid);
        } else {
            query(2 * pos + 1, val - seg[2 * pos], mid + 1, r);
        }
    }
}

void solve() {
    int n, a, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v[a]++;
    }

    build(1, 0, n);

    for (int i = 0; i < q; i++) {
        cin >> a;
        if (a > 0) {
            update(1, a, v[a] + 1, 0, n);
        } else {
            a = -a;
            int beg = 1, end = n;
            ans = n + 1;
            query(1, a, 0, n);
            update(1, ans, v[ans] - 1, 0, n);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] != 0) {
            cout << i << endln;
            return;
        }
    }

    cout << "0" << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}