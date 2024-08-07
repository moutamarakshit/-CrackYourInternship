/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*
private:
    int length(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    } */
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*int lenA=length(headA);
        int lenB=length(headB);
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(lenA>lenB){
            temp1=temp1->next;
            lenA--;
        }
        while(lenB>lenA){
            temp2=temp2->next;
            lenB--;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1; */
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};
