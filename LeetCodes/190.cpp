class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t resultado = 0;
            for(int i =  0; i < 32; ++i){
                resultado = (resultado << 1) | (n & 1ULL);
                n >>= 1ULL;
            }
            return resultado;
        }
    };
//complexidade espacial e temporal O(1)