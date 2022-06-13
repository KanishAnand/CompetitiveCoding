#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;
lli check(vector<pair<pair<lli, lli>, char>> v) {
    lli a = v[0].first.first, b = v[0].first.second, c = v[1].first.first,
        d = v[1].first.second, e = v[2].first.first, f = v[2].first.second;
    if (a == c + e && d == f && a == b + d) {
        return 1;
    } else if ((b == d) && (d == f) && a + c + e == b) {
        return 2;
    } else if ((a == c) && (c == e) && (a == b + d + f)) {
        return 3;
    } else if (a == c && b + d == f && a + e == f) {
        return 4;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, c, d, e, f;
    // vector<lli> v;
    cin >> a >> b >> c >> d >> e >> f;
    int it = 0;
    while (it < 8) {
        int temp = it;
        int x = temp % 2;
        temp /= 2;
        int y = temp % 2;
        temp /= 2;
        int z = temp % 2;
        temp /= 2;
        ++it;
        vector<pair<pair<lli, lli>, char>> v;
        if (x == 1) {
            v.pb(make_pair(make_pair(a, b), 'A'));
        } else {
            v.pb(make_pair(make_pair(b, a), 'A'));
        }
        if (y == 1) {
            v.pb(make_pair(make_pair(c, d), 'B'));
        } else {
            v.pb(make_pair(make_pair(d, c), 'B'));
        }
        if (z == 1) {
            v.pb(make_pair(make_pair(e, f), 'C'));
        } else {
            v.pb(make_pair(make_pair(f, e), 'C'));
        }
        sort(v.rbegin(), v.rend());
        int p = check(v);
        // cout << p << endl;
        lli a1 = v[0].first.first, b1 = v[0].first.second,
            c1 = v[1].first.first, d1 = v[1].first.second,
            e1 = v[2].first.first, f1 = v[2].first.second;
        char ch1 = v[0].second, ch2 = v[1].second, ch3 = v[2].second;
        if (p == 1) {
            cout << a1 << endl;
            fr(i, 0, b1) {
                fr(j, 0, a1) {
                    cout << ch1;
                }
                cout << endl;
            }
            fr(i, 0, d1) {
                fr(j, 0, a1) {
                    if (j < c1) {
                        cout << ch2;
                    } else {
                        cout << ch3;
                    }
                }
                cout << "\n";
            }
            return 0;
        } else if (p == 2) {
            cout << b1 << endl;
            fr(i, 0, b1) {
                fr(j, 0, a1 + c1 + e1) {
                    if (j < a1) {
                        cout << ch1;
                    } else if (j < a1 + c1) {
                        cout << ch2;
                    } else {
                        cout << ch3;
                    }
                }
                cout << "\n";
            }
            return 0;
        } else if (p == 3) {
            cout << a1 << endl;
            fr(i, 0, b1) {
                fr(j, 0, a1) {
                    cout << ch1;
                }
                cout << endl;
            }
            fr(i, 0, d1) {
                fr(j, 0, a1) {
                    cout << ch2;
                }
                cout << endl;
            }
            fr(i, 0, f1) {
                fr(j, 0, a1) {
                    cout << ch3;
                }
                cout << endl;
            }
            return 0;
        } else if (p == 4) {
            cout << a1 + e1 << endl;
            fr(i, 0, b1) {
                fr(j, 0, a1 + e1) {
                    if (j < a1) {
                        cout << ch1;
                    } else {
                        cout << ch3;
                    }
                }
                cout << endl;
            }
            fr(i, 0, d1) {
                fr(j, 0, a1 + e1) {
                    if (j < a1) {
                        cout << ch2;
                    } else {
                        cout << ch3;
                    }
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << "-1" << endl;
    rt;
}
