#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //先拿到链表长度
        ListNode *temp = head;
        int size = 0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        temp=head;
        //计算要删除节点走的步数
        int num=size-n;
        if(n==size){
            head=head->next;
            delete temp;
        }
        else if(n==1){
            for(int i=0;i<num-1;i++){
                temp=temp->next;
            }
            ListNode* then = temp->next;
            temp->next=nullptr;
            delete then;
        }else
        {
            for(int i = 0;i<num-1;i++){
                temp=temp->next;
            }
            ListNode * tar = temp->next;
            ListNode * then = tar->next;
            temp->next = then;
            delete tar;
        }
         return head;
    }
};