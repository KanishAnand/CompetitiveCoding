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
    lli n, a, ind = -1;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> prime(1000005, 1);
    for (lli i = 2; i <= sqrt(1000002); i++) {
        if (prime[i] == 1) {
            for (lli j = i * i; j <= 1000000; j += i) {
                prime[j] = 0;
            }
        }
    }

    vector<lli> primeflag(1000005, 0);

    for (lli i = 0; i < n; i++) {
        lli val = v[i];
        if (primeflag[val] == 1) {
            ind = i;
            break;
        }
        primeflag[val] = 1;
        for (lli j = 2; j <= sqrt(val); j++) {
            if (val % j == 0) {
                if (primeflag[j] == 1 || primeflag[val / j] == 1) {
                    ind = i;
                    break;
                }
            }
        }
        if (ind != -1) {
            break;
        }

        for (lli j = 2; j <= sqrt(val); j++) {
            if (val % j == 0) {
                primeflag[j] = 1;
                primeflag[val / j] = 1;
            }
        }
    }

    if (ind == -1) {
        for (lli i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } else {
        lli beg = v[ind] + 1;
        while (1) {
            if (primeflag[beg] == 1) {
                beg++;
                continue;
            }

            lli flag = 0, val = beg;
            for (lli j = 2; j <= sqrt(val); j++) {
                if (val % j == 0) {
                    if (primeflag[j] == 1 || primeflag[val / j] == 1) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag == 0) {
                v[ind] = beg;
                primeflag[beg] = 1;
                for (lli j = 2; j <= sqrt(beg); j++) {
                    if (beg % j == 0) {
                        primeflag[j] = 1;
                        primeflag[beg / j] = 1;
                    }
                }
                break;
            }

            beg++;
        }

        lli cnt = n - ind - 1, no = 2;
        while (cnt > 0) {
            ind++;
            while (primeflag[no] == 1 || prime[no] == 0) {
                no++;
            }
            v[ind] = no;
            no++;
            cnt--;
        }

        for (lli i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
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