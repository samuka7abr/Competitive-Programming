#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int>vec(N);
        for(int i = 0; i < N; i++)
            cin >> vec[i];

        int count = 0;
        int ultimo = -1e9;
        for(int x : vec){
            if(count == 0 || x >= ultimo + 2){
                count++;
                ultimo = x;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
