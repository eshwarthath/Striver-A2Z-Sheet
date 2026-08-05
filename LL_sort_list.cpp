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

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        if (left == nullptr)
            return right;

        if (right == nullptr)
            return left;

        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        if (left->val <= right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }

        temp = head;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left != nullptr)
            temp->next = left;
        else
            temp->next = right;

        return head;
    }

    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* mid = findMiddle(head);

        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }
};
