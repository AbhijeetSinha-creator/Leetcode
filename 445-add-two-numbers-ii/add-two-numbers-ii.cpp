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
    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *future;
        while(curr != NULL){
            future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        head = prev;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *Head = NULL;
        ListNode *Tail = NULL;
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        int carry = 0;
        int sum;
        while(curr1 && curr2){
            sum = curr1->val + curr2->val + carry;
            if(Head == NULL){
                Head = new ListNode(sum % 10);
                Tail = Head;
            }
            else{
                Tail->next = new ListNode(sum % 10);
                Tail = Tail->next;
            }
            carry = sum/10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            sum = curr1->val + carry;
            Tail->next = new ListNode(sum % 10);
            Tail = Tail->next;
            carry = sum/10;
            curr1 = curr1->next;
        } 
        while(curr2){
            sum = curr2->val + carry;
            Tail->next = new ListNode(sum % 10);
            Tail = Tail->next;
            carry = sum/10;
            curr2 = curr2->next;
        }
        while(carry){
            Tail->next = new ListNode(carry % 10);
            Tail = Tail->next;
            carry = carry/10;
        } 
        Head = reverse(Head);
        return Head;
    }
};