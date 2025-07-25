class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<0) return maxi;
        int sum=0;
        set<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                if(st.find(nums[i])==st.end()){
                    st.insert(nums[i]);
                    sum+=nums[i];
                }
            }
        }
        return sum;
    }
};