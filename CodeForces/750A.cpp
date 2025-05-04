#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    int lo = 0;
    int hi = n;
    int res = 0;
    int t = 240 - k;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if((5 * mid * (mid + 1)) / 2 <= t){
            res = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}