#include <bits/stdc++.h>
using namespace std;
#define lli double
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli x1, Y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

int fun(double a, double b) {
    if (a >= x3 && a <= x4 && b >= y3 && b <= y4) {
        return 1;
    } else {
        return 0;
    }
}

int fun2(lli a, lli b) {
    if (a >= x5 && a <= x6 && b >= y5 && b <= y6) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // vector<lli> v;
    cin >> x1 >> Y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    lli j, flag = 0, flag1 = 0, flag2 = 0, flag3 = 0;
    j = Y1;
    for (int i = x1; i <= x2; i++) {
        lli a = fun(i, j);
        lli b = fun2(i, j);
        lli c = fun(min(x2, i + 0.1), j);
        lli d = fun2(min(x2, i + 0.1), j);
        if (a == 0 && b == 0) {
            flag = 1;
            break;
        }
        if (c == 0 && d == 0) {
            flag = 1;
            break;
        }
    }

    j = y2;
    for (int i = x1; i <= x2; i++) {
        lli a = fun(i, j);
        lli b = fun2(i, j);
        lli c = fun(min(x2, i + 0.1), j);
        lli d = fun2(min(x2, i + 0.1), j);
        if (a == 0 && b == 0) {
            flag1 = 1;
            break;
        }
        if (c == 0 && d == 0) {
            flag1 = 1;
            break;
        }
    }

    lli i = x1;
    for (j = Y1; j <= y2; j++) {
        lli a = fun(i, j);
        lli b = fun2(i, j);
        lli c = fun(i, min(y2, j + 0.1));
        lli d = fun2(i, min(y2, j + 0.1));
        if (a == 0 && b == 0) {
            flag2 = 1;
            break;
        }
        if (c == 0 && d == 0) {
            flag2 = 1;
            break;
        }
    }

    i = x2;
    for (j = Y1; j <= y2; j++) {
        lli a = fun(i, j);
        lli b = fun2(i, j);
        lli c = fun(i, min(y2, j + 0.1));
        lli d = fun2(i, min(y2, j + 0.1));
        if (a == 0 && b == 0) {
            flag3 = 1;
            break;
        }
        if (c == 0 && d == 0) {
            flag3 = 1;
            break;
        }
    }

    if (flag == 0 && flag1 == 0 && flag2 == 0 && flag3 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    rt;
}