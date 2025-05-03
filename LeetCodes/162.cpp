class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            return busca(nums, 0, nums.size() - 1);
        }
        int busca(vector<int>& nums, int l, int h){
            if(l == h){
                return l;
            }
            int mid = (l + h) / 2;
            if(nums[mid] > nums[mid + 1]){
                return busca(nums, l, mid);
            }
            return busca(nums, mid + 1, h);
        }
    };

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    return i;
                }
            }
            return nums.size() - 1;
        }
    };
        
