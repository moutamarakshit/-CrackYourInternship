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
    void reorderList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while (temp) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = 0, k = 0;
        int n = vec.size();
        while (temp != nullptr) {
            if (i % 2 == 0) {
                temp->val = vec[k];
            } else {
                temp->val = vec[n - k - 1];
                k++;
            }
            i++;
            temp = temp->next;
        }
    }
};
