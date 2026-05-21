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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        for(int i = 0;i < n - 1;i++){
            fast = fast->next;
        }
        while(fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head){
            head = slow->next;
            slow->next = NULL;
            delete slow;
            return head;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;

    }
};