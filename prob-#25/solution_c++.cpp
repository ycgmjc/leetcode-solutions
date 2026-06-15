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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* new_head = nullptr;
        ListNode* tail_of_prev_group = nullptr;

        while (head != nullptr) {
            ListNode* temp = head;
            vector<ListNode*> section;

            for (int i = 0; i < k; i++) {
                if (temp == nullptr) break;
                section.push_back(temp);
                temp = temp->next;
            }

            if (section.size() < k) {
                if (tail_of_prev_group != nullptr) {
                    tail_of_prev_group->next = head; 
                }
                break;
            }

            if (new_head == nullptr) {
                new_head = section.back(); 
            }

            if (tail_of_prev_group != nullptr) {
                tail_of_prev_group->next = section.back();
            }

            for (int i = k - 1; i > 0; i--) {
                section[i]->next = section[i - 1];
            }

            section[0]->next = temp;

            tail_of_prev_group = section[0];
            head = temp;
        }

        return new_head == nullptr ? head : new_head;
    }
};
