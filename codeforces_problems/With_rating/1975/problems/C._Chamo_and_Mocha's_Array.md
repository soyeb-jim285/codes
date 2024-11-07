<h1 style='text-align: center;'> C. Chamo and Mocha's Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mocha likes arrays, so before her departure, Chamo gave her an array $a$ consisting of $n$ positive integers as a gift.

Mocha doesn't like arrays containing different numbers, so Mocha decides to use magic to change the array. Mocha can perform the following three-step operation some (possibly, zero) times: 

1. Choose indices $l$ and $r$ ($1 \leq l < r \leq n$)
2. Let $x$ be the median$^\dagger$ of the subarray $[a_l, a_{l+1},\ldots, a_r]$
3. Set all values $a_l, a_{l+1},\ldots, a_r$ to $x$

Suppose $a=[1,2,3,4,5]$ initially: 

* If Mocha chooses $(l,r)=(3,4)$ in the first operation, then $x=3$, the array will be changed into $a=[1,2,3,3,5]$.
* If Mocha chooses $(l,r)=(1,3)$ in the first operation, then $x=2$, the array will be changed into $a=[2,2,2,4,5]$.

Mocha will perform the operation until the array contains only the same number. Mocha wants to know what is the maximum possible value of this number.

$^\dagger$ The median in an array $b$ of length $m$ is an element that occupies position number $\lfloor \frac{m+1}{2} \rfloor$ after we sort the elements in non-decreasing order. For example, the median of $[3,1,4,1,5]$ is $3$ and the median of $[5,25,20,24]$ is $20$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\leq t\leq 500$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2\leq n\leq 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i \leq 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output the maximum value of the number.

## Example

### Input


```text
221 251 2 3 4 5
```
### Output

```text

1
4

```
## Note

In the first test case, $a=[1,2]$. Mocha can only choose the interval $(l,r)=(1,2)$. The array will be changed to $a=[1,1]$. Therefore, the answer is $1$.

In the second test case, Mocha can perform the following operations:

* Choose the interval $(l,r)=(4,5)$, then $a=[1,2,3,4,4]$.
* Choose the interval $(l,r)=(3,5)$, then $a=[1,2,4,4,4]$.
* Choose the interval $(l,r)=(1,5)$, then $a=[4,4,4,4,4]$.

The array contains only the same number, which is $4$. It can be proven that the maximum value of the final number cannot be greater than $4$.



#### Tags 

#1200 #OK #binary_search #brute_force #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_947_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
