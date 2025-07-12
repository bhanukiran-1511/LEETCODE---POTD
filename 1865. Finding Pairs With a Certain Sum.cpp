class FindSumPairs {
public:
    vector<int>a;
    vector<int>b;
    int n1,n2;
    unordered_map<int,int>mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        n1=a.size();
        b=nums2;
        n2=b.size();
        for(auto num:b) mpp[num]++;
    }
    
    void add(int index, int val) {
        mpp[b[index]]--;
        b[index]+=val;
        mpp[b[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto it:a){
            if(it<tot){
                int req=tot-it;
                if(mpp.count(req)) cnt+=mpp[req];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */