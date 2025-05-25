#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int C, G;
    cin >> C >> G;
    if (C==1){
        cout << "vivo e morto";
    } else if(C==0 && G==0){
        cout << "morto";
    } else if(C==0 && G==1){
        cout << "vivo";
    }
}