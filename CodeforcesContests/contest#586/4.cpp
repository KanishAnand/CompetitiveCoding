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
    cin >> n;
    vector<lli> check(n + 1, 0);
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    // a = v[0];
    // lli odd = 0, even = 0;
    // if (a % 2 == 0) {
    //     ++even;
    // } else {
    //     ++odd;
    // }

    // fr(i, 1, n) {
    //     // lli c = gcd(a, v[i]);
    //     // lli x = v[i] / c;
    //     // // lli y = a/c;
    //     // if (x % 2 == 0) {
    //     //     ++even;
    //     //     ve.pb(v[i]);
    //     // } else {
    //     //     ++odd;
    //     //     vo.pb(v[i]);
    //     // }
    // }
    lli z = 0, o = 0;

    fr(i, 0, n - 1) {
        lli c = gcd(v[i], v[i + 1]);
        lli x = v[i + 1] / c;
        lli y = v[i] / c;
        if (x % 2 == y % 2) {
            check[i + 1] = check[i];
        } else {
            check[i + 1] = 1 - check[i];
        }
    }
    fr(i, 0, n) {
        if (check[i] == 0) {
            z++;
        } else {
            o++;
        }
    }

    if (1) {
        cout << z << endl;
        fr(i, 0, n) {
            if (check[i] == 0) {
                cout << v[i] << " ";
            }
        }
    } else {
        cout << o << endl;
        fr(i, 0, n) {
            if (check[i] == 1) {
                cout << v[i] << " ";
            }
        }
    }

    // if (a % 2 == 0) {
    //     if (even + 1 > odd) {
    //         cout << odd << endl;
    //         fr(i, 0, vo.size()) {
    //             cout << vo[i] << " ";
    //         }
    //     } else {
    //         cout << even + 1 << endl;
    //         fr(i, 0, ve.size()) {
    //             cout << ve[i] << " ";
    //         }
    //     }
    // } else {
    //     if (even < odd + 1) {
    //         cout << even << endl;
    //         fr(i, 0, ve.size()) {
    //             cout << ve[i] << " ";
    //         }
    //     } else {
    //         cout << odd + 1 << endl;
    //         fr(i, 0, vo.size()) {
    //             cout << vo[i] << " ";
    //         }
    //     }
    // }

    cout << endl;
    rt;
}