class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pvt = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pvt = i;
                break;
            }
        }
        if(pvt == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n-1; i > pvt; i--){
            if(nums[i] > nums[pvt]){
                swap(nums[i], nums[pvt]);
                break;
            }
        }
        reverse(nums.begin() + pvt + 1, nums.end());
    }
};