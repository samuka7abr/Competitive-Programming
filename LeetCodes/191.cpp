class Solution {
    public:
        int hammingWeight(int n) {
            int uns = __builtin_popcount(n);
            return uns;
        }
    };

//Solução usando & comparator

int hammingWeight(int n){
    int uns = 0;

    while(n){
        uns += n & 1;
        n >>= 1;
    }
    
    return uns;
}
