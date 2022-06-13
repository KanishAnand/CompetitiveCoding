#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

lli gcd(lli a, lli b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    vector<lli> v;
    set<lli> st;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
        st.insert(a);
    }

    sort(v.begin(), v.end());

    lli mx = v[v.size() - 1], p = 0;
    for (lli i = 0; i < v.size() - 1; i++) {
        p = gcd(mx - v[i], p);
    }

    lli ans = 0;
    fr(i, 0, n) {
        ans += (mx - v[i]) / p;
    }
    cout << ans << " " << p << endl;
    rt;
}
