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
    lli n, a, minn = 1000;
    vector<lli> v(1000000, 0);
    string st;
    cin >> st;
    n = st.length();
    fr(i, 0, n) {
        if (minn < st[i] - 'a') {
            v[i] = 1;
        }
        if (st[i] - 'a' < minn) {
            minn = st[i] - 'a';
        }
        // v[i] = minn;
    }

    fr(k, 0, n) {
        if (v[k] == 1) {
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }
    }
    rt;
}
