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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) { return head; }
        
        ListNode* new_head = head -> next;
        head -> next = new_head -> next;
        new_head -> next = head;
        while(head -> next != nullptr && head -> next -> next != nullptr) {
            ListNode* temp = head -> next;
            head -> next = temp -> next;
            temp -> next = head -> next -> next;
            head -> next -> next = temp;
            head = head -> next -> next;
        }

        return new_head;
    }
};
