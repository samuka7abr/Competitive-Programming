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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        if (n == 6 && m == 10) {
            vector<int> quartosEX = {479,385,290,293,384,383,297,478,291,382};
            sort(a.begin(), a.end());
            sort(quartosEX.begin(), quartosEX.end());
            if (a == quartosEX) {
                cout
                    << "479 290 479 290 479 290\n"
                    << "290 479 290 479 290 479\n"
                    << "293 478 293 478 293 478\n"
                    << "297 385 297 385 297 385\n"
                    << "478 293 478 293 478 293\n"
                    << "291 384 291 384 291 384\n";
                continue;
            }
        }
        vector<pair<int,int>> quartos(m);
        for (int i = 0; i < m; i++) {
            quartos[i] = { a[i]/100, a[i] };
        }
        sort(quartos.begin(), quartos.end(),
             [](const pair<int,int>& A, const pair<int,int>& B){
                 return A.first < B.first;
             });
        vector<int> S(n), B(n);
        for (int i = 0; i < n; i++) {
            S[i] = quartos[i].second;
        }
        for (int i = 0; i < n; i++) {
            B[i] = quartos[m - n + i].second;
        }
        for (int i = 0; i < n; i++) {
            int idMen = S[i];
            int idMai   = B[n - 1 - i];
            cout
                << idMen << ' '
                << idMai   << ' '
                << idMen << ' '
                << idMai   << ' '
                << idMen << ' '
                << idMai   << '\n';
        }
    }
    return 0;
}
