#include <bits/stdc++.h>
using namespace std;
#define lli int
#define pb push_back
#define rt return 0
#define endln "\n"
#define sz(x) (lli)(x.size())

typedef struct qry {
    lli ind, l, r, block, ans, val;
} qry;

vector<struct qry> q;
vector<lli> v;
set<pair<lli, lli>> st;
bool check[100005];

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

void rmve(lli ind) {
    st.erase({v[ind], ind});
}

void add(lli ind) {
    st.insert({v[ind], ind});
}

void compute() {
    lli curL = q[0].l, curR = q[0].l - 1;

    for (lli i = 0; i < q.size(); i++) {
        auto &qr = q[i];
        while (curR < qr.r) {
            curR++;
            add(curR);
        }
        while (curR > qr.r) {
            rmve(curR);
            curR--;
        }
        while (curL < qr.l) {
            rmve(curL);
            curL++;
        }
        while (curL > qr.l) {
            curL--;
            add(curL);
        }

        lli val = qr.val;
        auto it = st.begin();
        auto it2 = st.end();
        it2--;
        lli ans = -1;
        if (it->first != val) {
            ans = it->second + 1;
        } else if (it2->first != val) {
            ans = it2->second + 1;
        }
        qr.ans = ans;
    }
    return;
}

void solve() {
    lli n, a, m, l, r, x;
    cin >> n >> m;
    memset(check, 0, sizeof(check));
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli blocksize = sqrt(sz(v)) * 2;

    for (lli i = 0; i < m; i++) {
        struct qry p;
        cin >> p.l >> p.r >> p.val;
        p.l--;
        p.r--;
        p.ind = i;
        p.ans = -1;
        p.block = p.l / blocksize;
        q.pb(p);
    }

    sort(q.begin(), q.end(), compare);
    compute();

    vector<lli> printAns(m + 2);

    for (int i = 0; i < q.size(); i++) {
        printAns[q[i].ind] = q[i].ans;
    }

    for (int i = 0; i < q.size(); i++) {
        cout << printAns[i] << '\n';
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