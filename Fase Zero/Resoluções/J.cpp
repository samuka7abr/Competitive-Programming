#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> st;
    SegTree(int _n): n(_n), st(4*n, LLONG_MAX) {}
    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) st[p] = a[l];
        else {
            int m = (l + r) >> 1;
            build(p<<1, l, m, a);
            build(p<<1|1, m+1, r, a);
            st[p] = min(st[p<<1], st[p<<1|1]);
        }
    }
    int find_first(int p, int l, int r, int i, int j, ll v) {
        if (r < i || l > j || st[p] >= v) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_first(p<<1, l, m, i, j, v);
        return res != -1 ? res : find_first(p<<1|1, m+1, r, i, j, v);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; ll K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int M = 2 * N;
    vector<ll> D(M);
    for (int i = 0; i < M; i++)
        D[i] = A[i % N] - (ll)i * K;

    SegTree st(M);
    st.build(1, 0, M-1, D);

    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        ll Ei = A[i] - (ll)i * K;
        int t = st.find_first(1, 0, M-1, i+1, i+N, Ei);
        B[i] = (t % N) + 1;
    }
    for (int i = 0; i < N; i++)
        cout << B[i] << (i+1<N ? ' ' : '\n');
    return 0;
}
