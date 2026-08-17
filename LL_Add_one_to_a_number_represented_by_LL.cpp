/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int backtrack(ListNode* head){
        ListNode* temp = head;

        if(temp == nullptr){
            return 1;          // Add one when we reach the end
        }

        int carry = backtrack(temp->next);

        temp->val = temp->val + carry;

        if(temp->val < 10){
            return 0;
        }

        temp->val = 0;
        return 1;
    }

    ListNode *addOne(ListNode *head) {

        int carry = backtrack(head);

        if(carry == 1){
            ListNode* newhead = new ListNode(1);
            newhead->next = head;
            return newhead;
        }

        return head;
    }
};
