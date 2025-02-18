#include <iostream> 
#include <sstream>
#include <algorithm>

class Solution{
public:
    std::string reverseWords(std::string s){
        std::stringstream res;
        int l = 0, r = 0;

        while(r < s.length()){
            if(s[r] != ' '){
                r++;
            }else{
                std::reverse(s.begin() + l, s.begin() + r);
                res << s.substr(l, r -l + 1);
                r++;
                l = r;
            }
        }
        std::reverse(s.begin() + l, s.begin() + r);
        res << " " << s.substr(l, r - l);

        std::string output = res.str();
        return output.substr(1); 
    }
};

int main(){
    
    
    return 0;
}