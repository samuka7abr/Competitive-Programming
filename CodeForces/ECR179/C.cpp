#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;

int main() {
    otim;
    int T;
    cin >> T;

    unordered_map<int, vector<int>> pos;
    vector<int> valores;
    valores.reserve(500000);

    while (T--) {
        int n;
        cin >> n;

        valores.clear();
        pos.clear();

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (pos[x].empty()) {
                valores.pb(x);
            }
            pos[x].pb(i);
        }

        ll res = LLONG_MAX;
        if ((int)valores.size() == 1 && (int)pos[valores[0]].size() == n) {
            res = 0;
        }
        else {
            for (int v : valores) {
                auto &ps = pos[v];
                int k = (int)ps.size();

                if (k == n) {
                    res = 0;
                    break;
                }

                vector<int> sentinelas(k + 2);
                sentinelas[0] = 0;
                for (int i = 0; i < k; i++) {
                    sentinelas[i + 1] = ps[i];
                }
                sentinelas[k + 1] = n + 1;

                vector<bool> temG(k + 2, false);
                for (int r = 1; r <= k + 1; r++) {
                    if (sentinelas[r] - sentinelas[r - 1] > 1) {
                        temG[r] = true;
                    }
                }

                vector<int> proxGap(k + 2, -1);
                proxGap[k + 1] = -1; 
                for (int u = k; u >= 0; u--) {
                    if (temG[u + 1]) {
                        proxGap[u] = u + 1;
                    } else {
                        proxGap[u] = proxGap[u + 1];
                    }
                }

                ll melhorSum = LLONG_MAX;

                for (int i = 1; i <= k; i++) {
                    int limit = sentinelas[i] + 1;
                    int it_idx = int(upper_bound(sentinelas.begin(), sentinelas.end(), limit) - sentinelas.begin());
                    int ubIdx = it_idx - 1; 

                    int rStart = proxGap[ubIdx];
                    if (rStart == -1) {
                        ll cost_here = (ll)(sentinelas[i] - 1);
                        melhorSum = min(melhorSum, cost_here);
                    }
                    else {
                        int limRight = sentinelas[rStart - 1] + 1;
                        int it2 = int(upper_bound(sentinelas.begin(), sentinelas.begin() + (k + 1), limRight) - sentinelas.begin());
                        int jIdx = it2 - 1;
                        if (jIdx >= 1 && jIdx <= k) {
                            ll cost_here = (ll)(sentinelas[i] - 1) + (ll)(n - sentinelas[jIdx]);
                            melhorSum = min(melhorSum, cost_here);
                        }
                    }
                }

                if (sentinelas[1] == 1) {
                    melhorSum = min(melhorSum, (ll)(n - 1));
                }

                if (melhorSum < LLONG_MAX) {
                    ll totalCost = melhorSum * (ll)v;
                    res = min(res, totalCost);
                }
            }
        }

        if (res == LLONG_MAX){
            res = 0;
        }
        cout << res << "\n";

    }

    return 0;
}
