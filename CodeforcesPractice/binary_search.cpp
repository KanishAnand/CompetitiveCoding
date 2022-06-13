ll b = 0, e = n - 1, ans = 1e15;

while (b <= e) {
    ll m = (b + e) / 2;
    if (check(m)) {
        ans = min(ans, m);
        // ans = max(ans,m);
        e = m - 1;
    } else {
        b = m + 1;
    }
}