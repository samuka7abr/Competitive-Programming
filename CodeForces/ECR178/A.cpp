#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll soma = a + b + c;
        if (soma % 3 == 0 && a + c >= 2 * b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}