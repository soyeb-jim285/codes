<h1 style='text-align: center;'> C. Division by Two and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ positive integers. You can perform operations on it.

In one operation you can replace any element of the array $a_i$ with $\lfloor \frac{a_i}{2} \rfloor$, that is, by an integer part of dividing $a_i$ by $2$ (rounding down).

See if you can apply the operation some number of times (possible $0$) to make the array $a$ become a permutation of numbers from $1$ to $n$ —that is, so that it contains all numbers from $1$ to $n$, each exactly once.

For example, if $a = [1, 8, 25, 2]$, $n = 4$, then the answer is yes. You could do the following:

1. Replace $8$ with $\lfloor \frac{8}{2} \rfloor = 4$, then $a = [1, 4, 25, 2]$.
2. Replace $25$ with $\lfloor \frac{25}{2} \rfloor = 12$, then $a = [1, 4, 12, 2]$.
3. Replace $12$ with $\lfloor \frac{12}{2} \rfloor = 6$, then $a = [1, 4, 6, 2]$.
4. Replace $6$ with $\lfloor \frac{6}{2} \rfloor = 3$, then $a = [1, 4, 3, 2]$.
### Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^4$) —the number of test cases.

Each test case contains exactly two lines. The first one contains an integer $n$ ($1 \le n \le 50$), the second one contains integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

### Output

For each test case, output on a separate line:

* YES if you can make the array $a$ become a permutation of numbers from $1$ to $n$,
* NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

## Example

### Input


```text
641 8 25 221 199 8 3 4 2 7 1 5 638 2 1424 7 16 7522 6 22 4 22
```
### Output

```text

YES
NO
YES
NO
NO
YES

```
## Note

The first test case is explained in the text of the problem statement.

In the second test case, it is not possible to get a permutation.



#### Tags 

#1100 #OK #constructive_algorithms #flows #graph_matchings #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_764_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
