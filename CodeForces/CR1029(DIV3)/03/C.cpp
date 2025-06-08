#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18;  
const double PI = acos(-1.0);

int main() {
    otim;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> suf(n + 1, 0);
        for (int x : a) suf[x]++;

        vector<bool> vis(n + 1, false);
        unordered_set<int> req;
        vector<int> cur;
        cur.reserve(n);

        int f = 0, nf = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            suf[x]--;
            if (req.count(x)) {
                req.erase(x);
            }
            if (!vis[x]) {
                vis[x] = true;
                cur.pb(x);
                if (suf[x] > 0) f++;
                else nf++;
            }
            if (req.empty() && nf == 0) {
                res++;
                for (int y : cur) req.insert(y);
                for (int y : cur) vis[y] = false;
                cur.clear();
                f = nf = 0;
            }
        }
        if (!cur.empty()) res++;
        cout << res << '\n';
    }
    return 0;
}
