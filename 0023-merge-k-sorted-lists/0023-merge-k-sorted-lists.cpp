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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* dummy=new ListNode(-1);
        ListNode* prevhead=dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto it:lists){
            ListNode* ptr=it;
            while(ptr){
                pq.push({ptr->val,ptr});
                ptr=ptr->next;
            }
            
        }
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            dummy->next=node;
            dummy=node;
        }
        return prevhead->next;

    }
};