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
// //              tree_order_statistics_node_update>
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

string st;
lli n;

lli fun(string r1, string r2, string r3, lli itr) {
    vector<lli> v(n + 2, 0);
    lli ptr1 = sz(r1) - 1, ptr2 = sz(r2) - 1, ptr3 = sz(r3) - 1;

    while (ptr1 >= 0 && itr >= 0) {
        if (st[itr] == r1[ptr1]) {
            v[itr] = 1;
            --ptr1;
        }
        --itr;
    }
    if (ptr1 >= 0) {
        return 0;
    }

    itr = n - 1;
    while (ptr2 >= 0 && itr >= 0) {
        if (v[itr] == 0 && st[itr] == r2[ptr2]) {
            v[itr] = 1;
            --ptr2;
        }
        --itr;
    }
    if (ptr2 >= 0) {
        return 0;
    }

    itr = n - 1;
    while (ptr3 >= 0 && itr >= 0) {
        if (v[itr] == 0 && st[itr] == r3[ptr3]) {
            v[itr] = 1;
            --ptr3;
        }
        --itr;
    }
    if (ptr3 >= 0) {
        return 0;
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, q;
    char ch, b;
    cin >> n >> q;
    string r1 = "", r2 = "", r3 = "";
    cin >> st;
    fr(beg, 0, q) {
        cin >> ch >> a;
        if (ch == '+') {
            cin >> b;
            if (a == 1) {
                r1 += b;
            } else if (a == 2) {
                r2 += b;
            } else {
                r3 += b;
            }
        } else {
            if (a == 1) {
                r1.pop_back();
            } else if (a == 2) {
                r2.pop_back();
            } else {
                r3.pop_back();
            }
        }
        lli val = fun(r1, r2, r3, n - 1) || fun(r1, r3, r2, n - 1) ||
                  fun(r2, r1, r3, n - 1) || fun(r2, r3, r1, n - 1) ||
                  fun(r3, r2, r1, n - 1) || fun(r3, r1, r2, n - 1);
        if (val == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    rt;
}
