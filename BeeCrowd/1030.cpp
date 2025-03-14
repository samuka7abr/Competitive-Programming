#include <iostream>
using namespace std;

int main() {



    int NC;
    cin >> NC;

    for (int caso = 1; caso <= NC; caso++) {
        int n, k;
        cin >> n >> k;
        int pos = 0;


        for (int i = 2; i <= n; i++) {
            pos = (pos + k) % i;
        }


        cout << "Case " << caso << ": " << pos + 1 << "\n";
    }

    return 0;
}
