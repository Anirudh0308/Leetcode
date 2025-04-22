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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ODD = head;
        ListNode* EVEN =head->next;

        ListNode* evenStart = head->next;

        while(EVEN != NULL && EVEN-> next != NULL){
            ODD->next = EVEN ->next;
            EVEN ->next = EVEN-> next->next;

            ODD = ODD->next;
            EVEN = EVEN ->next;
        }
        ODD -> next = evenStart;

        return head;
    }
};