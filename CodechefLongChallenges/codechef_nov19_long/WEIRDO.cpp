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

int vowel_cons(char a) {
    return (a == 'a' || a == 'i' || a == 'e' || a == 'o' || a == 'u');
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        lli l;
        cin >> l;
        vector<string> chefa, chefb;
        string st;

        fr(i, 0, l) {
            cin >> st;
            lli prev = -1;
            lli p = st.length();
            lli flag = 0;
            fr(j, 0, p) {
                lli c = vowel_cons(st[j]);
                if (c == 0) {
                    if (prev != -1) {
                        if (j - prev <= 2) {
                            flag = 1;
                            break;
                        }
                    }
                    prev = j;
                }
            }

            if (flag == 1) {
                chefb.pb(st);
            } else {
                chefa.pb(st);
            }
        }

        vector<long double> val(27, 0), cnt(27, 0);

        for (auto &ch : chefa) {
            vector<lli> ne(27, 0);
            lli p = ch.size();

            fr(j, 0, p) {
                ne[ch[j] - 'a']++;
                cnt[ch[j] - 'a']++;
            }

            for (lli j = 0; j < 26; j++) {
                if (ne[j] > 0) {
                    val[j]++;
                }
            }
        }

        vector<long double> val2(27, 0), cnt2(27, 0);
        for (auto &ch : chefb) {
            vector<lli> ne(27, 0);
            lli p = ch.size();

            fr(j, 0, p) {
                ne[ch[j] - 'a']++;
                cnt2[ch[j] - 'a']++;
            }

            for (lli j = 0; j < 26; j++) {
                if (ne[j] > 0) {
                    val2[j]++;
                }
            }
        }

        // val,cnt
        // long double sca = 1, scb = 1, sca2 = 1, scb2 = 1;
        // cout << val[0] << " " << val[1] << " " << val[2] << endl;
        // cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        lli p1 = chefa.size();
        lli p2 = chefb.size();
        long double ret = 1;
        vector<lli> mul, div;
        fr(i, 0, 26) {
            if (val[i] != 0) {
                mul.pb(val[i]);
                for (int k = 0; k < p1; k++) {
                    div.pb(cnt[i]);
                }
            }

            if (val2[i] != 0) {
                div.pb(val2[i]);
                for (int k = 0; k < p2; k++) {
                    mul.pb(cnt2[i]);
                }
            }
        }

        long double pp = 1e7;
        long double qq = 10;
        lli in1 = 0, in2 = 0;
        lli aa = mul.size(), bb = div.size();

        while (1) {
            if (in1 < aa && ret - pp <= qq) {
                ret *= mul[in1];
                in1++;
            } else if (in2 < bb) {
                ret /= div[in2];
                in2++;
            } else {
                break;
            }
        }

        if (in2 < bb) {
            while (in2 < bb) {
                ret /= div[in2];
                in2++;
            }
        }

        // cout << sca << " " << sca2 << " " << scb << " " << scb2 << endl;
        // long double x = (long double)sca / (long double)sca2;
        // long double y = (long double)scb / (long double)scb2;
        // cout << x << " " << y << endl;
        // cout << sca << " " << scb << endl;
        long double q = ret;

        if (q - pp > qq) {
            cout << "Infinity" << endl;
        } else {
            cout << fixed << setprecision(10) << q << endl;
        }
    }
    rt;
}
