<h1 style='text-align: center;'> E. 2..3...4.... Wonderful! Wonderful!</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Stack has an array $a$ of length $n$ such that $a_i = i$ for all $i$ ($1 \leq i \leq n$). He will select a positive integer $k$ ($1 \leq k \leq \lfloor \frac{n-1}{2} \rfloor$) and do the following operation on $a$ any number (possibly $0$) of times.

* Select a subsequence$^\dagger$ $s$ of length $2 \cdot k + 1$ from $a$. Now, he will delete the first $k$ elements of $s$ from $a$. To keep things perfectly balanced (as all things should be), he will also delete the last $k$ elements of $s$ from $a$.

Stack wonders how many arrays $a$ can he end up with for each $k$ ($1 \leq k \leq \lfloor \frac{n-1}{2} \rfloor$). As Stack is weak at counting problems, he needs your help. 

Since the number of arrays might be too large, please print it modulo $998\,244\,353$.

$^\dagger$ A sequence $x$ is a subsequence of a sequence $y$ if $x$ can be obtained from $y$ by deleting several (possibly, zero or all) elements. For example, $[1, 3]$, $[1, 2, 3]$ and $[2, 3]$ are subsequences of $[1, 2, 3]$. On the other hand, $[3, 1]$ and $[2, 1, 3]$ are not subsequences of $[1, 2, 3]$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^3$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \leq n \leq 10^6$) — the length of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test, on a new line, print $\lfloor \frac{n-1}{2} \rfloor$ space-separated integers — the $i$-th integer representing the number of arrays modulo $998\,244\,353$ that Stack can get if he selects $k=i$.

## Example

### Input


```text
434510
```
### Output

```text

2 
4 
10 2 
487 162 85 10 

```
## Note

In the first test case, two $a$ are possible for $k=1$: 

* $[1,2,3]$;
* $[2]$.

In the second test case, four $a$ are possible for $k=1$: 

* $[1,2,3,4]$;
* $[1,3]$;
* $[2,3]$;
* $[2,4]$.

In the third test case, two $a$ are possible for $k=2$: 

* $[1,2,3,4,5]$;
* $[3]$.


#### Tags 

#2400 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../think-cell_Round_1.md)
- [think-cell Round 1 (en)](../blogs/think-cell_Round_1_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
