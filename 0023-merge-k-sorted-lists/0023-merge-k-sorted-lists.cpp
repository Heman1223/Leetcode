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
private:
    ListNode* mergeTwoList(ListNode* list1,ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining part
        if(list1) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode* list1 = mergeTwoList(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            list1 = mergeTwoList(list1,lists[i]);
        }
        return list1;
    }
};