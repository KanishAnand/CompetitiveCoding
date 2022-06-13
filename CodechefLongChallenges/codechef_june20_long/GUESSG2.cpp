#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

void solve() {
    lli n, a;
    cin >> n;
    vector<pair<lli, lli>> v;
    v.pb({1, n});

    while (1) {
        // for (lli i = 0; i < v.size(); i++) {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }
        // cout << endl;
        lli cnt = 0, ind1, ind2, no1, no2;

        for (lli i = 0; i < v.size(); i++) {
            cnt += (v[i].second - v[i].first + 1);
        }
        lli val = cnt / 3;
        if (cnt % 3 != 0) {
            val++;
        }
        cnt = 0;
        for (lli i = 0; i < v.size(); i++) {
            lli p = v[i].second - v[i].first + 1;
            if (cnt + p >= val) {
                ind1 = i;
                no1 = v[i].first + (val - cnt) - 1;
                break;
            }
            cnt += p;
        }

        cnt = 0;
        val *= 2;

        for (lli i = 0; i < v.size(); i++) {
            lli p = v[i].second - v[i].first + 1;
            if (cnt + p >= val) {
                ind2 = i;
                no2 = v[i].first + (val - cnt) - 1;
                break;
            }
            cnt += p;
        }

        vector<pair<lli, lli>> tmp;
        string st = "";
        char ch;

        cout << no1 << endl;
        cin >> ch;
        if (ch == 'E') {
            break;
        }
        if (ch == 'G') {
            cout << no1 << endl;
            cin >> ch;
            if (ch == 'G') {
                // do with no1+1
                if (v[ind1].second >= no1 + 1) {
                    tmp.pb({no1 + 1, v[ind1].second});
                }
                for (lli i = ind1 + 1; i < v.size(); i++) {
                    tmp.pb({v[i].first, v[i].second});
                }
                // > b
            } else {
                st += ch;
                cout << no2 << endl;
                cin >> ch;
                if (ch == 'E') {
                    break;
                }
                st += ch;
                if (st == "LL") {
                    // do with no2-1
                    for (lli i = 0; i < ind2; i++) {
                        tmp.pb({v[i].first, v[i].second});
                    }
                    if (v[ind2].first <= no2 - 1) {
                        tmp.pb({v[ind2].first, no2 - 1});
                    }
                } else {
                    for (lli i = 0; i < ind1; i++) {
                        tmp.pb({v[i].first, v[i].second});
                    }

                    if (v[ind1].first <= no1 - 1) {
                        tmp.pb({v[ind1].first, no1 - 1});
                    }

                    if (v[ind2].second >= no2 + 1) {
                        tmp.pb({no2 + 1, v[ind2].second});
                    }

                    for (lli i = ind2 + 1; i < v.size(); i++) {
                        tmp.pb({v[i].first, v[i].second});
                    }
                }
            }
        } else {
            st += ch;
            cout << no2 << endl;
            cin >> ch;
            if (ch == 'E') {
                break;
            }
            st += ch;
            if (st == "LL") {
                // do with no2-1
                for (lli i = 0; i < ind2; i++) {
                    tmp.pb({v[i].first, v[i].second});
                }
                if (v[ind2].first <= no2 - 1) {
                    tmp.pb({v[ind2].first, no2 - 1});
                }
            } else {
                for (lli i = 0; i < ind1; i++) {
                    tmp.pb({v[i].first, v[i].second});
                }

                if (v[ind1].first <= no1 - 1) {
                    tmp.pb({v[ind1].first, no1 - 1});
                }

                if (v[ind2].second >= no2 + 1) {
                    tmp.pb({no2 + 1, v[ind2].second});
                }

                for (lli i = ind2 + 1; i < v.size(); i++) {
                    tmp.pb({v[i].first, v[i].second});
                }
            }
        }

        v = tmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}