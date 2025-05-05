#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(g, a[i]);
        }
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != g) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                if (i == index) {
                    cout << 1;
                } else {
                    cout << 2;
                }
        
                if (i + 1 < n) {
                    cout << ' ';
                } else {
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}
