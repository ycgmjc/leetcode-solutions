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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) { return head; }

        vector<int> mold;
        while(head != nullptr) {
            mold.push_back(head -> val);
            head = head -> next;
        }

        sort(mold.begin(), mold.end());

        ListNode* new_head = new ListNode(mold[0]);
        ListNode* traverse = new_head;
        for(int i = 1; i < mold.size(); i++) {
            ListNode* temp = new ListNode(mold[i]);
            traverse -> next = temp;
            traverse = traverse -> next;
        }

        return new_head;
    }
};
