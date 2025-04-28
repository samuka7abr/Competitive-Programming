#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int testCount;
    cin >> testCount;
    while (testCount--) {
        int arraySize;
        cin >> arraySize;
        vector<ll> values(arraySize + 2);
        for (int i = 1; i <= arraySize; i++) {
            cin >> values[i];
        }
 
        vector<ll> suffixSum(arraySize + 2, 0), prefixMax(arraySize + 2, 0);
        for (int i = arraySize; i >= 1; i--) {
            suffixSum[i] = values[i] + suffixSum[i + 1];
        }
        prefixMax[1] = values[1];
        for (int i = 2; i <= arraySize; i++) {
            prefixMax[i] = max(prefixMax[i - 1], values[i]);
        }
 
        for (int k = 1; k <= arraySize; k++) {
            int startIndex = arraySize - k + 1;
            ll keepAll = suffixSum[startIndex];
            ll moveOne = suffixSum[startIndex + 1] + prefixMax[startIndex];
            ll result = max(keepAll, moveOne);
            cout << result << (k < arraySize ? ' ' : '\n');
        }
    }
 
    return 0;
}