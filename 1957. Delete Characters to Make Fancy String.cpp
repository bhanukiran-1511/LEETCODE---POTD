class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int n=s.size();
        int cnt=1;
        char prev=s[0];
        ans+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==prev){
                cnt++;
                if(cnt<3) ans+=s[i];
            }
            else{
                prev=s[i];
                cnt=1;
                ans+=s[i];
            }
        }
        return ans;
    }
};