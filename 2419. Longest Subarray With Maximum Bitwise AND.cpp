class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int len=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] && nums[i]==maxi){
                len++;
            }
            else len=1;
            res=max(res,len);
        }
        return res;
    }
};