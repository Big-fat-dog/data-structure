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
        // 1. 创建虚拟头节点，它的 next 指向真正的 head
        ListNode* dummy = new ListNode(0, head);
        // prev 始终指向“需要交换的两个节点”的前一个节点
        ListNode* prev = dummy;

        // 2. 只要后面还有两个节点，就继续交换！
        // 这种写法直接规避了你代码里那一堆乱七八糟的空指针判断
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;       // 第一个节点
            ListNode* second = prev->next->next; // 第二个节点

            // 3. 经典的三步交换法（画图理解！）
            prev->next = second;        // 前驱节点指向第二个
            first->next = second->next; // 第一个节点指向后面剩下的
            second->next = first;       // 第二个节点指向第一个

            // 4. 指针后移，准备下一轮交换
            prev = first; // prev 移动到这一对的末尾（也就是原来的第一个）
        }

        ListNode* newHead = dummy->next;
        delete dummy; // 记得释放虚拟节点，防止内存泄漏！
        return newHead;
    }
};