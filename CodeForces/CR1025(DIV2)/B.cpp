#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int teto_log2(int x) {
    if (x <= 1) return 0;
    int log2Inf = 31 - __builtin_clz(x); 

    if (x == (1 << log2Inf)) {
        return log2Inf;
    } else {
        return log2Inf + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        int linhas, colunas, linha_i, coluna_i;
        cin >> linhas >> colunas >> linha_i >> coluna_i;

        int linhas_mantidas = min(linha_i, linhas - linha_i + 1);
        int colunas_mantidas = min(coluna_i, colunas - coluna_i + 1);

        int cortaLinha = teto_log2(linhas_mantidas) + teto_log2(colunas);

        int cortaCol = teto_log2(linhas) + teto_log2(colunas_mantidas);

        int resposta = 1 + min(cortaLinha, cortaCol);
        cout << resposta << endl;
    }

    return 0;
}
