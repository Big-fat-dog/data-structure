#include<iostream>
using namespace std;
int front=-1;
int rear=-1;
int A[4];
bool isEmpty(){
    if(front==-1&&rear==-1){
        return true;
    }
    else return false;
}
void Enqueue(int x,int N){
    //数组饱满的情况
    if((rear+1)%N==front)return;
    //空队列情况
    else if(isEmpty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%N;
    }
    A[rear]=x;
}
void Dequeue(int N){
    if(isEmpty()){
        return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%N;
    }
}
void print() {
    if (isEmpty()) {
        cout << "Empty queue\n";
        return;
    }
    int i = front;
    while (true) {
        cout << A[i] << " ";
        if (i == rear) break;          // 到达尾部就停
        i = (i + 1) % 4;          //循环数组下一位
    }
    cout << endl;
}
int main(){
    int n=sizeof(A) / sizeof(A[0]); //一个int类型占四个字节，这里整除，不能直接用sizeof会返回16！
    Enqueue(1,n);
    Enqueue(2,n);
    Enqueue(3,n);
    Enqueue(4,n);
    print();
    Dequeue(n);
    Dequeue(n);
    Enqueue(5,n);
    print();
    return 0;
}