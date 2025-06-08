#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18;  
const double PI = acos(-1.0);

int main(){
    otim;
    int t;
    cin >> t;
    for(int T = 0; T < t; T++){
        ll n;
        cin >> n;
        vector<ll> vet(n+1);
        for(ll i = 1; i <= n; i++){
            cin >> vet[i];
        }
        ll d = n*n - 1;                   
        ll numY = n*vet[1] - vet[n];         
        ll numX = n*vet[n] - vet[1];         

        if (numY < 0 || numX < 0 || numY % d != 0 || numX % d != 0) {
            cout << "NO\n";
            continue;
        }
        ll y = numY / d;
        ll x = numX / d;

        bool ok = true;
        for(ll i = 1; i <= n; i++){
            ll esperado = i*x + (n - i + 1)*y;
            if (vet[i] != esperado) {
                ok = false;
                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
