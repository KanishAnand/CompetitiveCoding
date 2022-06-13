#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

typedef struct qry {
    int ind, l, r, block;
    int flag, lc, ans;
} qry;

const int MOD = 1e9 + 7;
const int logn = 18;
const int fixedSize = 100005;

int inverseMod[2000008];
int add(int ans, int ind);

int tim = 1, level = 0, tt = 0;

int start_index[fixedSize], finish_index[fixedSize], hght[fixedSize],
    v[fixedSize], vis[100005];
bool check[100005];

vector<vector<pair<int, int>>> storeFactors(1e6 + 2);
vector<int> arr;
vector<struct qry> query;
vector<vector<int>> adj, dp;
int factorCnt[1000000];

bool compare(struct qry &a, struct qry &b) {
    if (a.block != b.block) {
        return a.block < b.block;
    } else {
        if (a.block & 1) {
            return a.r < b.r;
        } else {
            return a.r > b.r;
        }
    }
}

int power(int x, int y) {
    int ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans = (1ll * ans * x) % MOD;
        }
        y = y >> 1;
        x = (1ll * x * x) % MOD;
    }
    return ans;
}

void dfs(int a) {
    for (int i = 0; i < adj[a].size(); i++) {
        int val = adj[a][i];
        if (vis[val] != tt) {
            vis[val] = tt;
            tim++;
            arr.push_back(val);
            start_index[val] = sz(arr) - 1;

            dp[val][0] = a;
            for (int j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }

            ++level;
            hght[val] = level;
            dfs(val);
            --level;
            arr.push_back(val);
            finish_index[val] = sz(arr) - 1;
            tim++;
        }
    }
    return;
}

int lca(int a, int b) {
    if (hght[a] != hght[b]) {
        if (hght[a] < hght[b]) {
            int oa = a;
            a = b;
            b = oa;
        }

        for (int i = logn; i >= 0; i--) {
            if (dp[a][i] == 0) {
                continue;
            }
            int val = dp[a][i];
            if (hght[val] >= hght[b]) {
                a = val;
            }
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = logn; i >= 0; i--) {
        if (dp[a][i] == 0 || dp[b][i] == 0) {
            continue;
        }
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int rmve(int ans, int ind) {
    int node = arr[ind];
    int val = v[node];

    for (int i = 0; i < storeFactors[val].size(); i++) {
        int factor = storeFactors[val][i].first;
        int cnt = storeFactors[val][i].second;
        ans = (1ll * ans * inverseMod[factorCnt[factor] + 1]) % MOD;
        factorCnt[factor] -= cnt;
        ans = (1ll * ans * (factorCnt[factor] + 1)) % MOD;
    }

    return ans;
}

int add(int ans, int ind) {
    int node = arr[ind];
    int val = v[node];

    for (int i = 0; i < storeFactors[val].size(); i++) {
        int factor = storeFactors[val][i].first;
        int cnt = storeFactors[val][i].second;
        ans = (1ll * ans * inverseMod[factorCnt[factor] + 1]) % MOD;
        factorCnt[factor] += cnt;
        ans = (1ll * ans * (factorCnt[factor] + 1)) % MOD;
    }

    return ans;
}

int checkFun(int ans, int ind) {
    if (check[arr[ind]]) {
        check[arr[ind]] ^= 1;
        return rmve(ans, ind);
    } else {
        check[arr[ind]] ^= 1;
        return add(ans, ind);
    }
}

void compute() {
    int curL = query[0].l, curR = query[0].l - 1, ans = 1;

    for (int i = 0; i < query.size(); i++) {
        auto &qr = query[i];
        while (curL < qr.l) {
            ans = checkFun(ans, curL);
            curL++;
        }
        while (curL > qr.l) {
            curL--;
            ans = checkFun(ans, curL);
        }
        while (curR < qr.r) {
            curR++;
            ans = checkFun(ans, curR);
        }
        while (curR > qr.r) {
            ans = checkFun(ans, curR);
            curR--;
        }

        qr.ans = ans;

        if (qr.flag) {
            ans = checkFun(ans, start_index[qr.lc]);
            qr.ans = ans;
            ans = checkFun(ans, start_index[qr.lc]);
        }
    }
    return;
}

void solve() {
    int n, a, q, b;
    cin >> n;

    memset(check, 0, sizeof(check));
    memset(factorCnt, 0, sizeof(factorCnt));

    arr.clear();
    query.clear();

    dp.clear();
    adj.clear();

    dp.resize(n + 2, vector<int>(logn + 2, 0));
    adj.resize(n + 2);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    level = 0;
    tim = 1;
    vis[1] = tt;
    arr.push_back(1);
    start_index[1] = sz(arr) - 1;
    dfs(1);
    arr.push_back(1);
    finish_index[1] = sz(arr) - 1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v[i + 1] = a;
    }

    int blocksize = sqrt(sz(arr));

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        struct qry qr;

        if (start_index[a] > start_index[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        int lc = lca(a, b);

        if (lc == a) {
            qr.l = start_index[a];
            qr.r = start_index[b];
            qr.flag = 0;
        } else {
            qr.l = finish_index[a];
            qr.r = start_index[b];
            qr.flag = 1;
        }

        qr.lc = lc;
        qr.ind = i;
        qr.ans = 0;
        qr.block = qr.l / blocksize;
        query.push_back(qr);
    }

    sort(query.begin(), query.begin() + q, compare);

    compute();
    vector<int> printAns(q);

    for (int i = 0; i < query.size(); i++) {
        printAns[query[i].ind] = query[i].ans;
    }

    for (int i = 0; i < q; i++) {
        cout << printAns[i] << '\n';
    }

    return;
}

void storefactors() {
    for (int nmbr = 2; nmbr <= 1e6 + 1; nmbr++) {
        int no = nmbr;
        for (int i = 2; i <= sqrt(no); i++) {
            if (no % i != 0) {
                continue;
            }
            int cnt = 0;
            while (no % i == 0) {
                cnt++;
                no /= i;
            }
            storeFactors[nmbr].push_back({i, cnt});
            if (no == 1) {
                break;
            }
        }

        if (no != 1) {
            storeFactors[nmbr].push_back({no, 1});
        }
    }

    return;
}

void inverseModfunc() {
    int no = 2 * 1e6 + 2;
    for (int i = 1; i <= no; i++) {
        inverseMod[i] = power(i, MOD - 2);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    storefactors();
    inverseModfunc();
    int t;
    cin >> t;
    while (t--) {
        tt++;
        solve();
    }
    return 0;
}