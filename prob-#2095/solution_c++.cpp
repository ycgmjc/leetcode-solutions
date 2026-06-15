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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* traverse = head;
        int nodes = 1;
        while(traverse -> next != nullptr) {
            nodes += 1;
            traverse = traverse -> next;
        }
        if(nodes == 1) { return nullptr; }

        int mid_index = nodes / 2;
        traverse = head;
        for(int i = 0; i < mid_index - 1; i++) {
            traverse = traverse -> next;
        }
        traverse -> next = traverse -> next -> next;
        return head;
    }
};
