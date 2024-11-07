<h1 style='text-align: center;'> B. Permutation Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $a$ consisting of $n$ numbers $1$, $2$, ..., $n$ (a permutation is an array in which each element from $1$ to $n$ occurs exactly once).

You can perform the following operation: choose some subarray (contiguous subsegment) of $a$ and rearrange the elements in it in any way you want. But this operation cannot be applied to the whole array.

For example, if $a = [2, 1, 4, 5, 3]$ and we want to apply the operation to the subarray $a[2, 4]$ (the subarray containing all elements from the $2$-nd to the $4$-th), then after the operation, the array can become $a = [2, 5, 1, 4, 3]$ or, for example, $a = [2, 1, 5, 4, 3]$.

Your task is to calculate the minimum number of operations described above to sort the permutation $a$ in ascending order.

### Input

The first line contains a single integer $t$ ($1 \le t \le 2000$) — the number of test cases.

The first line of the test case contains a single integer $n$ ($3 \le n \le 50$) — the number of elements in the permutation.

The second line of the test case contains $n$ distinct integers from $1$ to $n$ — the given permutation $a$.

### Output

For each test case, output a single integer — the minimum number of operations described above to sort the array $a$ in ascending order.

## Example

### Input


```text
3
4
1 3 2 4
3
1 2 3
5
2 1 4 5 3
```
### Output


```text
1
0
2
```
## Note

In the explanations, $a[i, j]$ defines the subarray of $a$ that starts from the $i$-th element and ends with the $j$-th element.

In the first test case of the example, you can select the subarray $a[2, 3]$ and swap the elements in it.

In the second test case of the example, the permutation is already sorted, so you don't need to apply any operations.

In the third test case of the example, you can select the subarray $a[3, 5]$ and reorder the elements in it so $a$ becomes $[2, 1, 3, 4, 5]$, and then select the subarray $a[1, 2]$ and swap the elements in it, so $a$ becomes $[1, 2, 3, 4, 5]$.



#### Tags 

#900 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_109_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
