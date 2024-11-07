<h1 style='text-align: center;'> B. Plus-Minus Split</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$ consisting of characters "+" and "-". $s$ represents an array $a$ of length $n$ defined by $a_i=1$ if $s_i=$ "+" and $a_i=-1$ if $s_i=$ "-".

You will do the following process to calculate your penalty: 

1. Split $a$ into non-empty arrays $b_1,b_2,\ldots,b_k$ such that $b_1+b_2+\ldots+b_k=a^\dagger$, where $+$ denotes array concatenation.
2. The penalty of a single array is the absolute value of its sum multiplied by its length. In other words, for some array $c$ of length $m$, its penalty is calculated as $p(c)=|c_1+c_2+\ldots+c_m| \cdot m$.
3. The total penalty that you will receive is $p(b_1)+p(b_2)+\ldots+p(b_k)$.

If you perform the above process optimally, find the minimum possible penalty you will receive.

$^\dagger$ Some valid ways to split $a=[3,1,4,1,5]$ into $(b_1,b_2,\ldots,b_k)$ are $([3],[1],[4],[1],[5])$, $([3,1],[4,1,5])$ and $([3,1,4,1,5])$ while some invalid ways to split $a$ are $([3,1],[1,5])$, $([3],[\,],[1,4],[1,5])$ and $([3,4],[5,1,1])$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5000$) — the length of string $s$.

The second line of each test case contains string $s$ ($s_i \in \{ \mathtt{+}, \mathtt{-} \}$, $|s| = n$).

## Note

 that there are no constraints on the sum of $n$ over all test cases.

### Output

For each test case, output a single integer representing the minimum possible penalty you will receive.

## Example

### Input


```text
51+5-----6+-+-+-10--+++++++-20+---++++-+++++---++-
```
### Output

```text

1
5
0
4
4

```
## Note

In the first test case, we have $a=[1]$. We can split array $a$ into $([1])$. Then, the sum of penalties of the subarrays is $p([1]) = 1$.

In the second test case, we have $a=[-1,-1,-1,-1,-1]$. We can split array $a$ into $([-1],[-1],[-1],[-1],[-1])$. Then, the sum of penalties of the subarrays is $p([-1]) + p([-1]) + p([-1]) + p([-1]) + p([-1]) = 1 + 1 + 1 + 1 + 1 = 5$.

In the third test case, we have $a=[1,-1,1,-1,1,-1]$. We can split array $a$ into $([1,-1,1,-1],[1,-1])$. Then, the sum of penalties of the subarrays is $p([1,-1,1,-1]) + p([1,-1]) = 0 + 0 = 0$.



#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Hello_2024.md)
- [Hello 2024 (en)](../blogs/Hello_2024_(en).md)
- [Editorial for Hello 2024 (en)](../blogs/Editorial_for_Hello_2024_(en).md)
