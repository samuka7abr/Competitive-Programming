#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_testes;
    cin >> total_testes;
    while(total_testes--){
        int tamanho;
        cin >> tamanho;
        vector<vector<int>> grade(tamanho, vector<int>(tamanho));
        int topo = 0, base = tamanho - 1;
        int esquerda = 0, direita = tamanho - 1;
        int valor_atual = 0;

        while(topo <= base && esquerda <= direita){
            for(int coluna = esquerda; coluna <= direita; coluna++){
                grade[topo][coluna] = valor_atual++;
            }
            topo++;

            for(int linha = topo; linha <= base; linha++){
                grade[linha][direita] = valor_atual++;
            }
            direita--;

            if(topo <= base){
                for(int coluna = direita; coluna >= esquerda; coluna--){
                    grade[base][coluna] = valor_atual++;
                }
                base--;
            }

            if(esquerda <= direita){
                for(int linha = base; linha >= topo; linha--){
                    grade[linha][esquerda] = valor_atual++;
                }
                esquerda++;
            }
        }

        int maior_valor = tamanho * tamanho - 1;
        for(int linha = 0; linha < tamanho; linha++){
            for(int coluna = 0; coluna < tamanho; coluna++){
                grade[linha][coluna] = maior_valor - grade[linha][coluna];
            }
        }

        for(int linha = 0; linha < tamanho; linha++){
            for(int coluna = 0; coluna < tamanho; coluna++){
                cout << grade[linha][coluna] << (coluna + 1 < tamanho ? ' ' : '\n');
            }
        }
    }

    return 0;
}
