class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        int n=pl.size();
        int m=tr.size();
        sort(pl.begin(),pl.end());
        sort(tr.begin(),tr.end());
        int i=0,j=0;
        int cnt=0;
        while(i<n && j<m){
            if(pl[i]>tr[j]) j++;
            else if(pl[i]<=tr[j]){
                cnt++;
                i++;
                j++;
            }
            // else j++;
        }
        return cnt;
        
    }
};