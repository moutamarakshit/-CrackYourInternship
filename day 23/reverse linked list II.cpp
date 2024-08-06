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
    ListNode* reverse(ListNode* temp,int res){
        if(res==0) return temp;
        if(temp==NULL ||temp->next==NULL) return temp;
        ListNode* newHead= reverse(temp->next,res-1);
        ListNode* front=temp->next;
        front->next=temp;
        temp->next=nullptr;
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int res=right-left;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prevl=dummy;
        for (int i = 1; i < left; i++) {
            prevl = prevl->next;
        }
         ListNode* start = prevl->next;
        ListNode* end = start;
        for (int i = left; i < right; i++) {
            end = end->next;
        }

        ListNode* rest = end->next;
        end->next = nullptr;

        ListNode* newHead = reverse(start, right - left);
        prevl->next = newHead;
        start->next = rest;

        return dummy->next;
    }
};
