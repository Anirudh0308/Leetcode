
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        for(int i=1; i<=n; i++){
            temp = temp ->next;
        }
        if(temp == NULL){
            ListNode* result = head->next;
            delete(head);
            return result;
        }
        ListNode* prev = head;

        while(temp != NULL && temp ->next !=NULL){
            prev = prev->next;
            temp = temp->next;

        }
        ListNode* delNode = prev->next;
        prev->next = prev->next->next;

        return head;
    }
};