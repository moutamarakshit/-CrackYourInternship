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
    ListNode* reverselist(ListNode* temp){
        if(temp==NULL || temp->next==NULL) return temp;
        ListNode* newhead=reverselist(temp->next);
        ListNode* front=temp->next;
        front->next=temp;
        temp->next=nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
       /* stack<int>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* dummy=head;
        while(dummy){
            if(dummy->val==st.top()){
                st.pop();
                dummy=dummy->next;
            }
            else return false;
        }
        return true;
        */
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverselist(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=nullptr){
            if(first->val!=second->val){
               reverselist(newHead);
               return false;
            }
            else{
                first=first->next;
                second=second->next;
            }
        }
    reverselist(newHead);
    return true;
    }
};
