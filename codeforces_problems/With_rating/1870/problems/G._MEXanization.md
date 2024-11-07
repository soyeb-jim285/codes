<h1 style='text-align: center;'> G. MEXanization</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's define $f(S)$. Let $S$ be a multiset (i.e., it can contain repeated elements) of non-negative integers. In one operation, you can choose any non-empty subset of $S$ (which can also contain repeated elements), remove this subset (all elements in it) from $S$, and add the MEX of the removed subset to $S$. You can perform any number of such operations. After all the operations, $S$ should contain exactly $1$ number. $f(S)$ is the largest number that could remain in $S$ after any sequence of operations.

You are given an array of non-negative integers $a$ of length $n$. For each of its $n$ prefixes, calculate $f(S)$ if $S$ is the corresponding prefix (for the $i$-th prefix, $S$ consists of the first $i$ elements of array $a$).

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance: 

* The MEX of $[2,2,1]$ is $0$, because $0$ does not belong to the array.
* The MEX of $[3,1,0,1]$ is $2$, because $0$ and $1$ belong to the array, but $2$ does not.
* The MEX of $[0,3,1,2]$ is $4$, because $0$, $1$, $2$ and $3$ belong to the array, but $4$ does not.
### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the size of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 2 \cdot 10^5$) — the array $a$.

It is guaranteed that the sum of all $n$ values across all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ numbers: $f(S)$ for each of the $n$ prefixes of array $a$.

## Example

### Input


```text
48179 57 2 0 2 3 2 31031 0 381 0 1 2 4 3 0 2
```
### Output

```text

179 2 3 3 3 4 4 5 
1 
1 2 2 
1 2 2 3 3 5 5 5 

```
## Note

Consider the first test case. For a prefix of length $1$, the initial multiset is $\{179\}$. If we do nothing, we get $179$.

For a prefix of length $2$, the initial multiset is $\{57, 179\}$. Using the following sequence of operations, we can obtain $2$. 

1. Apply the operation to $\{57\}$, the multiset becomes $\{0, 179\}$.
2. Apply the operation to $\{179\}$, the multiset becomes $\{0, 0\}$.
3. Apply the operation to $\{0\}$, the multiset becomes $\{0, 1\}$.
4. Apply the operation to $\{0, 1\}$, the multiset becomes $\{2\}$. This is our answer.

Consider the second test case. For a prefix of length $1$, the initial multiset is $\{0\}$. If we apply the operation to $\{0\}$, the multiset becomes $\{1\}$. This is the answer.



#### Tags 

#3300 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../CodeTON_Round_6_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
