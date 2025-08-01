class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=0;i<numRows-1;i++){
            vector<int>prev=ans.back();
            int prev_size=prev.size();
            vector<int>curr(prev_size+1,1);
            for(int j=1;j<prev_size;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};