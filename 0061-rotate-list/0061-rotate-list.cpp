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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
            return head;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        k = k%n;
        for(int i = 0; i < k;i++){
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp->next){
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            prev->next = NULL;
            head = temp;
        }
        return head;
    }
};