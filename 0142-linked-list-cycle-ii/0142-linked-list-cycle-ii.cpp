/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        ListNode* temp = head;
        int count = 0;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};