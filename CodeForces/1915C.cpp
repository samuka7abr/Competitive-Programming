#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        ll soma = 0;

        for(int i = 0; i < N; i++){
            int numero;
            cin >> numero;
            soma += numero;
        }

        ll r = (int)sqrt(soma);
        if(r * r == soma){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}