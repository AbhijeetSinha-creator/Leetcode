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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = b - a + 1;
        ListNode *curr = new ListNode(0);
        curr->next = list1;
        list1 = curr;
        ListNode *prev = curr;
        curr = curr->next;
        while(a){
            prev = curr;
            curr = curr->next;
            a--;
        }
        while(count){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count--;
        }
        ListNode *Tail = list2;
        while(Tail->next != NULL){
            Tail = Tail->next;
        }
        prev->next = list2;
        Tail->next = curr;
        curr = list1;
        list1 = list1->next;
        delete curr;
        return list1;
    }
};