class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        for(int i=0;i<32;i++){
            if((n&(1<<i)) !=0){
                powers.push_back((1<<i));
            }
        }
        int mode=1e9+7;
        int q=queries.size();
        vector<int>ans;
        for(int i=0;i<q;i++){
            int st=queries[i][0];
            int ed=queries[i][1];
            long long val=1;
            for(int j=st;j<=ed;j++) val=(val*powers[j])%mode;
            ans.push_back(val);
        }
        return ans;
    }
};