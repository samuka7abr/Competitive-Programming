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
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        ll soma = a + b + c;

        auto f = [&](ll x){
            ll ciclos = x/ 3;
            ll total = ciclos * soma;
            ll res = x % 3;
            if(res >= 1) total += a;
            if(res >= 2) total += b;
            return total;
        };

        ll lo = 1, hi = n, ans = n;

        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            if(f(mid) >= n){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}