#ifndef DLL_DLL_H
#define DLL_DLL_H

template <typename ty>
class DLL {

    struct Node {
        Node* prev;  // Previous node
        Node* next;  // Next node
        ty val;      // Value of the node

        Node(ty val) : prev(nullptr), next(nullptr), val(val) {}
        Node(ty val, Node* prev) : prev(prev), next(nullptr), val(val) {}
    };

protected:
    Node* head, * tail;  // Pointers to head and tail
    int _size = 0;       // List size

    void increaseSize() { this->_size += 1; }  // Increment size
    void decreaseSize() { this->_size -= 1; }  // Decrement size
    void resetSize() { this->_size = 0; }      // Reset size

public:
    DLL() : head(nullptr), tail(nullptr) , _size(0) {}  // Constructor initializes an empty list

    DLL(DLL &other){
        if(other.empty()){
            return;
        }

        Node* other_itr = other.start();

        while (other != nullptr){
            this->push_back(other_itr->val);
            other_itr = other_itr->next;
        }
    }

    ~DLL() { this->clear(); }  // Destructor cleans up the list

    ty operator [](int idx){
        if (idx < 0 || idx >= this->_size) {
            throw std::out_of_range("Index out of range");
        }

        Node* itr = head;
        for (int i = 0; i < idx; i++) {
            itr = itr->next;  // Traverse to the node at the given index
        }

        return itr->val;  // Return the node at the given index
    }

    bool empty() { return head == nullptr && tail == nullptr; }  // Check if list is empty
    int size() { return this->_size; }  // Get current size
    Node* start(){return this->head;}
    Node* end(){return this->tail;}

    void push_back(ty val) {  // Add a node to the end
        if (this->empty()) {
            head = tail = new Node(val);
            this->increaseSize();
            return;
        }
        tail->next = new Node(val, tail);
        tail = tail->next;
        this->increaseSize();
    }

    void pop_back() {  // Remove node from the end
        if (this->empty()) return;
        if (this->head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            this->decreaseSize();
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        this->decreaseSize();
    }

    void push_front(ty val) {  // Add node to the front
        if (this->empty()) {
            push_back(val);
            return;
        }
        head->prev = new Node(val);
        head->prev->next = head;
        head = head->prev;
        this->increaseSize();
    }

    void pop_front() {  // Remove node from the front
        if (this->empty()) return;
        if (head->next == nullptr) {
            pop_back();
            return;
        }
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        this->decreaseSize();
    }

    void clear() {  // Clear the list
        if (this->empty()) return;
        while (head != tail) {
            pop_front();
            pop_back();
        }
        delete head;
        head = tail = nullptr;
        this->resetSize();
    }

    void insert(int index, ty val) {  // Insert a node at a given index
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

    void erase(int index) {  // Remove node at a given index
        if (this->empty()) return;
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == _size - 1) {
            pop_back();
            return;
        }
        Node* itr = head;
        for (int i = 1; i < index; i++) {
            itr = itr->next;
        }
        Node* temp = itr->next;
        itr->next = itr->next->next;
        itr->next->prev = itr;
        delete temp;
        this->decreaseSize();
    }

};

#endif //DLL_DLL_H
