#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<lli, null_type, less<lli>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of lli
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

string st;
vector<char> v = {'A', 'N', 'T', 'O'};

lli fun(vector<lli> &start, vector<lli> &tmp) {
    lli val = 0, ind;
    for (lli i = 0; i < len(st); i++) {
        if (st[i] == 'A') {
            ind = 0;
            val += abs(i - start[0]);
            start[0]++;
        } else if (st[i] == 'N') {
            ind = 1;
            val += abs(i - start[1]);
            start[1]++;
        } else if (st[i] == 'T') {
            ind = 2;
            val += abs(i - start[2]);
            start[2]++;
        } else {
            ind = 3;
            val += abs(i - start[3]);
            start[3]++;
        }

        if (tmp[3] == ind) {
            start[tmp[0]]++;
            start[tmp[1]]++;
            start[tmp[2]]++;
        } else if (tmp[2] == ind) {
            start[tmp[0]]++;
            start[tmp[1]]++;
        } else if (tmp[1] == ind) {
            start[tmp[0]]++;
        }
    }
    return val;
}

void solve() {
    cin >> st;

    map<char, lli> mp;
    for (lli i = 0; i < len(st); i++) {
        mp[st[i]]++;
    }

    lli no = 4, mx = -1;
    string ans = st;

    for (lli i = 0; i < no; i++) {
        for (lli j = 0; j < no; j++) {
            if (i == j) {
                continue;
            }
            for (lli k = 0; k < no; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (lli l = 0; l < no; l++) {
                    if (l == k || l == i || l == j) {
                        continue;
                    }
                    // set<lli> stt;
                    // stt.insert(i);
                    // stt.insert(j);
                    // stt.insert(k);
                    // stt.insert(l);
                    // if (sz(stt) != 4) {
                    //     continue;
                    // }

                    string check = "";
                    for (lli tmp = 0; tmp < mp[v[i]]; tmp++) {
                        check += v[i];
                    }
                    for (lli tmp = 0; tmp < mp[v[j]]; tmp++) {
                        check += v[j];
                    }
                    for (lli tmp = 0; tmp < mp[v[k]]; tmp++) {
                        check += v[k];
                    }
                    for (lli tmp = 0; tmp < mp[v[l]]; tmp++) {
                        check += v[l];
                    }

                    vector<lli> start(4);
                    start[i] = 0;
                    start[j] = mp[v[i]];
                    start[k] = mp[v[i]] + mp[v[j]];
                    start[l] = mp[v[i]] + mp[v[j]] + mp[v[k]];

                    vector<lli> tmp = {i, j, k, l};
                    lli val = fun(start, tmp);
                    if (val > mx) {
                        mx = val;
                        ans = check;
                    }
                }
            }
        }
    }

    // cout << mx << endl;
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
    return 0;
}