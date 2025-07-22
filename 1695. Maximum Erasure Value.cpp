class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int ans=0;
        int l=0;
        int sum=0;
        for(int r=0;r<n;r++){
            mpp[nums[r]]++;
            sum+=nums[r];
            while(mpp[nums[r]]>1){
                mpp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};