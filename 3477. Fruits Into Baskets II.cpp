class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int fruit=fruits[i];
            int flag=1;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruit){
                    baskets[j]=-1e9;
                    flag=0;
                    break;
                } 
            }
            if(flag==1) cnt++;
        }
        return cnt;
    }
};