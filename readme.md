# Doubly Linked List (DLL) in C++

This repository contains an implementation of a **Doubly Linked List (DLL)** in C++. The list supports efficient insertion and deletion at both ends using `head` and `tail` pointers.

## Features 

- **push_back(ty val)** → Add a node at the end (**O(1)**)
- **pop_back()** → Remove the last node (**O(1)**)
- **push_front(ty val)** → Add a node at the beginning (**O(1)**)
- **pop_front()** → Remove the first node (**O(1)**)
- **size()** → Return the number of nodes (**O(1) with counter, O(n) without**)
- **clear()** → Delete all nodes
- **insert(int index, ty val)** → Insert a node at a given position
- **erase(int index)** → Remove a node at a given index
- **operator[](int index)** → Access elements like an array
- **Destructor** → Ensures no memory leaks


