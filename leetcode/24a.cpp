struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* pre = dummy;
        if(head==nullptr)return nullptr;
        while(pre->next&&pre->next->next){
            ListNode* first = pre->next;
            ListNode* second = pre->next->next;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
        }
        return dummy->next;
    }
};