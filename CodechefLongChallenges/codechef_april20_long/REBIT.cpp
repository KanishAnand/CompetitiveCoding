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
const lli MOD = 998244353;
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
struct store {
    lli a, b, c, d;
    char ch;
};

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

void solve() {
    string st;
    cin >> st;
    if (st[0] == '#') {
        cout << "748683265 748683265 748683265 748683265" << endl;
        return;
    }

    stack<struct store> stck;

    for (lli i = 0; i < st.length(); i++) {
        if (st[i] == '#') {
            struct store tmp;
            tmp.ch = 'A';
            tmp.a = 1;
            tmp.b = 1;
            tmp.c = 1;
            tmp.d = 1;
            stck.push(tmp);
        } else if (st[i] == ')') {
            struct store tmp;
            tmp.a = 0;
            tmp.b = 0;
            tmp.c = 0;
            tmp.d = 0;
            tmp.ch = 'A';
            struct store first = stck.top();
            stck.pop();
            struct store operation = stck.top();
            stck.pop();
            struct store second = stck.top();
            stck.pop();
            stck.pop();
            if (operation.ch == '&') {
                // and
                lli val;
                val = ((second.a + second.b) % MOD +
                       (second.c + second.d) % MOD) %
                      MOD;
                tmp.a += (first.a * val) % MOD;
                tmp.a %= MOD;

                tmp.a += (first.b * second.a) % MOD;
                tmp.a %= MOD;
                tmp.b += (first.b * second.b) % MOD;
                tmp.b %= MOD;
                tmp.c += (first.b * second.c) % MOD;
                tmp.c %= MOD;
                tmp.d += (first.b * second.d) % MOD;
                tmp.d %= MOD;

                tmp.a += (first.c * second.a) % MOD;
                tmp.a %= MOD;
                tmp.c += (first.c * second.b) % MOD;
                tmp.c %= MOD;
                tmp.c += (first.c * second.c) % MOD;
                tmp.c %= MOD;
                tmp.a += (first.c * second.d) % MOD;
                tmp.a %= MOD;

                tmp.a += (first.d * second.a) % MOD;
                tmp.a %= MOD;
                tmp.d += (first.d * second.b) % MOD;
                tmp.d %= MOD;
                tmp.a += (first.d * second.c) % MOD;
                tmp.a %= MOD;
                tmp.d += (first.d * second.d) % MOD;
                tmp.d %= MOD;

            } else if (operation.ch == '|') {
                // or
                tmp.a += (first.a * second.a) % MOD;
                tmp.a %= MOD;
                tmp.b += (first.a * second.b) % MOD;
                tmp.b %= MOD;
                tmp.c += (first.a * second.c) % MOD;
                tmp.c %= MOD;
                tmp.d += (first.a * second.d) % MOD;
                tmp.d %= MOD;

                tmp.b += (first.b * second.a) % MOD;
                tmp.b %= MOD;
                tmp.b += (first.b * second.b) % MOD;
                tmp.b %= MOD;
                tmp.b += (first.b * second.c) % MOD;
                tmp.b %= MOD;
                tmp.b += (first.b * second.d) % MOD;
                tmp.b %= MOD;

                tmp.c += (first.c * second.a) % MOD;
                tmp.c %= MOD;
                tmp.b += (first.c * second.b) % MOD;
                tmp.b %= MOD;
                tmp.c += (first.c * second.c) % MOD;
                tmp.c %= MOD;
                tmp.b += (first.c * second.d) % MOD;
                tmp.b %= MOD;

                tmp.d += (first.d * second.a) % MOD;
                tmp.d %= MOD;
                tmp.b += (first.d * second.b) % MOD;
                tmp.b %= MOD;
                tmp.b += (first.d * second.c) % MOD;
                tmp.b %= MOD;
                tmp.d += (first.d * second.d) % MOD;
                tmp.d %= MOD;

            } else {
                // xor
                tmp.a += (first.a * second.a) % MOD;
                tmp.a %= MOD;
                tmp.b += (first.a * second.b) % MOD;
                tmp.b %= MOD;
                tmp.c += (first.a * second.c) % MOD;
                tmp.c %= MOD;
                tmp.d += (first.a * second.d) % MOD;
                tmp.d %= MOD;

                tmp.b += (first.b * second.a) % MOD;
                tmp.b %= MOD;
                tmp.a += (first.b * second.b) % MOD;
                tmp.a %= MOD;
                tmp.d += (first.b * second.c) % MOD;
                tmp.d %= MOD;
                tmp.c += (first.b * second.d) % MOD;
                tmp.c %= MOD;

                tmp.c += (first.c * second.a) % MOD;
                tmp.c %= MOD;
                tmp.d += (first.c * second.b) % MOD;
                tmp.d %= MOD;
                tmp.a += (first.c * second.c) % MOD;
                tmp.a %= MOD;
                tmp.b += (first.c * second.d) % MOD;
                tmp.b %= MOD;

                tmp.d += (first.d * second.a) % MOD;
                tmp.d %= MOD;
                tmp.c += (first.d * second.b) % MOD;
                tmp.c %= MOD;
                tmp.b += (first.d * second.c) % MOD;
                tmp.b %= MOD;
                tmp.a += (first.d * second.d) % MOD;
                tmp.a %= MOD;
            }
            stck.push(tmp);
        } else {
            struct store tmp;
            tmp.a = 0, tmp.b = 0, tmp.c = 0, tmp.d = 0, tmp.ch = st[i];
            stck.push(tmp);
        }
    }

    struct store tmp = stck.top();
    lli total = ((tmp.a + tmp.b) % MOD + (tmp.c + tmp.d) % MOD) % MOD;
    total = power(total, MOD - 2);
    lli a = (tmp.a * total) % MOD;
    lli b = (tmp.b * total) % MOD;
    lli c = (tmp.c * total) % MOD;
    lli d = (tmp.d * total) % MOD;
    cout << a << " " << b << " " << c << " " << d << endl;
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