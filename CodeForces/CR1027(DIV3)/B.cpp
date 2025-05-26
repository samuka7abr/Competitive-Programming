#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int z = 0;
        for(char c: s) if(c=='0') z++;
        int o = n - z;
        int m = n / 2;
        int mistura = m - k;

        bool ok = true;
        if(mistura < 0) ok = false;           
        if(z < mistura || o < mistura) ok = false;
        if(((z - mistura) & 1) != 0) ok = false;

        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}