#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())

lli check(string st, vector<vector<lli>> &palindrome) {
    lli n = len(st);

    for (lli mid = 0; mid < n; mid++) {
        lli beg = mid - 1, end = mid + 1;
        while (beg < end && beg >= 0 && end < n) {
            if (st[beg] == 'a' && st[end] == 'a') {
                if (palindrome[beg + 1][end - 1] != palindrome[beg][end]) {
                    return 0;
                }
            }
            beg--;
            end++;
        }

        beg = mid, end = mid + 1;
        while (beg < end && beg >= 0 && end < n) {
            if (st[beg] == 'a' && st[end] == 'a') {
                if (end - beg == 1 && palindrome[beg][end] == 0) {
                    return 0;
                }
                if (palindrome[beg + 1][end - 1] != palindrome[beg][end]) {
                    return 0;
                }
            }
            beg--;
            end++;
        }
    }

    return 1;
}

void solve() {
    string st;
    cin >> st;
    lli n = len(st);

    vector<vector<lli>> palindrome(n + 2, vector<lli>(n + 2, 0));
    for (lli i = 0; i < n; i++) {
        for (lli j = i; j < n; j++) {
            lli beg = i, end = j, flag = 1;
            while (beg < end) {
                if (st[beg] != st[end]) {
                    flag = 0;
                    break;
                }
                beg++;
                end--;
            }
            palindrome[i][j] = flag;
            palindrome[j][i] = flag;
        }
    }

    lli ans = 0;
    for (lli mask = 0; mask < pow(2, n); mask++) {
        lli tmp = mask, ind = 0;

        string tmp_st = "";
        vector<lli> vis(n + 2, 0);
        queue<lli> qu;

        while (tmp > 0) {
            if (tmp % 2 == 1) {
                tmp_st += 'a';
                vis[ind] = 1;
                qu.push(ind);
            } else {
                tmp_st += '?';
            }
            ind++;
            tmp /= 2;
        }

        while (len(tmp_st) != n) {
            tmp_st += '?';
        }

        while (!qu.empty()) {
            lli a = qu.front();
            tmp_st[a] = 'a';
            qu.pop();
            for (lli i = 0; i < n; i++) {
                lli mn = min(i, a);
                lli mx = max(i, a);
                if (palindrome[mn][mx] == 1 && vis[i] == 0) {
                    vis[i] = 1;
                    qu.push(i);
                }
            }
        }

        lli flag = check(tmp_st, palindrome);
        if (flag == 1) {
            ans++;
        }
    }

    cout << ans << endln;
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