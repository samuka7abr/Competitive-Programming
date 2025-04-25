#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int A, B;
    while(cin >> A >> B){
        cout << (A ^ B) << endl;
    }

    return 0;
}