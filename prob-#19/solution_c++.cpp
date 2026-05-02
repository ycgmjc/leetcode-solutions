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
        vector<ListNode*> path;
        ListNode* traverse = head;
        while(traverse -> next != nullptr) {
            path.push_back(traverse);
            traverse = traverse -> next;
        }
        path.push_back(traverse);
        if(path.size() < n) { return nullptr; }
        if(path.size() == n) { return head -> next; }
        
        int idx = path.size() - n;
        path[idx - 1] -> next = path[idx] -> next;
        return head;
    }
};
