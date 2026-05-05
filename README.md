# Tree Application – Student Record Management using BST

## Scenario
In a college, student records such as ID, name, and marks need to be stored and managed efficiently. The system should allow insertion of new student records, searching for a student by ID, and displaying all records in sorted order. A Binary Search Tree (BST) is used to organize the data based on student IDs.

---

## Justification
Binary Search Tree is used because:
- It allows fast searching of student records using unique IDs.
- It maintains data in sorted order automatically.
- It supports dynamic insertion without fixed size.
- It is more efficient than linear search methods for large datasets.

---

## Operations Implemented

1. Insert student record (ID, Name, Marks)  
2. Search student by ID  
3. Display all records (sorted using inorder traversal)  

---

## Algorithm

### 1. Insertion
- If root is NULL → create a new node  
- If ID < root ID → insert in left subtree  
- If ID > root ID → insert in right subtree  

---

### 2. Search
- If root is NULL → student not found  
- If ID matches → display student details  
- If ID < root → search left  
- Else → search right  

---

### 3. Inorder Traversal
- Traverse left subtree  
- Visit root node (print data)  
- Traverse right subtree  
→ This prints student records in ascending order of ID  

---

## Time Complexity

| Operation  | Average Case | Worst Case |
|-----------|-------------|-----------|
| Insertion | O(log n)    | O(n)      |
| Search    | O(log n)    | O(n)      |
| Traversal | O(n)        | O(n)      |

---

