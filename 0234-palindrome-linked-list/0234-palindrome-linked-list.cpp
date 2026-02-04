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
 #include<vector>
class Solution {
public:
    // ListNode* reverse(ListNode* head){
    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     ListNode* next = nullptr;
    //     while(curr != nullptr){
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
    bool check(vector<int> v){
        int size = v.size();
        int s = 0;
        int e = size - 1;
        while(s<=e){
            if(v[s] != v[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        return check(v);
        // ListNode* head2 = reverse(head);
        // ListNode* temp = head;
        // ListNode* temp2 = head2;
        // while(temp != nullptr){
        //     cout<<temp->val<<" "<<temp2->val<<" ";
        //     if(temp->val != temp2->val){
        //         return false;
        //     }else
        //     {
        //     temp = temp->next;
        //     temp2 = temp2->next;
        //     }
        // }
        // return true;
    }
};