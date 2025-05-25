#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll Y, K;
    cin >> Y >> K;
    if(Y == 1){
        cout << 1 + K;
        return 0;
    }

    vector<ll> primos;
    ll tY = Y;
    for(ll p = 2; p * p <= tY; ++p){
        if(tY % p == 0){
            primos.push_back(p);
            while(tY % p == 0) tY /= p;
        }
    }
    if(tY > 1) primos.push_back(tY);

    ll X = 1;
    ll rem = K;
    ll d = 1;

    while(rem > 0){
        if(d == Y){
            X += rem * d;
            break;
        }
        ll Z = Y / d;
        ll t = X / d;
        ll best_i = LLONG_MAX;
        for(ll p: primos){
            if(Z % p == 0){
                ll mod = t % p;
                ll ip = (p - mod) % p;
                if(ip == 0) ip = p;
                best_i = min(best_i, ip);
            }
        }
        if(best_i > rem){
            X += rem * d;
            break;
        }
        X += best_i * d;
        rem -= best_i;
        d = gcd(X, Y);
    }

    cout << X;
    return 0;
}
