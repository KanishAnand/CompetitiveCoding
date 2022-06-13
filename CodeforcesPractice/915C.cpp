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
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a, b;
    cin >> a >> b;
    vector<lli> va, vb;
    lli oa = a, ob = b;

    vector<lli> orgcnt(10, 0);

    while (a > 0) {
        va.pb(a % 10);
        orgcnt[a % 10]++;
        a /= 10;
    }
    while (b > 0) {
        vb.pb(b % 10);
        b /= 10;
    }

    sort(va.rbegin(), va.rend());
    reverse(all(vb));

    if (va.size() < vb.size()) {
        for (lli i = 0; i < va.size(); i++) {
            cout << va[i];
        }
        cout << endl;
    } else {
        vector<lli> no;

        for (lli i = 0; i < vb.size(); i++) {
            lli flag = 0;
            vector<lli> v;
            vector<lli> cnt = orgcnt;
            for (lli j = 0; j < i; j++) {
                if (cnt[vb[j]] == 0) {
                    flag = 1;
                    break;
                } else {
                    cnt[vb[j]]--;
                    v.pb(vb[j]);
                }
            }
            if (flag == 1) {
                continue;
            }

            flag = 1;
            for (lli j = vb[i] - 1; j >= 0; j--) {
                if (cnt[j] != 0) {
                    cnt[j]--;
                    v.pb(j);
                    flag = 0;
                    break;
                }
            }

            if (flag == 1) {
                continue;
            }

            for (lli j = 9; j >= 0; j--) {
                while (cnt[j] != 0) {
                    v.pb(j);
                    cnt[j]--;
                }
            }

            reverse(all(v));
            lli val = 0, p = 1;
            for (lli j = 0; j < v.size(); j++) {
                val += p * v[j];
                p *= 10;
            }

            no.pb(val);
        }

        lli flag = 0;
        for (lli i = 0; i < vb.size(); i++) {
            if (orgcnt[vb[i]] != 0) {
                orgcnt[vb[i]]--;
            } else {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            no.pb(ob);
        }

        sort(all(no));
        cout << no[no.size() - 1] << endl;
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