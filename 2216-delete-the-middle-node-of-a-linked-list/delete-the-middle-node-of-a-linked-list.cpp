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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        int length = 0;
        ListNode *curr = head;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        int middle = length/2;
        ListNode *prev = NULL;
        curr = head;
        while(middle){
            prev = curr;
            curr = curr->next;
            middle--;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }
};