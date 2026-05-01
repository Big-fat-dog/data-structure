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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. 创建虚拟头节点，专门治各种头节点变动的疑难杂症
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 2. 快指针先走 n 步，拉开和慢指针的距离
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 3. 快慢指针一起走，直到快指针到达链表末尾
        // 此时慢指针刚好停在“倒数第 n+1 个节点”（也就是目标节点的前驱）
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 4. 删除目标节点（跳过它）
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // 记得释放被删节点的内存

        // 5. 获取新头节点并释放虚拟节点
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};