class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=endTime.size();
        vector<int>free;
        free.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            int curr=startTime[i]-endTime[i-1];
            free.push_back(curr);
        }
        if(eventTime-endTime[n-1] !=0)free.push_back(eventTime-endTime[n-1]);
        int maxi=0;
        int l=0;
        int s=free.size();
        int sum=0;
        for(int r=0;r<s;r++){
            sum+=free[r];
            while(r-l+1 > k+1){
                sum-=free[l];
                l++;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};