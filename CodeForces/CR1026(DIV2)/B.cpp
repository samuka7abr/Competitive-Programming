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
        string s;
        cin >> s;
        int balanceado = 0, segmentos = 0;
        for(char c : s){
            if(c == '('){ 
                balanceado++;
            }else{
                balanceado--;
            }          
            if(balanceado == 0){ 
                segmentos++;
            }
        }

        if(segmentos >= 2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}