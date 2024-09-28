# Section 4: Data Structures & STL Containers

## What is a Container?

A container is an object that stores a collection of other objects (elements).

Containers manage the storage space for their elements and provide member functions to access them (mostly through iterators), similar to the Collection package in Java.

Note that an iterator is an important concept that provides instructions to traverse an iterable container (analogous to the Iterator interface in Java).

**Examples**: Stack, Map, Vector, Queue, etc.

### Container Categories

- **Sequence Containers**: Store data linearly in a sequence, where the order of insertion is maintained (e.g., Array, Vector, Deque, Forward List, List).
- **Associative Containers**: Use tree-like structures to store data, where the elements are automatically ordered by keys (e.g., Set, Map, Multiset, Multimap).
- **Unordered Associative Containers**: Similar to associative containers but store data in an unordered fashion using hash tables for faster access (e.g., Unordered Set, Unordered Map, Unordered Multiset, Unordered Multimap).
- **Container Adaptors**: Provide a simplified, specialized interface for storing data in a specific way (e.g., Stack, Queue, Priority Queue).

## Array

### Classical Array

- Fixed size, defined using basic syntax.
- Passed by reference (as a pointer).
- Lacks built-in member functions and safety features.
- Sort using `std::sort(arr, arr + size)`.

### STL Array (`std::array`)

- Fixed size, but is part of the STL with additional functionalities.
- Passed by reference, retaining size information; can also be passed by value.
- Provides member functions like `.size()`, bounds checking with `.at()`, and iterators for enhanced usability.
- Can be declared as `const` to prevent modifications, ensuring data integrity.
- Sort using `std::sort(arr.begin(), arr.end())`.

## Vector

- Dynamic arrays with the ability to resize themselves automatically when an element is inserted.
- Contiguous storage locations; reallocation happens when the underlying array is full.
- Some common methods are `[]` (an overloaded operator for indexing), `clear()`, `pop_back()`, `push_back()`, `reverse()`, and `size()`.

## Deque

- Double-ended queue is sequence container with dynamic sizes that can be expanded or contracted on both ends (front or back)
- Deques are not guaranteed to store all its elements in contiguoug storage locations: accessing elements in a deque by offsetting a pointer to another element causes undefined behavior.
- Elements of a deque can be scattered in different chunks of storage
