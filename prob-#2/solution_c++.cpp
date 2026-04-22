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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode;
        ListNode* endpoint = solution;
        ListNode* node_1 = l1;
        ListNode* node_2 = l2;

        int overflow = 0;
        bool node_1_end = false;
        bool node_2_end = false;

        while(true) {
            int num1 = 0;
            int num2 = 0;
            int sum = 0;

            if(!node_1_end) { num1 = node_1 -> val; }
            if(!node_2_end) { num2 = node_2 -> val; }
            
            sum = num1 + num2 + overflow;
            overflow = (num1 + num2 + overflow) / 10;

            endpoint -> next = new ListNode(sum % 10);
            endpoint = endpoint -> next;

            if(node_1 -> next == nullptr) { node_1_end = true; }
            else { node_1 = node_1 -> next; }
            if(node_2 -> next == nullptr) { node_2_end = true; }
            else { node_2 = node_2 -> next; }
            
            if(node_1_end && node_2_end && (overflow == 0)) { break; }
        }
        return solution -> next;
    }
};
