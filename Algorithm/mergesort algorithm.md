# Merge Sort
 
## Description
Merge Sort is a classic divide-and-conquer sorting algorithm. It recursively splits the input array into two halves, sorts each half independently, and then merges the two sorted halves back into a single sorted array. It guarantees O(n log n) performance in all cases.
 
## Algorithm: Merge
 
Merge(arr[], left, mid, right)  
//Input: Array arr[], indices left, mid, right  
//Output: arr[left..right] merged in sorted order
 
n1 ← mid − left + 1  
n2 ← right − mid
 
CREATE arrays L[0..n1−1] and R[0..n2−1]
 
FOR i ← 0 TO n1 − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;L[i] ← arr[left + i]  
END FOR
 
FOR j ← 0 TO n2 − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;R[j] ← arr[mid + 1 + j]  
END FOR
 
i ← 0, j ← 0, k ← left
 
WHILE i < n1 AND j < n2 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF L[i] ≤ R[j] THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arr[k] ← L[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← i + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arr[k] ← R[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j ← j + 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k ← k + 1  
END WHILE
 
WHILE i < n1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arr[k] ← L[i]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i ← i + 1, k ← k + 1  
END WHILE
 
WHILE j < n2 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arr[k] ← R[j]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j ← j + 1, k ← k + 1  
END WHILE
 
## Algorithm: MergeSort
 
MergeSort(arr[], left, right)  
//Input: Array arr[], left index, right index  
//Output: arr[left..right] sorted in non-decreasing order
 
IF left < right THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mid ← left + ⌊(right − left) / 2⌋  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MergeSort(arr, left, mid)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MergeSort(arr, mid + 1, right)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Merge(arr, left, mid, right)  
END IF
 
---
 
## Time Complexity
 
| Case        | Complexity   | Explanation |
|-------------|--------------|-------------|
| **Best**    | Θ(n log n)   | Even when the array is already sorted, MergeSort still divides and merges all sub-arrays, performing the same number of operations. |
| **Average** | Θ(n log n)   | The array is divided into log n levels, and at each level the merge step does O(n) work, giving n log n overall. |
| **Worst**   | Θ(n log n)   | MergeSort always splits into equal halves regardless of input, so worst-case performance equals average-case. |
 
## Space Complexity
| Type       | Complexity | Explanation |
|------------|------------|-------------|
| **Auxiliary** | O(n)    | Temporary arrays L and R are allocated during each merge step, totalling O(n) extra space. |
 
---
---
