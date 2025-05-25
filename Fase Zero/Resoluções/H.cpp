#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

string criaPalindromo(const string &pref, int L) {
    int l = pref.size();
    string P;
    P.reserve(L);
    P = pref;
    int espelho = (L % 2 == 0 ? l : l-1);
    for(int i = espelho - 1; i >= 0; --i)
        P.push_back(pref[i]);
    return P;
}

bool decBin(string &s) {
    int i = (int)s.size() - 1;
    while(i >= 0 && s[i] == '0') {
        s[i] = '1';
        --i;
    }
    if(i < 0) return false; 
    s[i] = '0';
    return s[0] == '1';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long X;
    cin >> X;
    string S;
    for(unsigned long long t = X; t; t >>= 1)
        S.push_back(char('0' + (t & 1)));
    reverse(S.begin(), S.end());
    if(S.empty()) S = "0";
    int L = S.size();

    int pre_len = (L + 1) / 2;
    string pref = S.substr(0, pre_len);
    string P = criaPalindromo(pref, L);

    if(P > S) {
        if(!decBin(pref)) {
            unsigned long long ans = (L == 1 ? 0ULL : ((1ULL << (L-1)) - 1ULL));
            cout << ans << "\n";
            return 0;
        }
        P = criaPalindromo(pref, L);
    }

    __int128 val = 0;
    for(char c : P) {
        val = (val << 1) + (c - '0');
    }
    cout << (unsigned long long)val << "\n";
    return 0;
}
