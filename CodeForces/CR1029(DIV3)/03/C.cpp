#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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
        vector<int> a(n+1);
        vector<int> prox(n+2);
        vector<int> ult(n+2);
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        int LIMITE = n + 1;
        for (int i = 1; i <= n; i++) {
            ult[i] = LIMITE;
        }
        
        for (int i = n; i >= 1; i--) {
            prox[i] = ult[a[i]];
            ult[a[i]] = i;
        }
        
        int pos = 1;
        int count = 0;
        
        while (pos <= n) {
            int fimSeg = pos;
            while (true) {
                int novoFim = 0;
                
                for (int i = pos; i <= fimSeg; i++) {
                    if (prox[i] > novoFim) {
                        novoFim = prox[i];
                    }
                }
                
                count++;
                
                if (novoFim > n) {
                    break;
                }
                
                pos = fimSeg + 1;
                fimSeg = novoFim;
            }
            break;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
