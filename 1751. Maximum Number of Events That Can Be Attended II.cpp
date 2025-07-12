class Solution {
public:
    int f(int idx,int n,vector<vector<int>>& events, int k,vector<vector<int>> &dp){
        if(idx>=n || k==0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];
        int npick=f(idx+1,n,events,k,dp);
        int currst=events[idx][0];
        int currend=events[idx][1];
        int val=events[idx][2];
        int pick=0;
        int nextind=n;
        int l=idx+1,r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            if(events[m][0]>currend){
                nextind=m;
                r=m-1;
            }
            else l=m+1;
        }
        pick=val+f(nextind,n,events,k-1,dp);
        return dp[idx][k]=max(pick,npick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return f(0,n,events,k,dp);
    }
};