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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, c, d, sum = 0;
    vector<lli> v;
    // cin >> a>>b>>c>>d;
    fr(i, 0, 4) {
        cin >> a;
        sum += a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    lli flag = 0;
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        rt;
    }
    if (v[3] == sum / 2) {
        flag = 1;
    } else if (v[3] + v[1] == sum / 2) {
        flag = 1;
    } else if (v[3] + v[2] == sum / 2) {
        flag = 1;
    } else if (v[3] + v[0] == sum / 2) {
        flag = 1;
    }
    if (flag == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    rt;
}
