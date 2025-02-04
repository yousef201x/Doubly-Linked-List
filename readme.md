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
- **find(ty val)** → Return the index of the first occurrence
- **operator[](int index)** → Access elements like an array
- **Destructor** → Ensures no memory leaks

## 📜 Flowchart: `push_back()`
The following flowchart visually describes how the `push_back()` function operates:
```html
<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width="804" height="600" src="https://edrawcloudpublicus.s3.amazonaws.com/viewer/self/7444553/share/2025-2-4/1738694386/main.svg"></iframe>

```
