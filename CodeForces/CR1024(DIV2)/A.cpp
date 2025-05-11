    #include <bits/stdc++.h>
    using namespace  std;
    using ll = long long;

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int T;
        cin >> T;

        while(T--){
            ll n, m, p, q;
            cin >> n >> m >> p >> q;
            ll r = n % p;
            if(r  != 0){
                cout << "YES\n";
            }else{
                long long t = n / p;
                cout << (m == t * q ? "YES\n" : "NO\n");
            }
        }

        return 0;
    }