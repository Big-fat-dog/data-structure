#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 处理空链表和一个节点的情况
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *temp = head;
        unordered_map<ListNode *, int> mylist;
        int index = 0;
        while (temp != nullptr)
        {
            mylist[temp]++;
            if (mylist[temp] == 2)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};