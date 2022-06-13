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
    lli n, a, k;
    vector<lli> v;
    cin >> n >> k;
    string st;
    cin >> st;

    if (n == 1) {
        if (k == 1) {
            cout << "0" << endl;
        } else {
            cout << st << endl;
        }
        rt;
    }

    if (n > 1) {
        if (k > 0) {
            if (st[0] != '1') {
                st[0] = '1';
                --k;
            }
        }
        fr(i, 1, n) {
            if (k > 0) {
                if (st[i] != '0') {
                    st[i] = '0';
                    --k;
                }
            } else {
                break;
            }
        }
    }
    cout << st << endl;
    rt;
}
