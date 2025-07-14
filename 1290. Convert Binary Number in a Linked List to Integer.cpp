/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;//storing linked list in vector
        }
        reverse(ans.begin(),ans.end());
        int val=0;
        for(int i=0;i<ans.size();i++){
            int num=ans[i];
            if(num==1)val+=pow(2,i);
        }
        return val;
    }
};