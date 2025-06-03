#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        ll x;
        cin >> x;

        int h = 63 - __builtin_clzll(x);
        ll ans = 2LL * h + 3;
        cout << ans << "\n";
    }

    return 0;
}
