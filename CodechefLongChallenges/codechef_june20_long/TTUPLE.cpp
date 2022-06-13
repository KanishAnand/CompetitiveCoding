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

lli fun(lli d, lli e, lli s, lli t) {
    lli val1 = s - d;
    lli val2 = t - e;

    if (val1 == val2) {
        return 1;
    }

    if (d != 0 && e != 0) {
        if ((s % d == 0) && (t % e == 0)) {
            if (s / d == t / e) {
                return 1;
            }
        }
    }
    return 2;
}

lli fun1(lli a, lli b, lli c, lli p, lli q, lli r) {
    lli cnt = 0;
    if (a == p) {
        cnt++;
    }
    if (b == q) {
        cnt++;
    }
    if (c == r) {
        cnt++;
    }
    if (cnt == 3) {
        return 0;
    }
    if (cnt == 2) {
        return 1;
    }
    if (cnt == 1) {
        lli d, e, s, t, flag = 0;
        if (a != p) {
            d = a;
            s = p;
            flag = 1;
        }
        if (b != q) {
            if (flag == 0) {
                d = b;
                s = q;
                flag = 1;
            } else {
                e = b;
                t = q;
            }
        }
        if (c != r) {
            e = c;
            t = r;
        }

        lli pp = fun(d, e, s, t);
        if (pp == 1) {
            return 1;
        } else {
            return 2;
        }
    }
    return 2;
}

