#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> vetor(n);
        for(int i = 0; i < n; i++){
            cin >> vetor[i];
        }
        ll minimo = *min_element(vetor.begin(), vetor.end());
        ll maximo = *max_element(vetor.begin(), vetor.end());
        ll R = maximo - minimo;
        ll S = accumulate(vetor.begin(), vetor.end(), 0LL);
        int countMax = 0;
        for(ll x : vetor){ 
            if(x == maximo) countMax++;
        }

        bool tomGanha;
        if(R > k + 1) {
            tomGanha = false;
        }
        else if (S % 2 == 0) {
            tomGanha = false;
        }
        else if (R == k + 1 && countMax > 1) {
            tomGanha = false;
        }
        else {
            tomGanha = true;
        }

        if(tomGanha){
            cout << "Tom" << endl;
        }else{
            cout << "Jerry" << endl;
        }
    }
    return 0;
}
