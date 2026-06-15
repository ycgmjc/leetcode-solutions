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
        int k = lists.size();
        if (k == 0) return nullptr;

        vector<ListNode*> traverse;
        for(ListNode* head : lists) {
            traverse.push_back(head);
        }

        vector<ListNode*> merged;
        
        while(true) {
            ListNode* minNode = nullptr;
            int minIndex = -1;
            
            for(int i = 0; i < k; i++) {
                ListNode* node = traverse[i];
                if(node == nullptr) { continue; }

                if(minNode == nullptr || node->val < minNode->val) {
                    minNode = node;
                    minIndex = i;
                }
            }
            
            if(minNode == nullptr) { break; }
            
            merged.push_back(minNode);
            
            traverse[minIndex] = traverse[minIndex]->next; 
        }

        if (merged.empty()) return nullptr;

        for(int i = 0; i < merged.size() - 1; i++) {
            merged[i]->next = merged[i + 1];
        }
        
        merged.back()->next = nullptr; 

        return merged[0];
    }
};
