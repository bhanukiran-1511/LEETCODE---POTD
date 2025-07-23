class Solution {
public:
    int modify(string pattern,string &s,int pt){
        int n=s.size();
        if(n<2) return 0;
        string newStr;
        int total=0;
        for(int i=0;i<n;i++){
            if(newStr.size()!=0 && s[i]==pattern[1] && newStr.back()==pattern[0]){
                total+=pt;
                newStr.pop_back();
            }
            else newStr.push_back(s[i]);
        }
        s=newStr;
        return total;
    }
    int maximumGain(string s, int x, int y) {
        int points=0;
        string copy=s;
        if(x>y){
            points+=modify("ab",copy,x);
            points+=modify("ba",copy,y);
        }
        else{
            points+=modify("ba",copy,y);
            points+=modify("ab",copy,x);
        }
        return points;
    }
};