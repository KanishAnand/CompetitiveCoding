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

vector<vector<lli>> v, seg;
string st;

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
    for (lli i = 0; i < 26; i++) {
        seg[pos][i] = seg[2 * pos][i] + seg[2 * pos + 1][i];
    }

    return;
}

void update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    }
    if (l > in || r < in) {
        return;
    }
    if (l == r) {
        v[in][st[in] - 'a']--;
        seg[pos][st[in] - 'a']--;
        st[in] = (char)(val + 'a');
        v[in][val]++;
        seg[pos][val]++;
        return;
    }
    if (in <= mid) {
        update(2 * pos, in, val, l, mid);
    } else {
        update(2 * pos + 1, in, val, mid + 1, r);
    }
    for (lli i = 0; i < 26; i++) {
        seg[pos][i] = seg[2 * pos][i] + seg[2 * pos + 1][i];
    }
    return;
}

vector<lli> query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r) {
        vector<lli> tmp(26, 0);
        return tmp;
    }
    if (end < l || beg > r) {
        vector<lli> tmp(26, 0);
        return tmp;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    vector<lli> v1 = query(2 * pos, beg, end, l, mid);
    vector<lli> v2 = query(2 * pos + 1, beg, end, mid + 1, r);
    for (lli i = 0; i < 26; i++) {
        v1[i] += v2[i];
    }
    return v1;
}

void solve() {
    lli n, a, q, ind;
    cin >> st;
    n = st.length();
    v.resize(n + 2, vector<lli>(26, 0));
    seg.resize(4 * n + 2, vector<lli>(26, 0));

    for (lli i = 0; i < n; i++) {
        v[i][st[i] - 'a']++;
    }

    build(1, 0, n - 1);

    lli l, r;
    cin >> q;

    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> ind;
            char ch;
            cin >> ch;
            ind--;
            update(1, ind, (ch - 'a'), 0, n - 1);
        } else {
            cin >> l >> r;
            l--;
            r--;
            vector<lli> ans = query(1, l, r, 0, n - 1);
            lli cnt = 0;
            for (lli i = 0; i < 26; i++) {
                if (ans[i] != 0) {
                    cnt++;
                }
            }
            cout << cnt << endln;
        }
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