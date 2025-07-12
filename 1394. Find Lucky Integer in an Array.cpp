class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto i:arr) mpp[i]++;
        int maxi=-1;
        for(auto it:mpp){
            if(it.first==it.second){
                maxi=max(maxi,it.first);
            } 
        }
        return maxi;
    }
};