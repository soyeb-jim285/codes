<h1 style='text-align: center;'> E. Equilibrium</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/f0ff3656aaef1143f540b4194460d67725ee6732.png) William has two arrays $a$ and $b$, each consisting of $n$ items.

For some segments $l..r$ of these arrays William wants to know if it is possible to equalize the values of items in these segments using a balancing operation. Formally, the values are equalized if for each $i$ from $l$ to $r$ holds $a_i = b_i$.

To perform a balancing operation an even number of indices must be selected, such that $l \le pos_1 < pos_2 < \dots < pos_k \le r$. Next the items of array a at positions $pos_1, pos_3, pos_5, \dots$ get incremented by one and the items of array b at positions $pos_2, pos_4, pos_6, \dots$ get incremented by one.

William wants to find out if it is possible to equalize the values of elements in two arrays for each segment using some number of balancing operations, and what is the minimal number of operations required for that. 
## Note

 that for each segment the operations are performed independently.

### Input

The first line contains a two integers $n$ and $q$ ($2 \le n \le 10^5$, $1 \le q \le 10^5$), the size of arrays $a$ and $b$ and the number of segments.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ $(0 \le a_i \le 10^9)$.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ $(0 \le b_i \le 10^9)$.

Each of the next $q$ lines contains two integers $l_i$ and $r_i$ $(1 \le l_i < r_i \le n)$, the edges of segments.

### Output

For each segment output a single number — the minimal number of balancing operations needed or "-1" if it is impossible to equalize segments of arrays.

## Example

### Input


```text
8 5
0 1 2 9 3 2 7 5
2 2 1 9 4 1 5 8
2 6
1 7
2 4
7 8
5 8
```
### Output


```text
1
3
1
-1
-1
```
## Note

For the first segment from $2$ to $6$ you can do one operation with $pos = [2, 3, 5, 6]$, after this operation the arrays will be: $a = [0, 2, 2, 9, 4, 2, 7, 5]$, $b = [2, 2, 2, 9, 4, 2, 5, 8]$. Arrays are equal on a segment from $2$ to $6$ after this operation.

For the second segment from $1$ to $7$ you can do three following operations: 

1. $pos = [1, 3, 5, 6]$
2. $pos = [1, 7]$
3. $pos = [2, 7]$

After these operations, the arrays will be: $a = [2, 2, 2, 9, 4, 2, 7, 5]$, $b = [2, 2, 2, 9, 4, 2, 7, 8]$. Arrays are equal on a segment from $1$ to $7$ after these operations.

For the third segment from $2$ to $4$ you can do one operation with $pos = [2, 3]$, after the operation arrays will be: $a = [0, 2, 2, 9, 3, 2, 7, 5]$, $b = [2, 2, 2, 9, 4, 1, 5, 8]$. Arrays are equal on a segment from $2$ to $4$ after this operation.

It is impossible to equalize the fourth and the fifth segment.



#### Tags 

#2200 #NOT OK #data_structures #dp #greedy 

## Blogs
- [All Contest Problems](../Deltix_Round,_Summer_2021_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
