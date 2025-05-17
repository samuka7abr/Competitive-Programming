#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while (T--) {   
        ll m;
        cin >> m;

        auto interage = [&](const string &comando) {
            cout << comando << endl;
            cout.flush();
            int resposta;
            if (!(cin >> resposta) || resposta == -1) {
                exit(0);
            }
            return resposta;
        };

        interage("mul 9");
        interage("digit");
        interage("digit");
        interage("add " + to_string(m - 9));
        interage("!");

    }
    return 0;
}
