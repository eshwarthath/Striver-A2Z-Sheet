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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* newHead = reverse(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != nullptr) {
            if (first->val != second->val) {
                reverse(newHead);      // Restore the list
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore the original list
        slow->next = reverse(newHead);

        return true;
    }
};
