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
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll m = llabs(arr[0]);

        int count = 0;

        for(int j = 1; j < n; j++){
            if(llabs(arr[j]) < m){
                count++;
            }
        }

        cout << (count <= n/2 ? "YES\n" : "NO\n");
    }
    return 0;
}