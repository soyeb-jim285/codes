<h1 style='text-align: center;'> C. Least Prefix Sum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Baltic, a famous chess player who is also a mathematician, has an array $a_1,a_2, \ldots, a_n$, and he can perform the following operation several (possibly $0$) times:

* Choose some index $i$ ($1 \leq i \leq n$);
* multiply $a_i$ with $-1$, that is, set $a_i := -a_i$.

Baltic's favorite number is $m$, and he wants $a_1 + a_2 + \cdots + a_m$ to be the smallest of all non-empty prefix sums. More formally, for each $k = 1,2,\ldots, n$ it should hold that $$a_1 + a_2 + \cdots + a_k \geq a_1 + a_2 + \cdots + a_m.$$

Please note that multiple smallest prefix sums may exist and that it is only required that $a_1 + a_2 + \cdots + a_m$ is one of them.

Help Baltic find the minimum number of operations required to make $a_1 + a_2 + \cdots + a_m$ the least of all prefix sums. It can be shown that a valid sequence of operations always exists.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10\,000$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq m \leq n \leq 2\cdot 10^5$) — the size of Baltic's array and his favorite number.

The second line contains $n$ integers $a_1,a_2, \ldots, a_n$ ($-10^9 \leq a_i \leq 10^9$) — the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, print a single integer — the minimum number of required operations.

## Example

### Input


```text
64 3-1 -2 -3 -44 31 2 3 41 115 5-2 3 -5 1 -205 2-2 3 -5 -5 -2010 4345875723 -48 384678321 -375635768 -35867853 -35863586 -358683842 -81725678 38576 -357865873
```
### Output

```text

1
1
0
0
3
4

```
## Note

In the first example, we perform the operation $a_4 := -a_4$. The array becomes $[-1,-2,-3,4]$ and the prefix sums, $[a_1, \ a_1+a_2, \ a_1+a_2+a_3, \ a_1+a_2+a_3+a_4]$, are equal to $[-1,-3,-6,-2]$. Thus $a_1 + a_2 + a_3=-6$ is the smallest of all prefix sums.

In the second example, we perform the operation $a_3 := -a_3$. The array becomes $[1,2,-3,4]$ with prefix sums equal to $[1,3,0,4]$.

In the third and fourth examples, $a_1 + a_2 + \cdots + a_m$ is already the smallest of the prefix sums — no operation needs to be performed.

In the fifth example, a valid sequence of operations is:

* $a_3 := -a_3$,
* $a_2 := -a_2$,
* $a_5 := -a_5$.

The array becomes $[-2,-3,5,-5,20]$ and its prefix sums are $[-2,-5,0,-5,15]$. 
## Note

 that $a_1+a_2=-5$ and $a_1+a_2+a_3+a_4=-5$ are both the smallest of the prefix sums (and this is a valid solution).



#### Tags 

#1600 #NOT OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Hello_2023.md)
- [Hello 2023 (en)](../blogs/Hello_2023_(en).md)
- [Editorial for Hello 2023 (en)](../blogs/Editorial_for_Hello_2023_(en).md)
