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
    vector<lli> v;
    cin >> n;
    string st;
    cin >> st;
    lli val1 = 0, val2 = 0, no1 = 0, no2 = 0;
    fr(i, 0, n / 2) {
        if (st[i] == '?') {
            no1++;
        } else {
            val1 += st[i] - '0';
        }
    }

    fr(i, n / 2, n) {
        if (st[i] == '?') {
            no2++;
        } else {
            val2 += st[i] - '0';
        }
    }
    // lli turn11 =,turn12 =

    if (val1 > val2) {
        lli x = val1 - val2, f = 0;
        if (x % 9 == 0) {
            f = 1;
        }
        x = x / 9 + 1;
        if (f == 1) {
            --x;
        }
        if (no2 - no1 >= x) {
            cout << "Bicarp" << endl;
        } else {
            cout << "Monocarp" << endl;
        }
        // if (val1 - val2 > 9) {
        //     if (no2 - no1 > 1) {
        //         cout << "Bicarp" << endl;
        //     } else {
        //         cout << "Monocarp" << endl;
        //     }
        // } else {
        //     if (no2 - no1 >= 1) {
        //         cout << "Bicarp" << endl;
        //     } else {
        //         cout << "Monocarp" << endl;
        //     }
        // }
    } else if (val1 < val2) {
        lli x = val2 - val1, f = 0;
        if (x % 9 == 0) {
            f = 1;
        }
        x = x / 9 + 1;
        if (f == 1) {
            --x;
        }
        if (no1 - no2 >= x) {
            cout << "Bicarp" << endl;
        } else {
            cout << "Monocarp" << endl;
        }
        // if (val2 - val1 > 9) {
        //     if (no1 - no2 > 1) {
        //         cout << "Bicarp" << endl;
        //     } else {
        //         cout << "Monocarp" << endl;
        //     }
        // } else {
        //     if (no1 - no2 >= 1) {
        //         cout << "Bicarp" << endl;
        //     } else {
        //         cout << "Monocarp" << endl;
        //     }
        // }
    } else {
        if (no1 == no2) {
            cout << "Bicarp" << endl;
        } else {
            cout << "Monocarp" << endl;
        }
    }
    rt;
}
