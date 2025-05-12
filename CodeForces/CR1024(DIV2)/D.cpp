#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int paridade_inversoes(const vector<int>& vetor) {
    int tamanho = vetor.size();

    vector<int> comprimido = vetor;
    sort(comprimido.begin(), comprimido.end());
    comprimido.erase(unique(comprimido.begin(), comprimido.end()), comprimido.end());

    vector<int> mapeado(tamanho);
    for(int i = 0; i < tamanho; i++) {
        mapeado[i] = int(lower_bound(comprimido.begin(), comprimido.end(), vetor[i]) - comprimido.begin());
    }

    vector<int> bit(tamanho + 1, 0);

    auto atualizar = [&](int indice){
        for(++indice; indice <= tamanho; indice += indice & -indice) {
            bit[indice]++;
        }
    };

    auto consultar = [&](int indice){
        int soma = 0;
        for(++indice; indice > 0; indice -= indice & -indice) {
            soma += bit[indice];
        }
        return soma;
    };

    int paridade = 0;
    for(int i = tamanho - 1; i >= 0; i--) {
        int x = mapeado[i];
        paridade ^= (consultar(x - 1) & 1);
        atualizar(x);
    }

    return paridade;
}

vector<int> montar_permutacao(const vector<int>& impares, const vector<int>& pares) {
    int tamanho = impares.size() + pares.size();
    vector<int> resultado(tamanho);
    int indice_impar = 0, indice_par = 0;

    for(int i = 0; i < tamanho; i++) {
        if((i % 2) == 0) {
            resultado[i] = impares[indice_impar++];
        } else {
            resultado[i] = pares[indice_par++];
        }
    }

    return resultado;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int total_testes;
    cin >> total_testes;

    while(total_testes--){
        int tamanho;
        cin >> tamanho;

        vector<int> entrada(tamanho), impares, pares;
        impares.reserve((tamanho + 1) / 2);
        pares.reserve(tamanho / 2);

        for(int i = 0; i < tamanho; i++) {
            cin >> entrada[i];
            if(i % 2 == 0) {
                impares.push_back(entrada[i]);
            } else {
                pares.push_back(entrada[i]);
            }
        }

        vector<int> impares_ordenados = impares;
        vector<int> pares_ordenados = pares;
        sort(impares_ordenados.begin(), impares_ordenados.end());
        sort(pares_ordenados.begin(), pares_ordenados.end());

        int paridade_impares = paridade_inversoes(impares);
        int paridade_pares = paridade_inversoes(pares);

        vector<int> resposta;

        if(paridade_impares == paridade_pares) {
            resposta = montar_permutacao(impares_ordenados, pares_ordenados);
        } else {
            vector<int> alternativa_1 = impares_ordenados;
            swap(alternativa_1[alternativa_1.size() - 1], alternativa_1[alternativa_1.size() - 2]);
            vector<int> resultado_1 = montar_permutacao(alternativa_1, pares_ordenados);

            vector<int> alternativa_2 = pares_ordenados;
            swap(alternativa_2[alternativa_2.size() - 1], alternativa_2[alternativa_2.size() - 2]);
            vector<int> resultado_2 = montar_permutacao(impares_ordenados, alternativa_2);

            resposta = min(resultado_1, resultado_2);
        }

        for(int valor : resposta) {
            cout << valor << ' ';
        }
        cout << "\n";
    }

    return 0;
}
