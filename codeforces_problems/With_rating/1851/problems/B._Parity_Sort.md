<h1 style='text-align: center;'> B. Parity Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of integers $a$ of length $n$. You can apply the following operation to the given array: 

* Swap two elements $a_i$ and $a_j$ such that $i \neq j$, $a_i$ and $a_j$ are either both even or both odd.

 Determine whether it is possible to sort the array in non-decreasing order by performing the operation any number of times (possibly zero).

For example, let $a$ = [$7, 10, 1, 3, 2$]. Then we can perform $3$ operations to sort the array: 

1. Swap $a_3 = 1$ and $a_1 = 7$, since $1$ and $7$ are odd. We get $a$ = [$1, 10, 7, 3, 2$];
2. Swap $a_2 = 10$ and $a_5 = 2$, since $10$ and $2$ are even. We get $a$ = [$1, 2, 7, 3, 10$];
3. Swap $a_4 = 3$ and $a_3 = 7$, since $3$ and $7$ are odd. We get $a$ = [$1, 2, 3, 7, 10$].
### Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of array $a$.

The second line of each test case contains exactly $n$ positive integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output on a separate line: 

* YES if the array can be sorted by applying the operation to it some number of times;
* NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as positive response).

## Example

### Input


```text
657 10 1 3 2411 9 3 5511 3 15 3 2610 7 8 1 2 311056 6 4 1 6
```
### Output

```text

YES
YES
NO
NO
YES
NO
```
## Note

The first test case is explained in the problem statement.



#### Tags 

#800 #OK #greedy #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_888_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
