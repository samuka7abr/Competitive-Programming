#include <iostream>
#include <vector>

class Solution{
public: 
    int binary_search(std::vector<int>& nums, int n){
        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            int mid = (lo + hi) / 2;

            if(nums[mid] == n){
                std:: cout<<mid;
            }
            else if(nums[mid] < n){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
    };
};