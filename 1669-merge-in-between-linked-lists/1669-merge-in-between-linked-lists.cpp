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
        int nodeStart = 1;
        int nodeEnd = 0;
        ListNode* lEnd = list2;
        ListNode* curr = list1;
        ListNode* prev = list1;
        while(lEnd->next || nodeStart != a || nodeEnd != b){
            if(lEnd->next) lEnd = lEnd->next;
            
            if(nodeStart != a){
                nodeStart++;
                prev = prev->next;
            }
            
            if(nodeEnd != b){
                nodeEnd++;
                curr = curr->next;
            }
        }
        prev->next = list2;
        lEnd->next = curr->next;
        return list1;

    }
};