# 🎨 Algorithms & Implementations Repository

Welcome to the **Algorithms Repository**! This repository is a centralized, educational, and highly structured reference collection of key computer science algorithms. To make learning and usage as seamless as possible, algorithm concepts (found in the [`Algorithm/`](Algorithm/) directory) are documented separately from their clean C++ implementations (found in the [`Implementation/`](Implementation/) directory).

---

## 📌 Table of Contents
1. [📊 Quick Algorithm Comparison Matrix](#-quick-algorithm-comparison-matrix)
2. [🔍 Detailed Algorithm Explanations](#-detailed-algorithm-explanations)
   - [📍 Closest Pair of Points](#1-closest-pair-of-points)
   - [🕸️ Floyd-Warshall Algorithm](#2-floyd-warshall-algorithm)
   - [🥞 Heap Sort](#3-heap-sort)
   - [🐎 Horspool's String Matching](#4-horspools-string-matching)
   - [🌳 Huffman Coding](#5-huffman-coding)
   - [📥 Insertion Sort](#6-insertion-sort)
   - [🔀 Merge Sort](#7-merge-sort)
   - [👑 N-Queens Problem](#8-n-queens-problem)
   - [⚡ Quick Sort](#9-quick-sort)
3. [⚙️ How to Compile and Run](#-how-to-compile-and-run)
4. [👥 Author & Contact Info](#-author--contact-info)

---

## 📊 Quick Algorithm Comparison Matrix

This table summarizes every algorithm in the repository to provide an immediate overview of paradigms and complexities at a single glance.

| # | Algorithm Name | Category / Paradigm | Best Case | Average Case | Worst Case | Auxiliary Space | Stable? | In-Place? |
|---|----------------|---------------------|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | **Closest Pair** | Computational Geometry (Brute Force) | $\Theta(n^2)$ | $\Theta(n^2)$ | $\Theta(n^2)$ | $O(1)$ | N/A | Yes |
| 2 | **Floyd-Warshall** | Dynamic Programming (Graph) | $\Theta(n^3)$ | $\Theta(n^3)$ | $\Theta(n^3)$ | $O(1)$ (in-place update) | N/A | Yes |
| 3 | **Heap Sort** | Selection-based Sorting (Binary Heap) | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $O(1)$ | No | Yes |
| 4 | **Horspool** | String Pattern Matching | $\Theta(n / m)$ | $\Theta(n)$ | $\Theta(n \times m)$ | $O(1)$ (shift table: $O(|\Sigma|)$) | N/A | Yes |
| 5 | **Huffman Coding** | Greedy (Data Compression) | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | N/A | No |
| 6 | **Insertion Sort** | Insertion-based Sorting | $\Theta(n)$ | $\Theta(n^2)$ | $\Theta(n^2)$ | $O(1)$ | Yes | Yes |
| 7 | **Merge Sort** | Divide and Conquer Sorting | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $O(n)$ | Yes | No |
| 8 | **N-Queens** | Backtracking (Constraint Satisfaction) | $O(1)$ (first sol) | $O(n!)$ | $O(n!)$ | $O(n)$ (recursion stack) | N/A | Yes |
| 9 | **Quick Sort** | Divide and Conquer Sorting | $\Theta(n \log n)$ | $\Theta(n \log n)$ | $\Theta(n^2)$ | $O(\log n)$ (avg stack) | No | Yes |

*Note: For Horspool, $n$ is text length and $m$ is pattern length. For N-Queens, $n$ is board size.*

---

## 🔍 Detailed Algorithm Explanations

---

### 1. Closest Pair of Points
* **Description:** Finds the pair of points in a 2D plane that are closest to each other according to the Euclidean distance formula: $d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$.
* **How It Works:** This implementation employs an exhaustive brute-force search comparing all $n(n-1)/2$ unique pairs of points.
* **Key Files:**
  - Concept & Notes: [`Algorithm/closestpair algorithm.md`](Algorithm/closestpair%20algorithm.md)
  - Implementation: [`Implementation/closestpair.cpp`](Implementation/closestpair.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/closestpair.cpp -o closestpair
  ./closestpair
  ```

---

### 2. Floyd-Warshall Algorithm
* **Description:** A dynamic programming approach to find the shortest paths between all pairs of vertices in a weighted, directed graph (supporting positive or negative edge weights, but no negative cycles).
* **How It Works:** Iteratively updates a distance matrix `dist[i][j]` by considering each vertex $k$ as an intermediate step: `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`.
* **Key Files:**
  - Concept & Notes: [`Algorithm/floyd algorithm.md`](Algorithm/floyd%20algorithm.md)
  - Implementation: [`Implementation/floyd.cpp`](Implementation/floyd.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/floyd.cpp -o floyd
  ./floyd
  ```

---

### 3. Heap Sort
* **Description:** A comparison-based sorting algorithm using a Binary Max-Heap.
* **How It Works:**
  1. Build a Max-Heap from the input array in $O(n)$ time.
  2. Repeatedly swap the root (maximum element) with the last element of the heap, decrement the heap size, and restore the max-heap property via an iterative heapify operation.
* **Key Files:**
  - Concept & Notes: [`Algorithm/heapsort algorithm.md`](Algorithm/heapsort%20algorithm.md)
  - Implementation: [`Implementation/heapsort.cpp`](Implementation/heapsort.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/heapsort.cpp -o heapsort
  ./heapsort
  ```

---

### 4. Horspool's String Matching
* **Description:** A highly efficient single-pattern string matching algorithm, which is a simplified version of Boyer-Moore.
* **How It Works:** Precomputes a shift table of size 256 for all ASCII characters based on the pattern's characters. It then aligns the pattern with the text and performs right-to-left character comparison, jumping forward based on the shift table on mismatch.
* **Key Files:**
  - Concept & Notes: [`Algorithm/horspool algorithm.md`](Algorithm/horspool%20algorithm.md)
  - Implementation: [`Implementation/horspool.cpp`](Implementation/horspool.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/horspool.cpp -o horspool
  ./horspool
  ```

---

### 5. Huffman Coding
* **Description:** A greedy data compression algorithm that assigns variable-length binary codes to characters based on their frequency of occurrence.
* **How It Works:**
  1. Create leaf nodes for each character and insert them into a priority queue/sorted list.
  2. Repeatedly extract the two lowest-frequency nodes, merge them under a new internal node with a combined frequency, and reinsert.
  3. Traverse the final tree from the root to assign binary codes (0 for left branch, 1 for right branch).
* **Key Files:**
  - Concept & Notes: (No dedicated md file) - See code for direct documentation.
  - Implementation: [`Implementation/huffmancoding.cpp`](Implementation/huffmancoding.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/huffmancoding.cpp -o huffmancoding
  ./huffmancoding
  ```

---

### 6. Insertion Sort
* **Description:** A simple, intuitive, in-place sorting algorithm that is highly efficient for small datasets or nearly-sorted arrays.
* **How It Works:** Builds the sorted array element-by-element by shifting larger sorted elements to the right to make space for inserting the current key.
* **Key Files:**
  - Concept & Notes: [`Algorithm/insertionsort algorithm.md`](Algorithm/insertionsort%20algorithm.md)
  - Implementation: [`Implementation/insertionsort.cpp`](Implementation/insertionsort.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/insertionsort.cpp -o insertionsort
  ./insertionsort
  ```

---

### 7. Merge Sort
* **Description:** A stable, divide-and-conquer sorting algorithm that guarantees $O(n \log n)$ performance.
* **How It Works:** Recursively divides the array into two halves, sorts them independently, and merges the sorted halves using helper space.
* **Key Files:**
  - Concept & Notes: [`Algorithm/mergesort algorithm.md`](Algorithm/mergesort%20algorithm.md)
  - Implementation: [`Implementation/mergesort.cpp`](Implementation/mergesort.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/mergesort.cpp -o mergesort
  ./mergesort
  ```

---

### 8. N-Queens Problem
* **Description:** A classic combinatorial backtracking problem of placing $N$ chess queens on an $N \times N$ chessboard such that no two queens threaten each other.
* **How It Works:** Uses depth-first backtracking search. For each row $k$, it systematically tests placing a queen in column $i$, checks constraints (row, column, and diagonal conflicts), and recursively attempts to place queens on subsequent rows.
* **Key Files:**
  - Concept & Notes: (No dedicated md file) - See code for direct documentation.
  - Implementation: [`Implementation/Nqueens.cpp`](Implementation/Nqueens.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/Nqueens.cpp -o nqueens
  ./nqueens
  ```

---

### 9. Quick Sort
* **Description:** An extremely fast, in-place, divide-and-conquer sorting algorithm widely used in production.
* **How It Works:** Selects a "pivot" element (in this case, the last element) and partitions the array such that all elements smaller than the pivot go to its left, and all larger elements go to its right. It then recursively sorts the left and right subarrays.
* **Key Files:**
  - Concept & Notes: [`Algorithm/quicksort algorithm.md`](Algorithm/quicksort%20algorithm.md)
  - Implementation: [`Implementation/quicksort.cpp`](Implementation/quicksort.cpp)
* **Compile & Run:**
  ```bash
  g++ -O3 Implementation/quicksort.cpp -o quicksort
  ./quicksort
  ```

---

## ⚙️ How to Compile and Run

To compile any algorithm implementation using the standard GNU C++ compiler (`g++`), run the following command from the repository root:

```bash
g++ -O3 Implementation/<algorithm_filename>.cpp -o <executable_name>
```

For example, to run the **Quick Sort** implementation:
```bash
g++ -O3 Implementation/quicksort.cpp -o quicksort && ./quicksort
```

---

## 👥 Author & Contact Info

* **Author:** Hariharasudhan A
* **Education:** Sophomore in CSE at Mepco Schlenk Engineering College
* **Email:** sudanayyappan_bcs28@mepcoeng.ac.in
* **GitHub Profile / Contact:** Feel free to reach out via email for questions or contributions!
