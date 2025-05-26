#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void constroiOrdem(int raiz, const vector<vector<int>>& adjacente, vector<int>& pai, vector<int>& order) {
    queue<int> q;
    q.push(raiz);
    pai[raiz] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adjacente[u]) {
            if (v == pai[u]) continue;
            pai[v] = u;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        vector<vector<int>> adjacente(N + 1);
        for (int i = 0; i < N - 1; i++) {
            int u,v;
            cin >> u >> v;
            adjacente[u].push_back(v);
            adjacente[v].push_back(u);
        }

        vector<int> pai(N + 1), order;
        order.reserve(N );
        constroiOrdem(1, adjacente, pai, order);

        vector<ll> f(N +1), g(N + 1);

        for (int u : order) {
            if (u == 1) {
                f[u] =  a[u];
                g[u] = -a[u];
            } else {
                int pai1  = pai[u];
                int avo = pai[pai1];

                ll melhorFAvo = 0;
                if (avo != 0) {
                    melhorFAvo = max(0LL, f[avo]);
                }
                ll o1 =  a[u];
                ll o2 =  a[u] - a[pai1];
                ll o3 =  a[u] - a[pai1] + melhorFAvo;
                f[u] = max(o1, max(o2, o3));

                ll melhorGAvo = 0;
                if (avo != 0) {
                    melhorGAvo = max(0LL, g[avo]);
                }
                ll p1 = -a[u];
                ll p2 = -a[u] + a[pai1];
                ll p3 = -a[u] + a[pai1] + melhorGAvo;
                g[u] = max(p1, max(p2, p3));
            }
        }

        for (int i = 1; i <= N; i++) {
            cout << f[i];
            if(i < N){
                cout << ' ';
            }else{
                cout << '\n';
            }
        }
    }

    return 0;
}
