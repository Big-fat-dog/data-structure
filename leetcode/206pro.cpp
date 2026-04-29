#include<iostream>
#include<stack>
using namespace std;
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
    ListNode* reverseList(ListNode* head) {
        //处理空链表和一个节点的情况
        if(head==nullptr)return head;
        //三指针法
        ListNode* before=nullptr;
        ListNode* current=head;
        ListNode* then=nullptr;
        //三指针法处理其他节点
        while(current!=nullptr){
            then=current->next;
            current->next=before;
            before=current;
            current=then;
        }
        return before;
        

    }
};