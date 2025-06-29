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
      ListNode* findMiddle(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next) {
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
      }

      ListNode* reverseLinkedList(ListNode* node) {
        ListNode* prev = nullptr;
        while(node){
            ListNode* nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
        }
        return prev;
      }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* middle = findMiddle(head);

        ListNode* right = reverseLinkedList(middle->next);

        middle->next = nullptr;

        ListNode* left = head;

        while(right) {
            ListNode* tmp1 = right->next;
            ListNode* tmp2 = left->next;

            left->next = right;
            right->next = tmp2;

            left = tmp2;
            right = tmp1;
        }
       
    }
};
