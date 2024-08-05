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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                prev->next = head1;
                prev = prev->next;
                head1 = head1->next;
            } else {
                prev->next = head2;
                prev = prev->next;
                head2 = head2->next;
            }
        }
        if (head2 != nullptr) 
            prev->next = head2;
        else  prev->next = head1;
           
        return dummy.next;
    }
    ListNode* getmid(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = getmid(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* leftHead = mergesort(left);
        ListNode* rightHead = mergesort(right);
        ListNode* newhead=merge(leftHead, rightHead);
        return newhead;
    }
    ListNode* sortList(ListNode* head){
        /* if(head==NULL || head->next==NULL) return head;
         vector<int>vec;
         ListNode* temp=head;
         while(temp){
             vec.push_back(temp->val);
             temp=temp->next;
         }
         sort(vec.begin(),vec.end());
         temp=head;
         int k=0;
         while(temp){
             temp->val=vec[k];
             k++;
             temp=temp->next;
         }
         return head;
     } */
     return mergesort(head);
    }

    };
