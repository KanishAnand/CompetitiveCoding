#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>0
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
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
    lli n, a, t;
    vector<lli> v;
    cin >> t;
    while (t--) {
        string st;
        cin >> st;
        n = st.length();
        vector<lli> cnt(26, 0), od, ev;
        lli odd = 0, even = 0;
        fr(i, 0, n) {
            if (cnt[st[i] - 'a'] == 0) {
                if ((st[i] - 'a') % 2 == 0) {
                    ++even;
                    ev.pb(st[i] - 'a');
                } else {
                    ++odd;
                    od.pb(st[i] - 'a');
                }
            }
            cnt[st[i] - 'a']++;
        }
        if (odd == 0) {
            fr(i, 0, sz(ev)) {
                while (cnt[ev[i]] > 0) {
                    cout << (char)(ev[i] + 'a');
                    cnt[ev[i]]--;
                }
            }
        } else if (even == 0) {
            fr(i, 0, sz(od)) {
                while (cnt[od[i]] > 0) {
                    cout << (char)(od[i] + 'a');
                    cnt[od[i]]--;
                }
            }
        } else if (odd >= 3 || even == 1) {
            lli p = ev[0], ind = -1;
            fr(i, 0, sz(od)) {
                if (abs(p - od[i]) != 1) {
                    ind = i;
                    break;
                }
            }
            if (ind == -1) {
                cout << "No answer";
            } else {
                fr(i, 0, sz(od)) {
                    if (i != ind) {
                        while (cnt[od[i]] > 0) {
                            cout << (char)(od[i] + 'a');
                            cnt[od[i]]--;
                        }
                    }
                }
                while (cnt[od[ind]] > 0) {
                    cout << (char)(od[ind] + 'a');
                    cnt[od[ind]]--;
                }

                fr(i, 0, sz(ev)) {
                    while (cnt[ev[i]] > 0) {
                        cout << (char)(ev[i] + 'a');
                        cnt[ev[i]]--;
                    }
                }
            }
        } else if (even >= 3 || odd == 1) {
            lli p = od[0], ind = -1;
            fr(i, 0, sz(ev)) {
                if (abs(p - ev[i]) != 1) {
                    ind = i;
                    break;
                }
            }
            if (ind == -1) {
                cout << "No answer";
            } else {
                fr(i, 0, sz(ev)) {
                    if (i != ind) {
                        while (cnt[ev[i]] > 0) {
                            cout << (char)(ev[i] + 'a');
                            cnt[ev[i]]--;
                        }
                    }
                }
                while (cnt[ev[ind]] > 0) {
                    cout << (char)(ev[ind] + 'a');
                    cnt[ev[ind]]--;
                }
                fr(i, 0, sz(od)) {
                    while (cnt[od[i]] > 0) {
                        cout << (char)(od[i] + 'a');
                        cnt[od[i]]--;
                    }
                }
            }
        } else {
            lli p = od[0], ind = -1, pp = 0;
            fr(i, 0, sz(ev)) {
                if (abs(p - ev[i]) != 1) {
                    ind = i;
                    break;
                }
            }

            if (ind == -1) {
                pp = 1;
                p = od[1];
                fr(i, 0, sz(ev)) {
                    if (abs(p - ev[i]) != 1) {
                        ind = i;
                        break;
                    }
                }
            }

            fr(i, 0, sz(ev)) {
                if (i != ind) {
                    while (cnt[ev[i]] > 0) {
                        cout << (char)(ev[i] + 'a');
                        cnt[ev[i]]--;
                    }
                }
            }
            while (cnt[ev[ind]] > 0) {
                cout << (char)(ev[ind] + 'a');
                cnt[ev[ind]]--;
            }
            if (pp == 0) {
                while (cnt[od[0]] > 0) {
                    cout << (char)(od[0] + 'a');
                    cnt[od[0]]--;
                }
                while (cnt[od[1]] > 0) {
                    cout << (char)(od[1] + 'a');
                    cnt[od[1]]--;
                }
            } else {
                while (cnt[od[1]] > 0) {
                    cout << (char)(od[1] + 'a');
                    cnt[od[1]]--;
                }
                while (cnt[od[0]] > 0) {
                    cout << (char)(od[0] + 'a');
                    cnt[od[0]]--;
                }
            }
        }
        cout << endl;
    }

    rt;
}
