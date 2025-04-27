#include <bits/stdc++.h>
using namespace std;

unsigned parse(const string &s, int base) {
    unsigned v = 0;
    for (char c : s) {
        v = v * base + (isdigit(c) ? c - '0' : tolower(c) - 'a' + 10);
    }
    return v;
}

string toHex(unsigned v) {
    if (v == 0) return "0";
    string r;
    while (v) {
        unsigned d = v % 16;
        r.push_back(d < 10 ? '0' + d : 'a' + d - 10);
        v /= 16;
    }
    reverse(r.begin(), r.end());
    return r;
}

string toBin(unsigned v) {
    if (v == 0) return "0";
    string r;
    while (v) {
        r.push_back('0' + (v & 1));
        v >>= 1;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string X, Y;
        cin >> X >> Y;
        int base = (Y == "bin" ? 2 : Y == "dec" ? 10 : 16);
        unsigned v = parse(X, base);

        cout << "Case " << i << ":\n";
        if (base != 10) cout << v << " dec\n";
        if (base != 16) cout << toHex(v) << " hex\n";
        if (base != 2)  cout << toBin(v) << " bin\n";
        cout << "\n";
    }
    return 0;
}
