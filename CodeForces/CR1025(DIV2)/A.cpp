#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    while (N--) {
        int T;
        cin >> T;

        vector<int> resultados(T);
        for (int i = 0; i < T; i++) {
            cin >> resultados[i];
        }

        bool possivel = true;
        bool pode_perder = false, pode_vencer = false;

        if (resultados[0] == 0) {
            pode_perder = false;
            pode_vencer = true;
        } else {
            pode_perder = true;
            pode_vencer = false;
        }

        for (int i = 1; i <= T - 2 && possivel; i++) {
            bool proximo_pode_perder = false, proximo_pode_vencer = false;

            if (resultados[i] == 0) {
                if (pode_perder) {
                    proximo_pode_perder = false;
                    proximo_pode_vencer = true;
                } else {
                    possivel = false;
                }
            } else {
                if (pode_vencer) {
                    proximo_pode_perder = true;
                    proximo_pode_vencer = true;
                } else if (pode_perder) {
                    proximo_pode_perder = true;
                    proximo_pode_vencer = false;
                } else {
                    possivel = false;
                }
            }

            pode_perder = proximo_pode_perder;
            pode_vencer = proximo_pode_vencer;
        }

        if (possivel) {
            if (resultados[T - 1] == 0) {
                if (!pode_perder) {
                    possivel = false;
                }
            } else {
                if (!pode_vencer) {
                    possivel = false;
                }
            }
        }

        if (possivel) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;;
        }
    }

    return 0;
}
