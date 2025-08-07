class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int first=0;
        for(int i=0;i<n;i++) first+=fruits[i][i];

        vector<vector<int>>dp1(n,vector<int>(n,0));
        dp1[0][n-1]=fruits[0][n-1];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int maxi=0;
                for(int dj=-1;dj<=1;dj++){
                    int prevCol=j+dj;
                    if(prevCol>=0 && prevCol<n){
                        maxi=max(maxi,dp1[i-1][prevCol]);
                    }
                }
                dp1[i][j]=maxi+fruits[i][j];
            }
        }
        int second=dp1[n-1][n-1];

        vector<vector<int>>dp2(n,vector<int>(n,0));
        dp2[n-1][0]=fruits[n-1][0];

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int maxi=0;
                for(int dc=-1;dc<=1;dc++){
                    int prevRow=i+dc;
                    if(prevRow>=0 && prevRow<n) maxi=max(maxi,dp2[prevRow][j-1]);
                }
                dp2[i][j]=maxi+fruits[i][j];
            }
        }
        int third=dp2[n-1][n-1];
        return first+second+third-2*fruits[n-1][n-1];
    }
};