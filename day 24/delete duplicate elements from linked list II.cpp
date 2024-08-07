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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mpp;
        ListNode* temp=head;
        while(temp){
            mpp[temp->val]++;
            temp=temp->next;
            
        }
        temp=head;
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        while(temp){
            if(mpp[temp->val]>1){
                prev->next=temp->next;
            }
            else {
                prev->next=temp;
                prev=temp;}
            temp=temp->next;
        }
        return dummy->next;
    }
};
