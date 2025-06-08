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

int main(){
    otim;
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> A(n+2), B(n+2);
        for(int i=1;i<=n;i++){
            cin >> A[i];
        }
        for(int i=1;i<=n;i++){
            cin >> B[i];
        }

        vector<vector<int>> posA(n+1), posB(n+1);
        for(int i=1;i<=n;i++){
            posA[A[i]].pb(i);
        }
        for(int i=1;i<=n;i++){
            posB[B[i]].pb(i);
        }

        int INF = n+1;
        vector<int> proxA(n+2, INF), proxB(n+2, INF);
        for(int i=1;i<=n;i++){
            auto &v = posA[B[i]];
            auto it = upper_bound(v.begin(), v.end(), i);
            if(it != v.end()){
                proxA[i] = *it;
            }
            auto &w = posB[A[i]];
            it = upper_bound(w.begin(), w.end(), i);
            if(it != w.end()){
                proxB[i] = *it;
            }
        }

        vector<char> g0(n+2, 0);
        vector<int> dp0(n+3, 0);
        for(int i=n;i>=1;i--){
            bool igual = false;
            if(A[i] == B[i]){
                igual = true;
            }
            bool repeteB = false;
            if(i < n){
                if(B[i] == B[i+1]){
                    repeteB = true;
                }
            }
            if(proxA[i] <= n){
                if(proxA[i] >= i+2){
                    repeteB = true;
                }
            }
            bool repeteA = false;
            if(i < n){
                if(A[i] == A[i+1]){
                    repeteA = true;
                }
            }
            if(proxB[i] <= n){
                if(proxB[i] >= i+2){
                    repeteA = true;
                }
            }
            bool proxG0 = false;
            if(g0[i+1]){
                proxG0 = true;
            }
            if(igual || repeteB || repeteA || proxG0){
                g0[i] = 1;
            } else {
                g0[i] = 0;
            }
            if(g0[i]){
                dp0[i] = dp0[i+1] + 1;
            } else {
                dp0[i] = dp0[i+1];
            }
        }
        int res = dp0[1];

        vector<int> preIG(n+1, 0);
        for(int i=1;i<=n;i++){
            if(A[i] == B[i]){
                preIG[i] = i;
            } else {
                preIG[i] = preIG[i-1];
            }
        }
        vector<int> L1(n+2, 0), L2(n+2, 0), L4(n+2, 0);
        vector<int> ultimoB(n+1, 0), ultimoA(n+1, 0);
        for(int k=1;k<=n;k++){
            L1[k] = preIG[k-1];
            if(k+1 <= n){
                L2[k] = ultimoB[B[k+1]];
            } else {
                L2[k] = 0;
            }
            if(k+1 <= n){
                L4[k] = ultimoA[A[k+1]];
            } else {
                L4[k] = 0;
            }
            ultimoB[B[k]] = k;
            ultimoA[A[k]] = k;
        }

        vector<vector<int>> add3(n+2), rem3(n+2), add5(n+2), rem5(n+2);
        for(int j=1;j<=n;j++){
            if(proxA[j] <= n){
                if(proxA[j] >= j+3){
                    int ini = j+1;
                    int fim = proxA[j]-2;
                    add3[ini].pb(j);
                    rem3[fim+1].pb(j);
                }
            }
            if(proxB[j] <= n){
                if(proxB[j] >= j+3){
                    int ini = j+1;
                    int fim = proxB[j]-2;
                    add5[ini].pb(j);
                    rem5[fim+1].pb(j);
                }
            }
        }

        multiset<int> ativos3, ativos5;
        for(int k=1;k<=n;k++){
            for(int x : rem3[k]){
                auto it = ativos3.find(x);
                if(it != ativos3.end()){
                    ativos3.erase(it);
                }
            }
            for(int x : add3[k]){
                ativos3.insert(x);
            }
            for(int x : rem5[k]){
                auto it = ativos5.find(x);
                if(it != ativos5.end()){
                    ativos5.erase(it);
                }
            }
            for(int x : add5[k]){
                ativos5.insert(x);
            }

            int L3 = 0;
            if(!ativos3.empty()){
                L3 = *prev(ativos3.end());
            }
            int L5 = 0;
            if(!ativos5.empty()){
                L5 = *prev(ativos5.end());
            }

            int suf = dp0[k+1];
            int melhor = L1[k];
            if(L2[k] > melhor){
                melhor = L2[k];
            }
            if(L3 > melhor){
                melhor = L3;
            }
            if(L4[k] > melhor){
                melhor = L4[k];
            }
            if(L5 > melhor){
                melhor = L5;
            }
            if(suf + melhor > res){
                res = suf + melhor;
            }
        }

        cout << res << "\n";
    }
    return 0;
}