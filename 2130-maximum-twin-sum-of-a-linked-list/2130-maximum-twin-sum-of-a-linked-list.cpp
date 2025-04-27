
class Solution {
public:
    int pairSum(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(mid != NULL){
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        int result = 0;
        ListNode* curr = head;

        while(prev != NULL){
            result = max(result, curr->val + prev->val);
            curr =curr->next;
            prev = prev->next;
        }
        return result;
    }
};