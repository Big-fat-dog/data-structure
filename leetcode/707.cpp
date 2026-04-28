class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };

public:
    int size;
    Node* head;
    MyLinkedList() : size(0), head(nullptr) {}
    int get(int index) {
        if (index < 0 || index >= this->size)
            return -1;
        Node* temp = this->head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val);
        // 处理空链表
        if (this->size == 0) {
            this->head = newnode;
            this->size++;
            return;
        }
        // 处理非空链表
        else {
            Node* temp = this->head;
            newnode->next = temp;
            temp->prev = newnode;
            this->head = newnode;
            this->size++;
        }
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val);
        // 处理空链表
        if (this->size == 0) {
            this->head = newnode;
            this->size++;
            return;
        }
        // 处理其他情况
        Node* temp = head;
        while (temp->next !=nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        this->size++;
    }

    void addAtIndex(int index, int val) {
        if (index > this->size || index < 0) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == this->size) {
            addAtTail(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        newnode->prev = temp->prev;
        newnode->next = temp;
        temp->prev->next = newnode;
        temp->prev = newnode;
        this->size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->size)
            return;
        Node* temp = head;
        if (index == 0) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            this->size--;
            return;
        }
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        this->size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */