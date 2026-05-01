

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fakeone = new ListNode(0, head);
        ListNode *temp = head;
        // 处理只有一个节点的情况
        if (head->next == nullptr && n == 1)
        {
            delete head;
            return nullptr;
        }
        int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        ListNode *before = fakeone;

        for (int i = 0; i < size - n; i++)
        {
            before = temp;
            temp = temp->next;
        }
        before->next = temp->next;
        if (size == n)
        {
            head = temp->next;
        }
        delete fakeone;
        delete temp;
        return head;
    }
};