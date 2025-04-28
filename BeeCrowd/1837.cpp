#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;

    int q0 = a / b;
    int r0 = a % b;

    int q, r;
    if (r0 < 0) {
        int s = (b > 0 ? 1 : -1);
        q = q0 - s;
        r = r0 + abs(b);
    } else {
        q = q0;
        r = r0;
    }

    cout << q << " " << r << "\n";
    return 0;
}