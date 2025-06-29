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
        if(!head || !head->next) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i=0;i<n;i++) {
            fast = fast->next;
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;
        return dummy->next;
    }
};
