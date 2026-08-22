struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 处理空链表或只有一个节点的情况
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 快指针每次走两步，慢指针每次走一步
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 慢指针走一步
            fast = fast->next->next;    // 快指针走两步
            
            if (slow == fast) {         // 相遇说明有环
                return true;
            }
        }
        
        return false;  // 快指针到达末尾，无环
    }
};