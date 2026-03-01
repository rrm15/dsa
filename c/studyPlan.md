# C Programming Assessment Study Plan

**Date:** March 2, 2026 | 8:30 AM - 10:30 AM | TLGL3 | 50 Marks

---

## Day 1 (Today - March 1) — Revise Core Topics + Practice

You have ~20 hours. Focus on understanding, not memorizing.

---

### Topic 1: Functions & Recursion

**Key concepts to know:**
- Call by value vs call by reference
- How recursion works (base case + recursive case)
- Stack frames during recursion
- When to use recursion vs iteration

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 1 | Easy | Write a function to find GCD of two numbers using recursion |
| 2 | Easy | Write a function that takes an array and its size, returns the sum |
| 3 | Medium | Write a recursive function to check if a string is a palindrome |
| 4 | Medium | Tower of Hanoi for n disks — print each move |
| 5 | Tough | Write a recursive function to generate all permutations of a string |

---

### Topic 2: Arrays & Strings

**Key concepts to know:**
- Array declaration, initialization, traversal
- 2D arrays and how they're stored in memory
- String functions: strlen, strcpy, strcmp, strcat
- Difference between char array and string literal

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 6 | Easy | Rotate an array left by k positions |
| 7 | Easy | Count vowels and consonants in a string |
| 8 | Medium | Find the second largest element in an array without sorting |
| 9 | Medium | Check if two strings are anagrams of each other |
| 10 | Tough | Multiply two matrices and print the result |

---

### Topic 3: Pointers

**Key concepts to know:**
- Pointer declaration, dereferencing
- Pointer arithmetic
- Pointer to array, array of pointers
- Passing pointers to functions
- Double pointers (pointer to pointer)

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 11 | Easy | Swap two numbers using pointers |
| 12 | Easy | Reverse an array using pointers |
| 13 | Medium | Write a function that returns multiple values using pointer parameters |
| 14 | Medium | Implement your own strlen and strcmp using pointers |
| 15 | Tough | Sort an array of strings using an array of pointers |

---

### Topic 4: Structures

**Key concepts to know:**
- Declaring and initializing structs
- Array of structures
- Passing structs to functions (by value and by pointer)
- Nested structures
- typedef with structs

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 16 | Easy | Create a Student struct with name, roll, marks — input and display |
| 17 | Medium | Sort an array of Student structs by marks using bubble sort |
| 18 | Tough | Create a nested struct (Address inside Student), input and display all fields |

---

### Topic 5: Unions, Function Pointers & File Operations

**Key concepts to know:**
- Difference between struct and union (memory sharing)
- sizeof union vs sizeof struct
- Function pointer syntax and usage
- fopen, fclose, fprintf, fscanf, fread, fwrite
- ifstream/ofstream if C++ is allowed

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 19 | Easy | Show the difference between struct and union with sizeof |
| 20 | Medium | Write a program that reads a file and counts lines, words, characters |
| 21 | Medium | Use a function pointer array to make a menu-driven calculator |
| 22 | Tough | Read student records from a file, sort them, write sorted output to another file |

---

### Topic 6: Searching & Sorting

**Key concepts to know:**
- Linear search, binary search
- Bubble sort, selection sort, insertion sort
- Time complexity basics (which is O(n), O(n²), O(log n))
- When to use what

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 23 | Easy | Linear search — return index or -1 |
| 24 | Easy | Bubble sort an integer array |
| 25 | Medium | Binary search (iterative and recursive) |
| 26 | Medium | Selection sort an array of strings alphabetically |
| 27 | Tough | Sort a struct array by multiple fields (first by marks, then by name) |

---

### Topic 7: Linked List, Stack & Queue

**Key concepts to know:**
- Singly linked list: create, insert, delete, display, reverse
- Stack using array and linked list (push, pop, peek)
- Queue using array and linked list (enqueue, dequeue)
- Where to use stack vs queue

**Practice questions:**

| # | Difficulty | Question |
|---|-----------|----------|
| 28 | Easy | Create a singly linked list with insert at end and display |
| 29 | Easy | Implement a stack using an array with push, pop, display |
| 30 | Medium | Reverse a singly linked list |
| 31 | Medium | Implement a queue using a linked list |
| 32 | Tough | Check if parentheses in an expression are balanced using a stack |
| 33 | Tough | Detect a cycle in a linked list |

---

## MCQ Topics to Revise (Quick Glance)

These show up as tricky MCQs. Know these cold:

- What happens when you access array out of bounds
- sizeof(struct) vs sizeof(union)
- Pointer arithmetic: what does `ptr + 1` actually add
- What does `*p++` vs `(*p)++` vs `*(p++)` do
- Recursion output tracing (they give code, you predict output)
- Pass by value vs pass by reference behavior
- fopen modes: "r", "w", "a", "r+", "w+", "a+"
- Stack overflow from infinite recursion
- What is a dangling pointer, wild pointer, null pointer
- Linked list: what happens if you lose the head pointer

---

## Strategy for the Exam

1. **Start with the easy question** — finish it in 15-20 min, get full marks
2. **Medium question next** — take 30-40 min, focus on correctness
3. **Tough question** — even partial code gets marks, write what you can
4. **MCQs** — do them in the remaining time, eliminate wrong options
5. **Always handle edge cases** — empty array, null pointer, n=0

---

## How This Works

1. Pick any question from above
2. Create a new `.c` file in `F:\Code\dsa\c\` and write your solution
3. Drop the file in chat
4. I'll review it — raw, honest feedback + how to improve
5. Move to the next one

Start wherever you feel weakest. Good luck.