void solve() {
    lli a, b, c;
    lli p, q, r;
    cin >> a >> b >> c;
    cin >> p >> q >> r;

    lli cnt = 0;
    if (a == p) {
        cnt++;
    }
    if (b == q) {
        cnt++;
    }
    if (c == r) {
        cnt++;
    }
    if (cnt == 3) {
        cout << "0" << endl;
        return;
    }
    if (cnt == 2) {
        cout << "1" << endl;
        return;
    }
    if (cnt == 1) {
        lli d, e, s, t, flag = 0;

        if (a != p) {
            d = a;
            s = p;
            flag = 1;
        }
        if (b != q) {
            if (flag == 0) {
                d = b;
                s = q;
                flag = 1;
            } else {
                e = b;
                t = q;
            }
        }
        if (c != r) {
            e = c;
            t = r;
        }

        lli pp = fun(d, e, s, t);
        if (pp == 1) {
            cout << "1" << endl;
        } else {
            cout << "2" << endl;
        }
        return;
    }

    // all different
    lli val1 = p - a;
    lli val2 = q - b;
    lli val3 = r - c;

    if ((val1 == val2) && (val2 == val3)) {
        cout << "1" << endl;
        return;
    }

    if (a != 0 && b != 0 && c != 0) {
        if (p % a == 0 && q % b == 0 && r % c == 0) {
            if ((p / a == q / b) && (q / b == r / c)) {
                cout << "1" << endl;
                return;
            }
        }
    }

    // check for ans: 2
    vector<lli> v1, v2;
    v1.pb(a), v1.pb(b), v1.pb(c);
    v2.pb(p), v2.pb(q), v2.pb(r);

    for (lli i = 0; i < 3; i++) {
        lli val = v2[i] - v1[i];
        for (lli j = 1; j <= 7; j++) {
            lli tmp = j, rem;
            lli x = a, y = b, z = c;
            lli cnt = 0;
            while (tmp > 0) {
                rem = tmp % 2;
                tmp /= 2;
                if (rem == 1) {
                    if (cnt == 0) {
                        x += val;
                    } else if (cnt == 1) {
                        y += val;
                    } else {
                        z += val;
                    }
                }
                cnt++;
            }

            lli pp = fun1(x, y, z, p, q, r);
            if (pp == 1) {
                cout << "2" << endl;
                return;
            }
        }
    }

    for (lli i = 0; i < 3; i++) {
        if (v1[i] == 0) {
            continue;
        }
        if (v2[i] % v1[i] != 0) {
            continue;
        }
        lli val = v2[i] / v1[i];
        for (lli j = 1; j <= 7; j++) {
            lli tmp = j, rem;
            lli x = a, y = b, z = c;
            lli cnt = 0;
            while (tmp > 0) {
                rem = tmp % 2;
                tmp /= 2;
                if (rem == 1) {
                    if (cnt == 0) {
                        x *= val;
                    } else if (cnt == 1) {
                        y *= val;
                    } else {
                        z *= val;
                    }
                }
                cnt++;
            }

            lli pp = fun1(x, y, z, p, q, r);
            if (pp == 1) {
                cout << "2" << endl;
                return;
            }
        }
    }

    for (lli i = 0; i < 3; i++) {
        lli val = v1[i] - v2[i];
        for (lli j = 1; j <= 7; j++) {
            lli tmp = j, rem;
            lli x = p, y = q, z = r;
            lli cnt = 0;
            while (tmp > 0) {
                rem = tmp % 2;
                tmp /= 2;
                if (rem == 1) {
                    if (cnt == 0) {
                        x += val;
                    } else if (cnt == 1) {
                        y += val;
                    } else {
                        z += val;
                    }
                }
                cnt++;
            }
            lli pp = fun1(a, b, c, x, y, z);
            if (pp == 1) {
                cout << "2" << endl;
                return;
            }
        }
    }

    for (lli i = 0; i < 3; i++) {
        if (v1[i] == 0) {
            continue;
        }
        if (v2[i] % v1[i] != 0) {
            continue;
        }

        lli val = v2[i] / v1[i];

        for (lli j = 1; j <= 7; j++) {
            lli tmp = j, rem;
            lli x = p, y = q, z = r;
            lli cnt = 0;
            lli ff = 0;
            while (tmp > 0) {
                rem = tmp % 2;
                tmp /= 2;
                if (rem == 1) {
                    if (cnt == 0) {
                        if (val == 0) {
                            if (x != 0) {
                                ff = 1;
                                break;
                            }
                            x = 0;
                        } else {
                            if (x % val != 0) {
                                ff = 1;
                                break;
                            }
                            x /= val;
                        }
                    } else if (cnt == 1) {
                        if (val == 0) {
                            if (y != 0) {
                                ff = 1;
                                break;
                            }
                            y = 0;
                        } else {
                            if (y % val != 0) {
                                ff = 1;
                                break;
                            }
                            y /= val;
                        }
                    } else {
                        if (val == 0) {
                            if (z != 0) {
                                ff = 1;
                                break;
                            }
                            z = 0;
                        } else {
                            if (z % val != 0) {
                                ff = 1;
                                break;
                            }
                            z /= val;
                        }
                    }
                }
                cnt++;
            }

            if (ff == 0) {
                lli pp = fun1(a, b, c, x, y, z);
                if (pp == 1) {
                    cout << "2" << endl;
                    return;
                }
            }
        }
    }

    lli vv1 = a - b;
    lli vv2 = p - q;
    if (vv1 != 0) {
        if (vv2 % vv1 != 0) {
            cout << "3" << endl;
            return;
        } else {
            lli xx = vv2 / vv1;
            lli yy = p - a * xx;
            lli tmp2 = b * xx + yy;
            lli tmp3 = c * xx + yy;
            if (tmp2 == q && tmp3 == r) {
                cout << "2" << endl;
            } else {
                cout << "3" << endl;
            }
            return;
        }
    } else {
        if (vv2 != 0) {
            cout << "3" << endl;
        } else {
            vv1 = a - c;
            vv2 = p - r;
            if (vv1 == 0 && vv2 == 0) {
                cout << "2" << endl;
                return;
            }
            if (vv1 == 0 && vv2 != 0) {
                cout << "3" << endl;
                return;
            }
            if (vv1 != 0 && vv2 == 0) {
                cout << "3" << endl;
                return;
            }
            lli xx = vv2 / vv1;
            lli yy = p - a * xx;
            lli tmp2 = b * xx + yy;
            lli tmp3 = c * xx + yy;
            if (tmp2 == q && tmp3 == r) {
                cout << "2" << endl;
            } else {
                cout << "3" << endl;
            }
            return;
        }
        return;
    }

    cout << "3" << endl;
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}