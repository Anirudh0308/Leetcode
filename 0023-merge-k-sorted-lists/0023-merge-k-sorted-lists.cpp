
class Solution {
public:

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1 -> val <= l2 -> val){
            l1->next = mergeTwoSortedLists(l1 -> next, l2);
            return l1;
        }else{
             l2->next = mergeTwoSortedLists(l1,l2 -> next);
            return l2;
        }
        return NULL;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*> &lists){
        if(start >end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        int mid = start + (end - start) /2;
        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid+1, end, lists);
        return mergeTwoSortedLists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) 
            return NULL;

        return partitionAndMerge(0, k-1, lists);
    }

};





// struct Compare {
//     bool operator()(ListNode* a, ListNode* b) {
//         return a->val > b->val;  // Min-Heap based on node values
//     }
// };

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
//         for (auto node : lists) {
//             if (node) pq.push(node);  // Only push non-null nodes
//         }

//         ListNode* dummy = new ListNode(0);
//         ListNode* tail = dummy;

//         while (!pq.empty()) {
//             ListNode* minNode = pq.top(); pq.pop();
//             tail->next = minNode;
//             tail = tail->next;
//             if (minNode->next) pq.push(minNode->next);
//         }

//         return dummy->next;
//     }
// };