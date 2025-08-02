class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mpp;
        int mini=1e9;
        for(auto num:basket1){
            mpp[num]++;
            mini=min(mini,num);
        }
        for(auto num:basket2){
            mpp[num]--;
            mini=min(mini,num);
        }
        vector<int>temp;
        for(auto it:mpp){
            int cost=it.first;
            int count=it.second;
            if(count==0) continue;
            if(count %2 ==1) return -1;
            else{
                for(int i=1;i<=abs(count/2);i++) temp.push_back(cost);
            }
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=0;i<temp.size()/2;i++){
            ans+=min(temp[i],mini*2);
        }
        return ans;
    }
};