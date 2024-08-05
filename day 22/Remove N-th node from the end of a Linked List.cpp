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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //brute force
        /*
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n) return head->next;
        temp=head;
        int res=cnt-n;
        while(temp){
            res--;
           if(res==0)
           break;
           temp=temp->next;
        }
        ListNode* ans=temp->next;
        temp->next=temp->next->next;
        delete ans;
        return head; */
        //optimal
        ListNode* fast=head;
        for(int i=0;i<n;i++)
        fast=fast->next;
        if(fast==nullptr) return head->next;
        ListNode* slow=head;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* dummy=slow->next;
        slow->next=slow->next->next;
        delete dummy;
        return head;            
    }
};
