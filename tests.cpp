#include <iostream>
#include <cassert>

#include "DLL.h"

void test_empty_list() {
    DLL<int> list;
    assert(list.empty() == true); // The list should be empty
    assert(list.size() == 0); // The size should be 0
}

void test_push_back_and_pop_back() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.size() == 2); // List size should be 2
    assert(list[0] == 10); // First element should be 10
    assert(list[1] == 20); // Second element should be 20
    list.pop_back();
    assert(list.size() == 1); // Size should be 1 after pop
    assert(list[0] == 10); // The remaining element should be 10
}

void test_push_front_and_pop_front() {
    DLL<int> list;
    list.push_front(10);
    list.push_front(20);
    assert(list.size() == 2); // List size should be 2
    assert(list[0] == 20); // First element should be 20
    assert(list[1] == 10); // Second element should be 10
    list.pop_front();
    assert(list.size() == 1); // Size should be 1 after pop
    assert(list[0] == 10); // The remaining element should be 10
}

void test_insert_and_erase() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.insert(1, 15);
    assert(list[0] == 10);
    assert(list[1] == 15); // 15 should be inserted at index 1
    list.erase(1);
    assert(list[1] == 20); // After erase, 15 should be removed
}

void test_out_of_bounds_access() {
    DLL<int> list;
    try {
        list[0]; // This should throw an exception because the list is empty
    } catch (const std::out_of_range& e) {
        assert(true); // Exception should be caught
    }
}

void test_clear() {
    DLL<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.empty() == true); // The list should be empty after clear
    assert(list.size() == 0); // Size should be 0
}

int main() {
    test_empty_list();
    test_push_back_and_pop_back();
    test_push_front_and_pop_front();
    test_insert_and_erase();
    test_out_of_bounds_access();
    test_clear();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
