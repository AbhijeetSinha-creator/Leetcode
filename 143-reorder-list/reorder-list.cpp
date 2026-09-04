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
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p2 = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL;
        while(p2){
            ListNode *future = p2->next;
            p2->next = prev;
            prev = p2;
            p2 = future;
        }
        p2 = prev;
        ListNode *p1 = head;
        ListNode *front1;
        ListNode *front2;
        while(p2){
            front1 = p1->next;
            front2 = p2->next;
            p1->next = p2;
            p2->next = front1;
            p1 = front1;
            p2 = front2;
        }
    }
};