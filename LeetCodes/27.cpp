class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int escrito = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != val){
                    nums[escrito] = nums[i];
                    escrito++;
                }
            }
            return escrito;
        }
    };