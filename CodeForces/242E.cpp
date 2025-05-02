#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100000;
int n, m;
vector<array<int,20>> cnt;
vector<int> lazy;

void build(int id, int l, int r, const vector<int>& a) {
    lazy[id] = 0;
    if (l == r) {
        for (int b = 0; b < 20; ++b)
            cnt[id][b] = (a[l] >> b) & 1;
    } else {
        int mid = (l + r) >> 1;
        build(id<<1, l, mid, a);
        build(id<<1|1, mid+1, r, a);
        for (int b = 0; b < 20; ++b)
            cnt[id][b] = cnt[id<<1][b] + cnt[id<<1|1][b];
    }
}

void apply_xor(int id, int l, int r, int x) {
    int len = r - l + 1;
    for (int b = 0; b < 20; ++b) {
        if ((x >> b) & 1)
            cnt[id][b] = len - cnt[id][b];
    }
    lazy[id] ^= x;
}

void push(int id, int l, int r) {
    if (!lazy[id]) return;
    int mid = (l + r) >> 1;
    apply_xor(id<<1,   l,   mid, lazy[id]);
    apply_xor(id<<1|1, mid+1, r, lazy[id]);
    lazy[id] = 0;
}

void update(int id, int l, int r, int ql, int qr, int x) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        apply_xor(id, l, r, x);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update(id<<1,   l,   mid, ql, qr, x);
    update(id<<1|1, mid+1, r, ql, qr, x);
    for (int b = 0; b < 20; ++b)
        cnt[id][b] = cnt[id<<1][b] + cnt[id<<1|1][b];
}

ll query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
        ll s = 0;
        for (int b = 0; b < 20; ++b)
            s += ll(cnt[id][b]) << b;
        return s;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    return query(id<<1, l, mid, ql, qr)
         + query(id<<1|1, mid+1, r, ql, qr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    cnt.assign(4*(n+1), array<int,20>());
    lazy.assign(4*(n+1), 0);
    build(1, 1, n, a);

    cin >> m;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << query(1,1,n,l,r) << "\n";
        } else {
            int x;
            cin >> x;
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}
