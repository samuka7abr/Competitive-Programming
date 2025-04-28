#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int n : nums){
            ans ^= n;
        }
        cout << ans << endl;
    }
};