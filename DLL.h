#ifndef DLL_DLL_H
#define DLL_DLL_H

template <typename ty>

class DLL {

    struct Node{
        Node* prev,next;
        ty val;

        Node(ty val) : prev(nullptr) , next(nullptr),val(val){}
        Node(ty val , Node* prev) : prev(prev) , next(nullptr),val(val){}

    };

protected:
    Node* head , tail;
public:
    DLL() : head(nullptr), tail(nullptr){}

    bool empty(){
        return head == nullptr && tail == nullptr ;
    }

    void push_back(ty val){
        if(this->empty()){
            head = tail = new Node(val);
            return;
        }

        tail = tail->next= new Node(val,tail);
    }

    void pop_back(){
        if(this->empty()){
            return;
        }

        if(this->head->next == nullptr){
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
   }
};


#endif //DLL_DLL_H
