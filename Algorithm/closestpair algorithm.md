# Closest Pair of Points

## Description
Closest Pair of Points finds the two points in a set of n 2D points that are nearest to each other. The brute-force approach checks every unique pair of points, computes the Euclidean distance between them, and tracks the pair with the smallest distance found so far.

---

## Algorithm: ClosestPair

ClosestPair(arr[0..n-1][2])  
//Input: Array arr of n points, each with integer coordinates (x, y)  
//Output: The closest pair of points and their Euclidean distance

d ← 99999  
res[0] ← (0, 0)  
res[1] ← (0, 0)

FOR i ← 0 TO n − 2 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR j ← i + 1 TO n − 1 DO  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x1 ← arr[i][0]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;y1 ← arr[i][1]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;x2 ← arr[j][0]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;y2 ← arr[j][1]  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dx ← x2 − x1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dy ← y2 − y1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;d1 ← √(dx² + dy²)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF d1 < d THEN  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;d ← d1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;res[0] ← (arr[i][0], arr[i][1])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;res[1] ← (arr[j][0], arr[j][1])  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END FOR  
END FOR

r ← round(d × 1000)  
ip ← r / 1000  
frac ← r mod 1000  
IF frac < 0 THEN frac ← −frac

Return res[0], res[1], ip, frac

---

## Time Complexity

| Case        | Complexity | Explanation |
|-------------|------------|-------------|
| **Best**    | Θ(n²)      | No early exit exists — the nested loop always runs all n(n−1)/2 iterations even if the closest pair is found on the very first comparison. |
| **Average** | Θ(n²)      | For any arrangement of input points, every unique pair (i, j) where j > i is evaluated unconditionally. |
| **Worst**   | Θ(n²)      | Total comparisons are exactly n(n−1)/2, which is Θ(n²), regardless of the spatial distribution of points. |

## Space Complexity

| Type          | Complexity | Explanation |
|---------------|------------|-------------|
| **Input**     | O(n)       | An n × 2 integer array stores the coordinates of all n input points. |
| **Auxiliary** | O(1)       | Only a fixed set of scalar variables are used: d, d1, dx, dy, x1, y1, x2, y2, r, ip, frac, res[2][2] — none scale with n. |
