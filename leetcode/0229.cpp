
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 处理空链表的情况
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int size1 = 0;
        int size2 = 0;
        while (temp1 != nullptr)
        {
            size1++;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr)
        {
            size2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        // 移动指针直至末尾对齐
        if (size1 >= size2)
        {
            for (int i = 0; i < size1 - size2; i++)
            {
                temp1 = temp1->next;
            }
        }
        else
        {
            for (int i = 0; i < size2 - size1; i++)
            {
                temp2 = temp2->next;
            }
        }
        while (temp1 != nullptr)
        {
            if (temp1 != temp2)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                return temp1;
            }
        }
        return nullptr;
    }
};