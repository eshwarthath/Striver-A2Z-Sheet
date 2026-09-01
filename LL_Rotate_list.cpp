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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length and tail
        int len = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;
        if (k == 0)
            return head;

        // Make list circular
        tail->next = head;

        // Find new tail
        int steps = len - k;
        ListNode* newTail = head;

        while (--steps) {
            newTail = newTail->next;
        }

        // Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
