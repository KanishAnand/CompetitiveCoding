/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 10, inf = 1e9 + 42, LOG = log2(inf) + 2;

struct shop {
    ll a, b;
    bool operator<(const shop& o) const {
        if (a == 1 and o.a == 1) {
            return b < o.b;
        } else {
            return b * (o.a - 1) < o.b * (a - 1);
        }
    }
};

int main() {
    fast_cin();
    int n;
    ll T;
    cin >> n >> T;
    ++T;
    vector<shop> s(n);
    for (auto& i : s) {
        cin >> i.a >> i.b;
        ++i.a;
        ++i.b;
    }
    sort(s.begin(), s.end());
    int bak_n = n;
    while (n > 0 and s[n - 1].a == 1) {
        --n;
    }
    vector<ll> dp(LOG + 1, inf);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = LOG - 1; j >= 0; --j) {
            dp[j + 1] = min(dp[j + 1], s[i].a * dp[j] + s[i].b);
        }
    }
    ll ans = 0;
    for (int j = 0; j < LOG; ++j) {
        if (dp[j] > T) {
            continue;
        }
        ll cand = j, t = dp[j];
        for (int i = n; i < bak_n; ++i) {
            if (t + s[i].b <= T) {
                ++cand;
                t += s[i].b;
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
}
