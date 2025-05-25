#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int OFFSET = 4000;
    const int RANGE = 8001;

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    static long long dp[5][RANGE];
    dp[0][OFFSET] = 1;

    for(int x: A){
        for(int k = 4; k >= 1; k--){
            int lo = OFFSET - 1000*(k-1);
            int hi = OFFSET + 1000*(k-1);
            for(int s = hi; s >= lo; s--){
                long long cnt = dp[k-1][s];
                if(cnt) dp[k][s + x] += cnt;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int q;
        cin >> q;
        int idx = q + OFFSET;
        cout << ( (idx>=0 && idx<RANGE) ? dp[4][idx] : 0 ) << "\n";
    }

    return 0;
}
