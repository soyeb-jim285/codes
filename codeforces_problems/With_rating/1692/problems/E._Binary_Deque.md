<h1 style='text-align: center;'> E. Binary Deque</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Slavic has an array of length $n$ consisting only of zeroes and ones. In one operation, he removes either the first or the last element of the array. 

What is the minimum number of operations Slavic has to perform such that the total sum of the array is equal to $s$ after performing all the operations? In case the sum $s$ can't be obtained after any amount of operations, you should output -1.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $s$ ($1 \leq n, s \leq 2 \cdot 10^5$) — the length of the array and the needed sum of elements.

The second line of each test case contains $n$ integers $a_i$ ($0 \leq a_i \leq 1$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum amount of operations required to have the total sum of the array equal to $s$, or -1 if obtaining an array with sum $s$ isn't possible.

## Example

### Input


```text
73 11 0 03 11 1 09 30 1 0 1 1 1 0 0 16 41 1 1 1 1 15 10 0 1 1 016 21 1 0 0 1 0 0 1 1 0 0 0 0 0 1 16 31 0 1 0 0 0
```
### Output

```text

0
1
3
2
2
7
-1

```
## Note

In the first test case, the sum of the whole array is $1$ from the beginning, so we don't have to make any operations.

In the second test case, the sum of the array is $2$ and we want it to be equal to $1$, so we should remove the first element. The array turns into $[1, 0]$, which has a sum equal to $1$.

In the third test case, the sum of the array is $5$ and we need it to be $3$. We can obtain such a sum by removing the first two elements and the last element, doing a total of three operations. The array turns into $[0, 1, 1, 1, 0, 0]$, which has a sum equal to $3$.



#### Tags 

#1200 #OK #binary_search #implementation #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_799_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
