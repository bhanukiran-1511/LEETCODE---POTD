class Solution {
public:
    char f(string &s,int pos,int k){
        if(pos>=k) return s[k-1];
        else{
            int n=s.size();
            for(int i=0;i<n;i++){
                if(s[i]=='z') s+='a';
                else s+=char((int)s[i]+1);
            }
            return f(s,pos+n,k);
        }
    }
    char kthCharacter(int k) {
        return char('a' + __builtin_popcount(k - 1));
    }
};