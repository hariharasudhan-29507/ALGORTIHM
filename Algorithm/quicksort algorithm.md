# Quick Sort

## Description
Quick Sort is a divide-and-conquer, comparison-based sorting algorithm. It selects a "pivot" element, partitions the array into elements less than and greater than the pivot, then recursively sorts the partitions. It is efficient on average and widely used in practice.

---

## Algorithm: Partition 

Partition(arr[low..high])
//Output: index p where pivot is placed, arr partitioned around pivot

pivot ← arr[high]
i ← low − 1
FOR j ← low TO high − 1 DO
&nbsp;&nbsp;&nbsp;&nbsp;IF arr[j] ≤ pivot THEN
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← i + 1
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Swap arr[i] and arr[j]
&nbsp;&nbsp;&nbsp;&nbsp;END IF
END FOR
Swap arr[i + 1] and arr[high]
Return i + 1

---

## Algorithm: QuickSort 

QuickSort(arr[0..n-1], low, high)
//Output: arr[] sorted in non-decreasing order

IF low < high THEN
&nbsp;&nbsp;&nbsp;&nbsp;p ← Partition(arr, low, high)
&nbsp;&nbsp;&nbsp;&nbsp;QuickSort(arr, low, p − 1)
&nbsp;&nbsp;&nbsp;&nbsp;QuickSort(arr, p + 1, high)
END IF

Return arr[]

---

## Time Complexity

| Case        | Complexity   | Explanation |
|-------------|--------------|-------------|
| **Best**    | Θ(n log n)   | Balanced partitions lead to O(log n) recursion depth and O(n) work per level. |
| **Average** | Θ(n log n)   | Random data typically produces balanced partitions on average. |
| **Worst**   | Θ(n^2)       | Highly unbalanced partitions (e.g., already sorted with bad pivot choice) lead to O(n) depth and O(n^2) work. |

## Space Complexity

| Type          | Complexity | Explanation |
|---------------|------------|-------------|
| **Input**     | O(n)       | The array of n elements being sorted in-place. |
| **Auxiliary** | O(log n)   | Average recursion stack depth is O(log n); worst-case O(n) if partitions are unbalanced. |

---

## Properties
- Stable: No (default in-place Quick Sort is not stable).  
- In-place: Yes (uses constant extra space besides recursion stack).  
- Best used: Large arrays where average-case performance is important; consider randomized pivot or median-of-three to avoid worst-case behavior.
