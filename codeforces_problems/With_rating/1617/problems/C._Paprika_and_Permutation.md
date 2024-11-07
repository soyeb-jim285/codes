<h1 style='text-align: center;'> C. Paprika and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Paprika loves permutations. She has an array $a_1, a_2, \dots, a_n$. She wants to make the array a permutation of integers $1$ to $n$.

In order to achieve this goal, she can perform operations on the array. In each operation she can choose two integers $i$ ($1 \le i \le n$) and $x$ ($x > 0$), then perform $a_i := a_i \bmod x$ (that is, replace $a_i$ by the remainder of $a_i$ divided by $x$). In different operations, the chosen $i$ and $x$ can be different.

Determine the minimum number of operations needed to make the array a permutation of integers $1$ to $n$. If it is impossible, output $-1$.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$. ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the minimum number of operations needed to make the array a permutation of integers $1$ to $n$, or $-1$ if it is impossible.

## Example

### Input


```text
4
2
1 7
3
1 5 4
4
12345678 87654321 20211218 23571113
9
1 2 3 4 18 19 5 6 7
```
### Output


```text
1
-1
4
2
```
## Note

For the first test, the only possible sequence of operations which minimizes the number of operations is: 

* Choose $i=2$, $x=5$. Perform $a_2 := a_2 \bmod 5 = 2$.

For the second test, it is impossible to obtain a permutation of integers from $1$ to $n$.



#### Tags 

#1300 #NOT OK #binary_search #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_761_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
