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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int sum = 0,carry = 0;
        while(curr1 && curr2){
            sum = curr1->val + curr2->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = newNode;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1){
            sum = curr1->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = newNode;
            curr1 = curr1->next;
        }
        while(curr2){
            sum = curr2->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum%10;
            }
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = newNode;
            curr2 = curr2->next;
        }
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            curr->next = newNode;
        }
        return ans->next;
    }
};