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
    lli n, a;
    cin >> n;
    lli beg = 1, end = n, flag = 0;
    char ch;
    lli p = 0;
    int pp = 0;

    while (beg <= end) {
        assert(pp <= 300);
        while (1) {
            if (p == 0) {
                pp++;
                assert(pp <= 300);
                cout << beg << endl;
                beg++;
                p = 1;
                cin >> ch;
                if (ch == 'E') {
                    flag = 1;
                    break;
                }
                if (ch == 'L') {
                    break;
                }
            } else {
                pp++;
                assert(pp <= 300);
                cout << end << endl;
                end--;
                p = 0;
                cin >> ch;
                if (ch == 'E') {
                    flag = 1;
                    break;
                }
                if (ch == 'G') {
                    break;
                }
            }
        }

        if (flag == 1) {
            break;
        }

        lli mid = (beg + end) / 2;

        pp++;
        assert(pp <= 300);
        cout << mid << endl;
        cin >> ch;
        if (ch == 'E') {
            flag = 1;
            break;
        }

        if (ch == 'L') {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
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