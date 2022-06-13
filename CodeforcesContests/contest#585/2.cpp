#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endl '\n'
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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    vector<lli> v, dpp, dpn;
    cin >> n;
    dpp.resize(n + 1, 0);
    dpn.resize(n + 1, 0);
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }

    if (v[0] > 0) {
        dpp[0] = 1;
        dpn[0] = 0;
    } else {
        dpp[0] = 0;
        dpn[0] = 1;
    }

    fr(i, 1, n) {
        if (v[i] > 0) {
            dpp[i] += dpp[i - 1];
            dpn[i] += dpn[i - 1];
            ++dpp[i];
        } else {
            dpp[i] += dpn[i - 1];
            dpn[i] += dpp[i - 1];
            ++dpn[i];
        }
    }

    lli cp = 0, cn = 0;
    fr(i, 0, n) {
        cp += dpp[i];
        cn += dpn[i];
    }

    cout << cn << " " << cp << endl;
    rt;
}
