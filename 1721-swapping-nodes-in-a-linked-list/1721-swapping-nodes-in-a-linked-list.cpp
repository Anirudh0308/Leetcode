
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            if(p2 != NULL){
                p2 = p2->next;
            }
            k--;
            if(k == 0){
                p1 = temp;
                p2 = head;
            }
            temp = temp->next;
        }
        swap(p1->val, p2->val);

        return head;
    }
};