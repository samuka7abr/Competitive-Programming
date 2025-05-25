#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int casos;
    cin >> casos;
    while(casos--){
        int tam;
        cin >> tam;
 
        vector<ll> resposta(tam);
        vector<ll> historico;
        historico.reserve(tam);
 
        ll maiorPrefixo = 0;
        ll melhorBeleza = 0;
 
        for(int idx = 0; idx < tam; idx++){
            ll valor;
            cin >> valor;
 
            if(valor > maiorPrefixo){
                ll candidata = 0;
                if(!historico.empty()){
                    if(2 * maiorPrefixo > valor){
                        candidata = valor;
                    } else {
                        for(ll anterior : historico){
                            ll b = anterior + (valor % anterior);
                            if(b > candidata) candidata = b;
                        }
                    }
                }
                melhorBeleza = max(melhorBeleza, candidata);
                maiorPrefixo = valor;
            }
            else if(valor < maiorPrefixo){
                ll b = valor + (maiorPrefixo % valor);
                melhorBeleza = max(melhorBeleza, b);
            }
 
            resposta[idx] = melhorBeleza;
            historico.push_back(valor);
        }
 
        for(int i = 0; i < tam; i++){
            cout << resposta[i] << (i+1 < tam ? ' ' : '\n');
        }
    }
 
    return 0;
}
