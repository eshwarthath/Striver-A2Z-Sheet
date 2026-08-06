/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* sortList(ListNode* &head) {

        if(head == NULL || head->next == NULL)
            return head;

        // Create dummy nodes
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead  = new ListNode(-1);
        ListNode* twoHead  = new ListNode(-1);

        // Tail pointers
        ListNode* zero = zeroHead;
        ListNode* one  = oneHead;
        ListNode* two  = twoHead;

        ListNode* temp = head;

        // Divide into three lists
        while(temp != NULL)
        {
            if(temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        // Connect the lists
        zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        // Set new head
        if(zeroHead->next != NULL)
            head = zeroHead->next;
        else if(oneHead->next != NULL)
            head = oneHead->next;
        else
            head = twoHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};
