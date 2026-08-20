/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {

        ListNode* temp = head;

        while(temp != NULL) {

            if(temp->val == target) {

                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                if(prevNode)
                    prevNode->next = nextNode;
                else
                    head = nextNode;

                if(nextNode)
                    nextNode->prev = prevNode;

                delete temp;
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
