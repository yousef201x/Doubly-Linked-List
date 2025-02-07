#include <iostream>
#include "DLL.h" // Your implementation

void test_push_back() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    std::cout << "Test push_back: " << (list[0] == 10 && list[1] == 20 && list[2] == 30 ? "PASSED" : "FAILED") << "\n";
}

void test_push_front() {
    DLL<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    std::cout << "Test push_front: " << (list[0] == 10 && list[1] == 20 && list[2] == 30 ? "PASSED" : "FAILED") << "\n";
}

void test_pop_back() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    std::cout << "Test pop_back: " << (list.size() == 1 && list[0] == 10 ? "PASSED" : "FAILED") << "\n";
}

void test_pop_front() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    std::cout << "Test pop_front: " << (list.size() == 1 && list[0] == 20 ? "PASSED" : "FAILED") << "\n";
}

void test_insert() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(30);
    list.insert(1, 20);
    std::cout << "Test insert: " << (list[0] == 10 && list[1] == 20 && list[2] == 30 ? "PASSED" : "FAILED") << "\n";
}

void test_erase() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.erase(1);
    std::cout << "Test erase: " << (list[0] == 10 && list[1] == 30 ? "PASSED" : "FAILED") << "\n";
}

void test_clear() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    std::cout << "Test clear: " << (list.empty() ? "PASSED" : "FAILED") << "\n";
}

void test_copy_constructor() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);

    DLL<int> copy(list); // Using copy constructor

    std::cout << "Test copy constructor: " << (copy.size() == 2 && copy[0] == 10 && copy[1] == 20 ? "PASSED" : "FAILED") << "\n";
}

void test_iterator() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    DLL<int>::iterator it;
    it = list.start();

    bool passed = (*it == 10);
    ++it;
    passed &= (*it == 20);
    ++it;
    passed &= (*it == 30);

    std::cout << "Test iterator: " << (passed ? "PASSED" : "FAILED") << "\n";
}

int main() {
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_insert();
    test_erase();
    test_clear();
    test_copy_constructor();
    test_iterator();

    return 0;
}
