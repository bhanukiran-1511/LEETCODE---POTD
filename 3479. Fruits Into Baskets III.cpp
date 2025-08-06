class Solution {
public:
    void build(int i,int l,int r, vector<int>&arr,vector<int>&segment){
        if(l==r) {
            segment[i]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,arr,segment);
        build(2*i+2,mid+1,r,arr,segment);
        segment[i]=max(segment[2*i+1],segment[2*i+2]);
    }
    bool query(int i,int l,int r,int fruit,vector<int>&segment){
        if(segment[i]<fruit) return false;
        if(l==r){
            segment[i]=-1;
            return true;
        }
        int mid=(l+r)/2;
        bool placed=false;
        int left=segment[2*i+1];
        if(left>=fruit){
            placed=query(2*i+1,l,mid,fruit,segment);
        }
        else{
            placed=query(2*i+2,mid+1,r,fruit,segment);
        }
        segment[i]=max(segment[2*i+1],segment[2*i+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>segment(4*n+1,-1);
        build(0,0,n-1,baskets,segment);
        int unplaced=0;
        for(int fruit:fruits){
            if(query(0,0,n-1,fruit,segment)==false) unplaced++;
        }
        return unplaced;
    }
};