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
const lli MOD = 1e9 + 7;

lli make_no(vector<lli> v) {
    lli ans = 0, p = 1;
    for (lli i = 0; i < sz(v); i++) {
        ans += v[i] * p;
        p *= 2;
    }
    return ans;
}

lli solve1(lli x, lli y, lli l, lli r) {
    // lli x, y, l, r;
    // cin >> x >> y >> l >> r;
    if (l == r) {
        return l;
        // cout << l << endl;
        // return;
    }

    lli lc = l, rc = r, xc = x, yc = y;
    vector<lli> vl, vr, vx, vy;

    while (xc > 0) {
        vx.pb(xc % 2);
        xc /= 2;
    }

    while (yc > 0) {
        vy.pb(yc % 2);
        yc /= 2;
    }

    while (lc > 0) {
        vl.pb(lc % 2);
        lc /= 2;
    }
    while (rc > 0) {
        vr.pb(rc % 2);
        rc /= 2;
    }

    while (sz(vl) < sz(vr)) {
        vl.pb(0);
    }

    lli ind;

    for (lli i = sz(vl) - 1; i >= 0; i--) {
        if (vl[i] != vr[i]) {
            ind = i;
            break;
        }
    }

    vector<lli> ans;
    ans = vr;
    lli mx = (r & x) * (r & y);
    lli ch = (l & x) * (l & y);
    if (ch > mx) {
        mx = ch;
        ans = vl;
    } else if (ch == mx) {
        ans = vl;
    }
    // do it for l also

    for (lli i = 0; i <= ind; i++) {
        if (vr[i] == 1) {
            vr[i] = 0;
            for (lli j = 0; j < i; j++) {
                vr[j] = 1;
            }
            lli val = make_no(vr);
            lli p = (x & val) * (y & val);
            if (p > mx) {
                mx = p;
                ans = vr;
            }
        }
    }

    while (sz(vx) < sz(ans)) {
        vx.pb(0);
    }

    while (sz(vy) < sz(ans)) {
        vy.pb(0);
    }

    for (lli i = 0; i < sz(ans); i++) {
        if (vx[i] == 0 && vy[i] == 0) {
            ans[i] = 0;
        }
    }

    lli val = make_no(ans);
    if (val < l) {
        for (lli i = sz(ans) - 1; i >= 0; i--) {
            if (vl[i] == 1 && ans[i] == 0) {
                ans[i] = 1;
            } else if (ans[i] == 1 && vl[i] == 0) {
                break;
            }
        }
    }
    val = make_no(ans);

    if (mx == 0) {
        // cout << l << endl;
        return l;
    } else {
        return val;
        // cout << val << endl;
    }
}

lli solve2(lli x, lli y, lli l, lli r) {
    lli mx = -1, ans;
    // cin >> x >> y >> l >> r;
    for (lli i = l; i <= r; i++) {
        lli val = (i & x) * (i & y);
        if (val > mx) {
            mx = val;
            ans = i;
        }
    }
    // cout << mx << endl;
    // cout << ans << endl;
    return ans;
}

void solve() {
    lli n, a, val = 1e12, cnt = 0;
    // cout << rand() % val << " " << rand() % val << " ";
    while (1) {
        lli x = rand() % val;
        lli y = rand() % val;
        lli l = rand() % val;
        lli r = rand() % val;
        if (l > r) {
            swap(l, r);
        }
        lli a = solve1(x, y, l, r);
        lli b = solve2(x, y, l, r);
        if (a == b) {
            cout << "YES" << endl;
        } else {
            cout << x << " " << y << " " << l << " " << r << endl;
            cout << "NO" << endl;
            break;
        }
        cnt++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t;
    // t = 40;
    // cout << t << endl;
    // while (t--)
    solve();
    rt;
}