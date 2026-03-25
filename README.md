# Singly-linked-list Implementation 
 *NAME-Javan Otieno
 *REG NO-Eb3/67256/23
Cosc 333 Assignment_singly linked list implementation 

## Description

This program implements a **singly linked list** from scratch in C++ without using any built-in data structures. The implementation includes:

-Insertion - At beginning, end, and at specific positions
- Deletion - By value and by position
- Search - Find a value and return its position
- Traversal - Display all elements
- Performance Metrics - Track comparisons and operations


## How the Algorithm Works

### Node Structure
Each node contains:
- `data` - The actual value stored
- `next` - Pointer to the next node

### Operations

| Operation | How it works | Time Complexity |

| Insert at Beginning | Create new node, point to current head, update head | O(1) |
| Insert at End** | Traverse to last node, add new node at the end | O(n) |
| Insert at Position | Traverse to position-1, insert new node | O(n) |
| Delete by Value | Search for value, remove node if found | O(n) |
| Delete at Position | Traverse to position-1, remove node | O(n) |
| Search | Traverse list comparing each value | O(n) |
| Traversal | Visit each node and display data | O(n) |

## Step-by-Step Demonstration 

Initial: Empty list

Step 1: Insert 10 at beginning

Step 2: Insert 20 at end

Step 3: Insert 5 at beginning

Step 4: Insert 15 at position 2

Step 5: Search for 15

Step 6: Delete 10 by value

Step 7: Delete at position 1

Final: List contains [5, 20]

## Complexity Analysis

### Time Complexity Table

| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Insert at Beginning | O(1) | O(1) | O(1) |
| Insert at End | O(1) | O(n) | O(n) |
| Insert at Position | O(1) | O(n) | O(n) |
| Delete by Value | O(1) | O(n) | O(n) |
| Delete at Position | O(1) | O(n) | O(n) |
| Search | O(1) | O(n) | O(n) |
| Traversal | O(n) | O(n) | O(n) |

### Space Complexity
O(n) - Each node uses constant space, and memory grows linearly with the number of node

### Commit History
- Commit 1: Initial commit: Complete linked list implementation
- Commit 2: Add step-by-step demonstration and performance testing
- Commit 3: Add README documentation

---

## Conclusion

This implementation successfully demonstrates:
-  Complete singly linked list with all required operations
-  No built-in data structures used
-  Performance metrics tracking
-  Complexity analysis matching theoretical expectations
-  Testing across multiple input sizes
-  Regular Git commits showing development process 

Student: Javan Otieno  
Registration: EB3.67256.23  
Date: March 25, 2026
