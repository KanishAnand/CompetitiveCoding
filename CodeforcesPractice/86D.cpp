#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

typedef struct qry {
    lli ind, l, r, block, ans;
} qry;

vector<struct qry> query;
vector<lli> v, cnt(1e6 + 5, 0), check(200005, 0);

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

lli rmve(lli ans, lli ind) {
    lli val = v[ind];
    ans -= val * cnt[val] * cnt[val];
    cnt[val]--;
    ans += val * cnt[val] * cnt[val];
    return ans;
}

lli add(lli ans, lli ind) {
    lli val = v[ind];
    ans -= val * cnt[val] * cnt[val];
    cnt[val]++;
    ans += val * cnt[val] * cnt[val];
    return ans;
}

void compute() {
    lli curL = query[0].l, curR = query[0].l - 1;
    lli ans = 0;

    for (lli i = 0; i < query.size(); i++) {
        auto &qr = query[i];
        while (curL < qr.l) {
            ans = rmve(ans, curL);
            curL++;
        }
        while (curL > qr.l) {
            curL--;
            ans = add(ans, curL);
        }
        while (curR < qr.r) {
            curR++;
            ans = add(ans, curR);
        }
        while (curR > qr.r) {
            ans = rmve(ans, curR);
            curR--;
        }

        qr.ans = ans;
    }
    return;
}

void solve() {
    lli n, a, q, b;
    cin >> n >> q;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli blocksize = sqrt(sz(v));

    for (lli i = 0; i < q; i++) {
        cin >> a >> b;
        struct qry qr;

        qr.l = a - 1;
        qr.r = b - 1;
        qr.ind = i;
        qr.ans = 0;
        qr.block = qr.l / blocksize;
        query.push_back(qr);
    }

    sort(query.begin(), query.end(), compare);

    compute();
    vector<lli> printAns(q);

    for (int i = 0; i < query.size(); i++) {
        printAns[query[i].ind] = query[i].ans;
    }

    for (int i = 0; i < q; i++) {
        cout << printAns[i] << '\n';
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}