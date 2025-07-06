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
    ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* root = dummy;
    ListNode* curr = head;

    while (curr != nullptr) {
        int sum = 0;
        if (curr->val == 0) {
            curr = curr->next; // move inside segment
            // Ensure we do not access curr->val if curr is nullptr
            while (curr != nullptr && curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }
            // Only create a node if a segment was found
            if (sum > 0) {
                root->next = new ListNode(sum);
                root = root->next;
            }
        } else {
            curr = curr->next; // skip non-zero values outside segments
        }
    }
    return dummy->next;
}

};