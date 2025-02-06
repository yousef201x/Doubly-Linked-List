#include <iostream>
#include "DLL.h"

void testInsertionAndDeletion() {
    DLL<int> list;

    // Insert elements at different positions
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.insert(1, 15); // Insert in the middle
    list.insert(0, 5);  // Insert at the head
    list.insert(list.size(), 40); // Insert at the tail

    std::cout << "After multiple insertions: Size = " << list.size() << " (Expected: 6)\n";

    // Remove elements
    list.pop_front();
    std::cout << "After pop_front: Size = " << list.size() << " (Expected: 5)\n";
    list.pop_back();
    std::cout << "After pop_back: Size = " << list.size() << " (Expected: 4)\n";
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back(); // Should handle empty list safely

    std::cout << "After multiple pops: Empty = " << list.empty() << " (Expected: 1)\n";
}

void testEdgeCases() {
    DLL<int> list;

    // Edge case: insert in an empty list
    list.insert(0, 100);
    std::cout << "Insert into empty list: Size = " << list.size() << " (Expected: 1)\n";

    // Edge case: pop from an empty list
    list.clear();
    list.pop_front();
    list.pop_back();
    std::cout << "Pop from empty list: Empty = " << list.empty() << " (Expected: 1)\n";

    // Edge case: inserting at out-of-bound index should not crash
    list.push_back(1);
    list.push_back(2);
    list.insert(100, 50); // Invalid index, should handle gracefully
    std::cout << "Insert at out-of-bounds index: Size = " << list.size() << " (Expected: 3)\n";
}

void testStress() {
    DLL<int> list;

    // Insert 100,000 elements
    for (int i = 0; i < 100000; i++) {
        list.push_back(i);
    }
    std::cout << "Inserted 100,000 elements: Size = " << list.size() << "\n";

    // Delete 100,000 elements
    while (!list.empty()) {
        list.pop_front();
    }
    std::cout << "Removed 100,000 elements: Empty = " << list.empty() << "\n";
}

int main() {
    std::cout << "Running complex tests...\n";

    testInsertionAndDeletion();
    testEdgeCases();
    testStress();

    std::cout << "All tests completed!\n";
    return 0;
}
