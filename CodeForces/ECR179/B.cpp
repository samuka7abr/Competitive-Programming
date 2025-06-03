#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> F(11);
    F[1] = 1;
    F[2] = 2;
    for(int i = 3; i <= 10; i++){
        F[i] = F[i-1] + F[i-2];
    }

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        string resposta; 
        resposta.reserve(m);

        for(int i = 0; i < m; i++){
            int w, l, h;
            cin >> w >> l >> h;

            struct Slot { int A, B, Z; };

            int A0 = max(w, l);
            int B0 = min(w, l);

            vector<Slot> slots;
            slots.pb({A0, B0, 0});

            bool ok = true;
            for(int i = n; i >= 1; i--){
                int fi = F[i];

                int melhorIdx = -1;
                int melhorZ = INT_MAX;
                int melhorArea = INT_MAX;

                for(int j = 0; j < (int)slots.size(); j++){
                    int A = slots[j].A;
                    int B = slots[j].B;
                    int Z = slots[j].Z;

                    if(B < fi) continue;        
                    if(Z + fi > h) continue;    

                    int area = A * B;
                    if(Z < melhorZ || (Z == melhorZ && area < melhorArea)){
                        melhorZ = Z;
                        melhorArea = area;
                        melhorIdx = j;
                    }
                }

                if(melhorIdx < 0){
                    ok = false;
                    break;
                }

                int A = slots[melhorIdx].A;
                int B = slots[melhorIdx].B;
                int Z = slots[melhorIdx].Z;

                slots[melhorIdx] = slots.back();
                slots.pop_back();

                if(B - fi > 0){
                    int A1 = A;
                    int B1 = B - fi;
                    if(A1 < B1) swap(A1, B1);
                    slots.pb({A1, B1, Z});
                }

                if(A - fi > 0){
                    int a2 = A - fi;
                    int b2 = fi;
                    int A2 = max(a2, b2);
                    int B2 = min(a2, b2);
                    if(B2 > 0){
                        slots.pb({A2, B2, Z});
                    }
                }

                if(Z + fi < h){
                    slots.pb({fi, fi, Z + fi});
                }
            }

            if(ok){
                resposta.pb('1');
            }else{
                resposta.pb('0');
            }
        }

        cout << resposta << "\n";
    }

    return 0;
}
