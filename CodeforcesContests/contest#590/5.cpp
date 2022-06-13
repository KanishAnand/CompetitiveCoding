#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
char arr[200000];
char seg[800000];

int merge(int i, char val, int pos, int l, int r);

int update(int i, char val, int pos, int l, int r) {
    merge(i, val, pos, l, r);
    return 0;
}

int merge(int i, char val, int pos, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        if (l == i) {
            arr[l] = val;
            seg[pos] = val;
        }
        return seg[pos];
    }
    int mid = (l + r) / 2;
    if (i <= mid) {
        merge(i, val, 2 * pos + 1, l, mid);
        seg[pos] = merge(i, val, 2 * pos + 1, l, mid) + seg[2 * pos + 2];
    } else {
        merge(i, val, 2 * pos + 2, mid + 1, r);
        seg[pos] = seg[2 * pos + 1] + merge(i, val, 2 * pos + 2, mid + 1, r);
    }

    return seg[pos];
}

int min(int a, int b) {
    return a < b ? a : b;
}

char query(int pos, int l, int r, int lo, int hi, set<char> &st) {
    if (r < lo || l > hi) {
        return '0';
    } else if (l <= lo && r >= hi) {
        return seg[pos];
    } else {
        int mid = (lo + hi) / 2;
        char a = query(2 * pos + 1, l, r, lo, mid, st);
        if (a != '0') {
            st.insert(a);
        }
        a = query(2 * pos + 2, l, r, mid + 1, hi, st);
        if (a != '0') {
            st.insert(a);
        }
        // return query(2 * pos + 1, l, r, lo, mid, st) +
        //        query(2 * pos + 2, l, r, mid + 1, hi, st);
    }
}

int build(int pos, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (l == r) {
        seg[pos] = arr[l];
        return seg[pos];
    }

    else {
        int mid = (l + r) / 2;
        seg[pos] = build(2 * pos + 1, l, mid) + build(2 * pos + 2, mid + 1, r);
    }
    return seg[pos];
}

int main(void) {
    int n, q;
    string st;
    cin >> st;
    scanf("%d", &q);
    n = st.length();
    for (int i = 0; i < n; i++) {
        arr[i] = st[i];
    }

    build(0, 0, n - 1);
    // for (int i = 0; i < 4 * n; i++) {
    //     printf("%d ", seg[i]);
    // }
    int l, r, i, val;
    int a, pos;
    char ch;
    // scanf("%d%d",&l,&r);
    // int pos=0;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> pos >> ch;
            update(pos - 1, ch, 0, 0, n - 1);
            // cout << arr << endl;
        } else {
            int b, c;
            cin >> b >> c;
            set<char> st;
            query(0, b - 1, c - 1, 0, n - 1, st);
            cout << st.size() << endl;
        }
    }

    // printf("%d\n", query(pos, l, r, 0, n - 1));
    // scanf("%d%d", &i, &val);
    // update(i, val, 0, 0, n - 1);
    // for (int i = 0; i < 4 * n; i++) {
    //     printf("%d ", seg[i]);
    // }
    return 0;
}