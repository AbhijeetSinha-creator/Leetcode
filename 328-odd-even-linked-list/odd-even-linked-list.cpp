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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;

        ListNode *head1 = head;
        ListNode *head2 = head1->next;
        ListNode *curr = head;
        ListNode *future;
        while(curr->next){
            future = curr->next;
            curr->next = future->next;
            curr = future;
        }
        curr = head1;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head2;
        return head;
    }
};