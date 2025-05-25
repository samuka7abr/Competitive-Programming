#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
 
        vector<int> d(n), l(n), r(n);
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
        }
 
        vector<int> L(n+1), R(n+1);
        L[0] = R[0] = 0;
        bool ok = true;
        for(int i = 1; i <= n; i++){
            int novoL, novoR;
            if(d[i-1] == -1){
                novoL = L[i-1];
                novoR = R[i-1] + 1;
            } else {
                novoL = L[i-1] + d[i-1];
                novoR = R[i-1] + d[i-1];
            }
            novoL = max(novoL, l[i-1]);
            novoR = min(novoR, r[i-1]);
            if(novoL > novoR){
                ok = false;
                break;
            }
            L[i] = novoL;
            R[i] = novoR;
        }
 
        if(!ok){
            cout << "-1\n";
            continue;
        }
 
        vector<int> res(n);
        vector<int> h(n+1);
        h[n] = L[n];  
 
        for(int i = n; i >= 1; i--){
            if(d[i-1] == -1){
                int hp = h[i];
                if(hp >= L[i-1] && hp <= R[i-1]){
                    res[i-1] = 0;
                    h[i-1] = hp;
                } else {
                    res[i-1] = 1;
                    h[i-1] = h[i] - 1;
                }
            } else {
                res[i-1] = d[i-1];
                h[i-1] = h[i] - d[i-1];
            }
        }
 
        for(int i = 0; i < n; i++){
            cout << res[i] << (i+1<n?' ':'\n');
        }
    }
    return 0;
}