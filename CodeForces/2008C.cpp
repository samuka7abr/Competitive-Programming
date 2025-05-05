#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        ll r, l;
        cin >> l >> r;

        ll d = r - l;
        ll lo = 1, hi = 2e5, ans = 0;
        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            ll need = mid * (mid - 1) / 2;

            if(need <= d){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}