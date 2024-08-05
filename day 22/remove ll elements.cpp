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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
      ListNode* dummy=new ListNode(0,head);
      ListNode* prev=dummy;
      ListNode* curr=head;
      while(curr!=nullptr){
        if(curr->val==val){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
            
        }else{
            prev=curr;
            curr=curr->next;
        }
      }
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
      }
       
};
