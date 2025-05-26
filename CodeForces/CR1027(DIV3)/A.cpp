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
        string s; 
        cin >> s;
        int N = stoi(s);
        int c = int(floor(sqrt(N) + 0.5));
        if(c*c == N) 
            cout << 0 << ' ' << c << '\n';
        else 
            cout << -1 << '\n';
    }
    return 0;
}