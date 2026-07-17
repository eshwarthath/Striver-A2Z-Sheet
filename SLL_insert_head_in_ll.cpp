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
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode* temp = new ListNode(X,head);
            head = temp;
            return head;
        }
};
