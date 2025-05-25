#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long M;
    cin >> M;
    unsigned long long bits = (unsigned long long)M * 8ULL * 1000000ULL;

    int floorLog = 63 - __builtin_clzll(bits);
    int ans = ((1ULL << floorLog) == bits ? floorLog : floorLog + 1);

    cout << ans << "\n";
    return 0;
}
