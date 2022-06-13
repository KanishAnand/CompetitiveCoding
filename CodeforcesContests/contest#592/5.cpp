#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

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
    input(n, v);
    sort(all(v));
    vector<lli> pref(n + 2, 0), suff(n + 2, 0);
    fr(i, 1, n) {
        pref[i] = (v[i] - v[i - 1]) * i + pref[i - 1];
    }

    for (lli i = n - 2; i >= 0; i--) {
        suff[i] = (v[i + 1] - v[i]) * (n - i - 1) + suff[i + 1];
    }
    lli ans = 1e9 + 5;
    vector<lli> suf;
    fr(i, 0, n) {
        suf.pb(suff[n - 1 - i]);
    }
    sort(all(suf));
    if (pref[n - 1] <= k || suff[0] <= k) {
        cout << "0" << endl;
        rt;
    }

    for (lli i = 0; i < n - 1; i++) {
        lli val = k - pref[i];
        // cout << i << v[i] << endl;

        if (val < 0) {
            break;
        }
        // cout << i << v[i] << endl;
        // auto it = lower_bound(suff.begin(),suff.end(),val);
        // lli in = find index of suffix array with cost <= val lli cost =
        //              k - (pref[i] + suff[]);
        // cout << val << endl;
        auto itr = lower_bound(suf.begin(), suf.end(), val);
        // cout << *itr << endl;
        if (itr == suf.end()) {
            itr--;
            lli in = itr - suf.begin();
            in = n - in - 1;
            lli value = v[in] - v[i];
            value = max(value, (lli)0);
            lli cost = k - (pref[i] + suff[in]);

            if (cost != 0 && value != 0) {
                lli x = min(i + 1, n - in);
                lli t = cost / x;
                if (i + 1 <= n - in) {
                    if (t > v[i + 1] - v[i]) {
                        value -= (v[i + 1] - v[i]);
                        cost -= (v[i + 1] - v[i]) * (i + 1);
                    } else {
                        value -= t;
                        cost -= t * (i + 1);
                    }
                    t = cost / (n - in);
                    if (t > v[in] - v[in - 1]) {
                        value -= v[in] - v[in - 1];
                        cost -= (v[in] - v[in - 1]) * (n - in);
                    } else {
                        value -= t;
                        cost -= t * (n - in);
                    }
                } else {
                    if (t > v[in] - v[in - 1]) {
                        value -= v[in] - v[in - 1];
                        cost -= (v[in] - v[in - 1]) * (n - in);
                    } else {
                        value -= t;
                        cost -= t * (n - in);
                    }
                    t = cost / (i + 1);
                    if (t > v[i + 1] - v[i]) {
                        value -= (v[i + 1] - v[i]);
                        cost -= (v[i + 1] - v[i]) * (i + 1);
                    } else {
                        value -= t;
                        cost -= t * (i + 1);
                    }
                }

                // value -= t;
                value = max(value, (lli)0);
            }
            if (value < ans) {
                ans = value;
            }
        }

        else if (itr != suf.begin()) {
            // cout << i << v[i] << endl;

            if (*itr != val) {
                itr--;
            }
            lli in = itr - suf.begin();
            in = n - in - 1;
            lli value = v[in] - v[i];
            // cout << value << " " << in << " " << i << endl;
            value = max(value, (lli)0);
            lli cost = k - (pref[i] + suff[in]);
            // cout << cost << " " << value << endl;
            if (cost != 0 && value != 0) {
                lli x = min(i + 1, n - in);
                lli t = cost / x;
                if (i + 1 <= n - in) {
                    if (t > v[i + 1] - v[i]) {
                        value -= (v[i + 1] - v[i]);
                        cost -= (v[i + 1] - v[i]) * (i + 1);
                    } else {
                        value -= t;
                        cost -= t * (i + 1);
                    }
                    t = cost / (n - in);
                    if (t > v[in] - v[in - 1]) {
                        value -= v[in] - v[in - 1];
                        cost -= (v[in] - v[in - 1]) * (n - in);
                    } else {
                        value -= t;
                        cost -= t * (n - in);
                    }
                } else {
                    if (t > v[in] - v[in - 1]) {
                        value -= v[in] - v[in - 1];
                        cost -= (v[in] - v[in - 1]) * (n - in);
                    } else {
                        value -= t;
                        cost -= t * (n - in);
                    }
                    t = cost / (i + 1);
                    if (t > v[i + 1] - v[i]) {
                        value -= (v[i + 1] - v[i]);
                        cost -= (v[i + 1] - v[i]) * (i + 1);
                    } else {
                        value -= t;
                        cost -= t * (i + 1);
                    }
                }
                // cout << value << " " << t << endl;
                // value -= t;
                // cout << value << endl;
                value = max(value, (lli)0);
            }
            if (value < ans) {
                ans = value;
            }
        } else {
            // cout << i << v[i] << endl;
            if (*itr == val) {
                lli in = itr - suf.begin();
                in = n - in - 1;
                lli value = v[in] - v[i];
                value = max(value, (lli)0);
                lli cost = k - (pref[i] + suff[in]);
                if (cost != 0 && value != 0) {
                    lli x = min(i + 1, n - in);
                    lli t = cost / x;
                    if (i + 1 <= n - in) {
                        if (t > v[i + 1] - v[i]) {
                            value -= (v[i + 1] - v[i]);
                            cost -= (v[i + 1] - v[i]) * (i + 1);
                        } else {
                            value -= t;
                            cost -= t * (i + 1);
                        }
                        t = cost / (n - in);
                        if (t > v[in] - v[in - 1]) {
                            value -= v[in] - v[in - 1];
                            cost -= (v[in] - v[in - 1]) * (n - in);
                        } else {
                            value -= t;
                            cost -= t * (n - in);
                        }
                    } else {
                        if (t > v[in] - v[in - 1]) {
                            value -= v[in] - v[in - 1];
                            cost -= (v[in] - v[in - 1]) * (n - in);
                        } else {
                            value -= t;
                            cost -= t * (n - in);
                        }
                        t = cost / (i + 1);
                        if (t > v[i + 1] - v[i]) {
                            value -= (v[i + 1] - v[i]);
                            cost -= (v[i + 1] - v[i]) * (i + 1);
                        } else {
                            value -= t;
                            cost -= t * (i + 1);
                        }
                    }
                    // value -= t;
                    value = max(value, (lli)0);
                }
                if (value < ans) {
                    ans = value;
                }
            }
        }
        // cout << ans << " " << i << endl;
    }
    cout << ans << endl;
    rt;
}
