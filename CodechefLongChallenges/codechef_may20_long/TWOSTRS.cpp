#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

lli b[30];

int kmp(string str, string substr);
void kmpPreprocess(string substr) {
    int m = substr.length();
    int i = 0, j = -1;

    b[i] = -1;
    while (i < m) {
        while (j >= 0 && substr[i] != substr[j])
            j = b[j];

        i++;
        j++;
        b[i] = j;
    }
}

int kmp(string str, string substr) {
    int i = 0, j = 0, count = 0;
    int n = str.length();
    int m = substr.length();
    kmpPreprocess(substr);
    while (i < n) {
        while (j >= 0 && str[i] != substr[j])
            j = b[j];

        i++;
        j++;

        if (j == m) {
            count++;
            j = b[j];
        }
    }
    return count;
}

void solve() {
    lli n, mx = -1, val;
    string a, b, st;
    vector<string> store;
    vector<lli> no;
    cin >> a >> b;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        cin >> val;
        store.pb(st);
        no.pb(val);
    }

    vector<string> data, dataa, datab;
    vector<lli> store_ans;
    string a1 = "";

    for (lli i = 0; i <= a.length(); i++) {
        if (i > 0) {
            a1 += a[i - 1];
        }

        lli val = 0;
        for (lli j = 0; j < n; j++) {
            if (store[j].length() > a1.length()) {
                continue;
            }
            lli p = kmp(a1, store[j]);
            val += p * no[j];
        }

        string rev_a = "";
        lli cnt = 0;

        for (lli j = a1.length() - 1; j >= 0; j--) {
            if (cnt == 26) {
                break;
            }
            rev_a += a1[j];
            cnt++;
        }

        reverse(all(rev_a));

        string b1 = b;
        reverse(all(b1));
        for (lli j = 0; j <= b.length(); j++) {
            lli val1 = 0;
            if (j > 0) {
                b1.pop_back();
            }
            string c1 = b1;
            reverse(all(c1));
            string rev_b = "";
            lli len = c1.length();

            for (lli pp = 0; pp < min((lli)26, len); pp++) {
                rev_b += c1[pp];
            }

            for (lli pp = 0; pp < n; pp++) {
                if (store[pp].length() > c1.length()) {
                    continue;
                }
                lli p = kmp(c1, store[pp]);
                val1 += p * no[pp];
            }

            string ch = rev_a + rev_b;
            // cout << ch << endl;
            data.pb(ch);
            dataa.pb(rev_a);
            datab.pb(rev_b);
            store_ans.pb(val + val1);
        }
    }

    for (lli i = 0; i < data.size(); i++) {
        string ch = data[i];
        string ch1 = dataa[i];
        string ch2 = datab[i];
        lli ans = store_ans[i];
        lli vv = 0, val, p;
        // cout << ch << endl;
        for (lli k = 0; k < n; k++) {
            if (store[k].length() <= ch.length()) {
                // continue;
                val = kmp(ch, store[k]);
                vv += val * no[k];
                p = val * no[k];
            }

            // if (ch == "hitechechef") {
            //     cout << ans << endl;
            //     cout << vv << " " << p << " " << k << endl;
            // }

            if (store[k].length() <= ch1.length()) {
                // continue;
                val = kmp(ch1, store[k]);
                vv -= val * no[k];
                p = val * no[k];
            }

            // if (ch == "hitechechef") {
            //     cout << vv << " " << p << " " << k << endl;
            // }

            if (store[k].length() <= ch2.length()) {
                // continue;
                val = kmp(ch2, store[k]);
                vv -= val * no[k];
                p = val * no[k];
            }
            // if (ch == "hitechechef") {
            //     cout << ch2 << endl;
            //     cout << vv << " " << p << " " << k << endl;
            // }
        }
        ans += vv;
        mx = max(mx, ans);
    }

    cout << mx << endl;
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