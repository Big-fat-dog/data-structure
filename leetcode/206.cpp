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
        // 处理空链表,只有一个节点的情况
        if (head == nullptr||head->next==nullptr)
            return head;
        //收集所有有效节点
        stack<ListNode*> address;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            address.push(temp);
            temp=temp->next;
        }
        head=temp;
        int n=address.size();
        for(int i=0;i<n;i++){
            if(!address.empty())
            {temp->next=address.top();
            temp=temp->next;
            address.pop();}
            else{
                break;
            }
        }
        temp->next=nullptr;
        return head;
    }
};