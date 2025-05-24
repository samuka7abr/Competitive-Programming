#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> vetor(n);
        for (int i = 0; i < n; i++) {
            cin >> vetor[i];
        }

        sort(vetor.begin(), vetor.end());

        vector<int> ultimaApar(2, -1);
        for (int i = 0; i < n; i++) {
            ultimaApar[vetor[i] % 2] = i;
        }

        int res = n;  
        for (int x = 0; x < n; x++) {
            int p = vetor[x] % 2;
            int j = ultimaApar[p];
            if (j < x) continue; 
            int tira = x + (n - 1 - j);

            res = min(res, tira);
        }
        
        cout << res << endl;
    }


    return 0;
}