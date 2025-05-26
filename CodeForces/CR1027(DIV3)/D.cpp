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
        int n;
        cin >> n;
        vector<pair<ll,ll>> monstros(n);
        for(int i = 0; i < n; i++){
            cin >> monstros[i].first >> monstros[i].second;
        }
        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        vector<ll> coordX(n), coordY(n);
        for(int i = 0; i < n; i++){
            coordX[i] = monstros[i].first;
            coordY[i] = monstros[i].second;
        }
        sort(coordX.begin(), coordX.end());
        sort(coordY.begin(), coordY.end());

        ll minX = coordX[0],  secondMinX = coordX[1];
        ll maxX = coordX[n-1], secondMaxX = coordX[n-2];
        ll minY = coordY[0],  secondMinY = coordY[1];
        ll maxY = coordY[n-1], secondMaxY = coordY[n-2];

        int cntMinX = count(coordX.begin(), coordX.end(), minX);
        int cntMaxX = count(coordX.begin(), coordX.end(), maxX);
        int cntMinY = count(coordY.begin(), coordY.end(), minY);
        int cntMaxY = count(coordY.begin(), coordY.end(), maxY);

        ll W0 = maxX - minX + 1;
        ll H0 = maxY - minY + 1;
        ll melhor = W0 * H0;

        for(int i = 0; i < n; i++){
            ll x = monstros[i].first;
            ll y = monstros[i].second;

            ll loX = (x > minX || cntMinX > 1 ? minX : secondMinX);
            ll hiX = (x < maxX || cntMaxX > 1 ? maxX : secondMaxX);
            ll w = hiX - loX + 1;

            ll loY = (y > minY || cntMinY > 1 ? minY : secondMinY);
            ll hiY = (y < maxY || cntMaxY > 1 ? maxY : secondMaxY);
            ll h = hiY - loY + 1;

            ll area = w * h;
            if(area == n-1){
                area += min(w, h);
            }
            melhor = min(melhor, area);
        }

        cout << melhor << "\n";
    }
    return 0;
}
