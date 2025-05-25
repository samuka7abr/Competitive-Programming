#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int size = 1 << N;  
    vector<int> perm(size);
    for (int i = 0; i < size; ++i) perm[i] = i;

    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int c, t;
            cin >> c >> t;
            for (int j = 0; j < size; ++j) {
                if ((perm[j] >> c) & 1) {
                    perm[j] ^= (1 << t);
                }
            }
        } else {
            int c1, c2, t;
            cin >> c1 >> c2 >> t;
            for (int j = 0; j < size; ++j) {
                if (((perm[j] >> c1) & 1) && ((perm[j] >> c2) & 1)) {
                    perm[j] ^= (1 << t);
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        string row(size, '0');
        row[perm[i]] = '1';
        cout << row << '\n';
    }

    return 0;
}
