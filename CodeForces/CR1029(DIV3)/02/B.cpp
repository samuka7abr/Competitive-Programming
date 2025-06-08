#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18;  
const double PI = acos(-1.0);

int main(){
    otim;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            cout << i << " ";
        }
        cout << 1 << "\n";
    }
    return 0;
}

