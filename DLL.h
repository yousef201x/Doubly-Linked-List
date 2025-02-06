#ifndef DLL_DLL_H
#define DLL_DLL_H

template <typename ty>
class DLL {

    struct Node {
        Node* prev;
        Node* next;
        ty val;

        Node(ty val) : prev(nullptr), next(nullptr), val(val) {}
        Node(ty val, Node* prev) : prev(prev), next(nullptr), val(val) {}
    };

protected:
    Node* head, * tail;
    int _size = 0;

    void increaseSize(){
        this->_size +=1;
    }

    void decreaseSize(){
        this->_size-=1;
    }

    void resetSize(){
        this->_size = 0;
    }


public:
    DLL() : head(nullptr), tail(nullptr) {}

    bool empty() {
        return head == nullptr && tail == nullptr;
    }

    int size(){
        return this->_size;
    }

    void push_back(ty val) {
        if (this->empty()) {
            head = tail = new Node(val);
            this->increaseSize();
            return;
        }

        tail->next = new Node(val, tail);
        tail = tail->next;

        this->increaseSize();
    }

    void pop_back() {
        if (this->empty()) {
            return;
        }

        if (this->head->next == nullptr) {
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            decreaseSize();
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;

        this->decreaseSize();
    }

    void push_front(ty val) {
        if (this->empty()) {
            push_back(val);
            return;
        }

        head->prev = new Node(val);
        head->prev->next = head;
        head = head->prev;

        this->increaseSize();
    }

    void pop_front(){
        if(this->empty()){
            return;
        }

        if(head->next == nullptr){
            this->pop_back();
            return;
        }

        head = head->next;
        delete head->prev;
        head->prev = nullptr;

        this->decreaseSize();
    }

    void clear(){
        if(this->empty()){
            return;
        }

        if(head->next == nullptr){
            this->pop_back();
        }

        while (head != tail){
            this->pop_front();
            this->pop_back();
        }

        delete head;
        head = tail = nullptr;

        this->resetSize();
    }

    void insert(int index, ty val) {
        if (index <= 0) {
            push_front(val);
            return;
        }
        if (index >= _size) {
            push_back(val);
            return;
        }

        Node* itr = head;
        for (int i = 0; i < index - 1; i++) {
            itr = itr->next;
        }

        Node* newNode = new Node(val, itr);
        newNode->next = itr->next;
        itr->next->prev = newNode;
        itr->next = newNode;

        this->increaseSize();
    }

    ~DLL(){
        this->clear();
    }
};



#endif //DLL_DLL_Hs
