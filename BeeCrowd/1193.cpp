#include <bits/stdc++.h>
using namespace std;

int bin_to_dec(const string& bin) {
    int result = 0;
    for (char c : bin) {
        result = result * 2 + (c - '0');
    }
    return result;
}

string dec_to_bin(int n) {
    string res;
    while (n > 0) {
        res += (n % 2) + '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string X, base;
        cin >> X >> base;

        cout << "Case " << i << ":\n";

        if (base == "bin") {
            int dec = bin_to_dec(X);
            cout << dec << " dec\n";
            cout << hex << dec << " hex\n";
        } else if (base == "dec") {
            int dec = stoi(X);
            cout << hex << dec << " hex\n";
            cout << dec_to_bin(dec) << " bin\n";
        } else if (base == "hex") {
            int dec;
            stringstream ss;
            ss << hex << X;
            ss >> dec;
            cout << dec << " dec\n";
            cout << dec_to_bin(dec) << " bin\n";
        }

        cout << '\n';
    }

    return 0;
}