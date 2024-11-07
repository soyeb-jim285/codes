<h1 style='text-align: center;'> F. 3SUM</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of positive integers with length $n$, determine if there exist three distinct indices $i$, $j$, $k$ such that $a_i + a_j + a_k$ ends in the digit $3$.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 2 \cdot 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^9$) — the elements of the array.

The sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

### Output

### Output

 $t$ lines, each of which contains the answer to the corresponding test case. 
### Output

 "YES" if there exist three distinct indices $i$, $j$, $k$ satisfying the constraints in the statement, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
6420 22 19 8441 11 1 202241100 1100 1100 1111512 34 56 78 9041 9 8 4616 38 94 25 18 99
```
### Output

```text

YES
YES
NO
NO
YES
YES

```
## Note

In the first test case, you can select $i=1$, $j=4$, $k=3$. Then $a_1 + a_4 + a_3 = 20 + 84 + 19 = 123$, which ends in the digit $3$.

In the second test case, you can select $i=1$, $j=2$, $k=3$. Then $a_1 + a_2 + a_3 = 1 + 11 + 1 = 13$, which ends in the digit $3$.

In the third test case, it can be proven that no such $i$, $j$, $k$ exist. 
## Note

 that $i=4$, $j=4$, $k=4$ is not a valid solution, since although $a_4 + a_4 + a_4 = 1111 + 1111 + 1111 = 3333$, which ends in the digit $3$, the indices need to be distinct.

In the fourth test case, it can be proven that no such $i$, $j$, $k$ exist.

In the fifth test case, you can select $i=4$, $j=3$, $k=1$. Then $a_4 + a_3 + a_1 = 4 + 8 + 1 = 13$, which ends in the digit $3$.

In the sixth test case, you can select $i=1$, $j=2$, $k=6$. Then $a_1 + a_2 + a_6 = 16 + 38 + 99 = 153$, which ends in the digit $3$.



#### Tags 

#1300 #OK #brute_force #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_799_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
