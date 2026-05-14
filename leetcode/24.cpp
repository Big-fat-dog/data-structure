

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 处理空链表和一个节点的链表
        if (head == nullptr || head->next == nullptr)
            return head;
        // 处理其他情况
        // int counter = 1;
        ListNode *before = nullptr;
        ListNode *current = head;
        ListNode *then = current->next;
        while (current != nullptr)
        {
            // counter++;
            if (then == nullptr)
                break;
            if (current == head)
            {
                head = then;
            }
            current->next = then->next;
            then->next = current;
            if (before != nullptr)
                before->next = then;

            before = current;
            current = current->next;
            if (current == nullptr)
                break;
            then = current->next;
        }
        return head;
    }
};