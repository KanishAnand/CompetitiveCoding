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
    lli n, a, q;
    vector<lli> v;
    cin >> q;
    while (q--) {
        cin >> n;
        string st1, st2;
        cin >> st1;
        cin >> st2;
        if (n >= 3) {
            cout << "YES" << endl;
        } else if (n == 1) {
            if (st1[0] == '1' || st1[1] == '2') {
                if (st2[0] == '1' || st2[1] == '2') {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            } else {
                if (st2[0] == '1' || st2[1] == '2') {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            }
        } else {
            if (st1[0] == '1' || st1[0] == '2') {
                if (st1[1] != '1' && st1[1] != '2' && st2[1] != '1' &&
                    st2[1] != '2') {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                if (st2[1] != '1' && st2[1] != '2') {
                    cout << "YES" << endl;
                } else {
                    if (st2[0] != '1' && st2[0] != '2') {
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
    rt;
}
