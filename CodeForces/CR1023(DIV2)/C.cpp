#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll K;
        cin >> n >> K;
        string s;
        cin >> s;

        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        bool fail = false, hasExact = false;
        {
            ll acc = 0;
            for(int i = 1; i <= n; i++){
                if(s[i-1] == '1'){
                    acc += a[i];
                    if(i == n || s[i] == '0'){
                        if(acc > K) fail = true;
                        if(acc == K) hasExact = true;
                        acc = 0;
                    }
                }
            }
        }
        if(fail){
            cout << "No\n";
            continue;
        }
        if(hasExact){
            cout << "Yes\n";
            for(int i = 1; i <= n; i++){
                if(s[i-1] == '1') cout << a[i];
                else              cout << -INF;
                cout << (i < n ? ' ' : '\n');
            }
            continue;
        }

        vector<pair<int,int>> zeros;
        for(int i = 1; i <= n; ){
            if(s[i-1] == '0'){
                int j = i;
                while(j <= n && s[j-1] == '0') j++;
                zeros.emplace_back(i, j-1);
                i = j;
            } else {
                i++;
            }
        }
        if(zeros.empty()){
            cout << "No\n";
            continue;
        }

        vector<ll> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            ll v = (s[i-1] == '1' ? a[i] : 0LL);
            dp[i] = max(v, dp[i-1] + v);
        }

        bool done = false;
        for(auto [l, r] : zeros){
            if(r - l + 1 >= 2){
                ll bestLeft = max<ll>(0, dp[l-1]);
                ll x = K - bestLeft;

                vector<ll> b(n+1);
                for(int i = 1; i <= n; i++){
                    b[i] = (s[i-1]=='1' ? a[i] : -INF);
                }
                b[l] = x;
                for(int i = l+1; i < r; i++){
                    b[i] = 0;
                }
                cout << "Yes\n";
                for(int i = 1; i <= n; i++){
                    cout << b[i] << (i<n?' ':'\n');
                }
                done = true;
                break;
            }
        }
        if(done) continue;

        for(auto [l, r] : zeros){
            // r == l
            ll bestLeft = max<ll>(0, dp[l-1]);

            ll pref = 0, maxPref = 0;
            int j = l+1;
            while(j <= n && s[j-1] == '1'){
                pref += a[j];
                maxPref = max(maxPref, pref);
                j++;
            }

            ll x = K - (bestLeft + maxPref);
            vector<ll> b(n+1);
            for(int i = 1; i <= n; i++){
                b[i] = (s[i-1]=='1' ? a[i] : -INF);
            }
            b[l] = x;

            cout << "Yes\n";
            for(int i = 1; i <= n; i++){
                cout << b[i] << (i<n?' ':'\n');
            }
            done = true;
            break;
        }
        if(!done){
            cout << "No\n";
        }
    }
    return 0;
}
